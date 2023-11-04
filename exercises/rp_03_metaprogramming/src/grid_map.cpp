#include "grid_map.h"
using namespace std;

GridMap::GridMap(int rows_, int cols_, Scalar resolution_) {
  values = new uint8_t[rows_ * cols_];
  rows = rows_;
  cols = cols_;
  resolution = resolution_;
  inv_resolution = 1.0 / resolution;
  origin = Vec2i({rows_ / 2, cols_ / 2});
}

GridMap::~GridMap() { delete[] values; }

bool GridMap::scanRay(Vec2& hit,
                      const Vec2& origin,
                      const Vec2& direction,
                      const Scalar max_range) const{
  Scalar range = 0;
  while (range < max_range) {
    hit = origin + direction * range;
    Vec2i int_endpoint = world2grid(hit);
    range += resolution;
    if (!inside(int_endpoint)) return false;
    uint8_t val = at(int_endpoint);
    if (val < 127) {
      return true;
    }
  }
  return false;
}

Scalar GridMap::scanRay(const Vec2& origin,
                        const Vec2& direction,
                        const Scalar max_range) const {
  Scalar range = 0;

  while (range < max_range) {
    Vec2i int_endpoint=world2grid(origin + direction * range);
    
    if (!inside(int_endpoint))
      return max_range;

    if (at(int_endpoint) < 127)
      return range;

    range +=resolution;
  }
  
  return max_range;
}

void GridMap::loadFromImage(const char* filename, Scalar res) {
  resolution = res;
  inv_resolution = 1. / res;
  cerr << "loading [" << filename << "]" << endl;
  cv::Mat m = cv::imread(filename);
  if (m.rows == 0) {
    throw std::runtime_error("unable to load image");
  }
  cv::Mat loaded_image;
  cv::cvtColor(m, loaded_image, cv::COLOR_BGR2GRAY);
  int size = loaded_image.rows * loaded_image.cols;
  values = new uint8_t[loaded_image.rows * loaded_image.cols];
  rows = loaded_image.rows;
  cols = loaded_image.cols;
  origin[0] = cols / 2;
  origin[1] = rows / 2;

  memcpy(values, loaded_image.data, size);
}

void GridMap::draw(Canvas& dest) {
  dest = cv::Mat(rows, cols, CV_8UC1);
  memcpy(dest.data, values, rows * cols);
}
