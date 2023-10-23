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

bool GridMap::scanRay(Vec2& hit, const Vec2& origin, const Vec2& direction, const Scalar max_range) {
  Scalar range=0;
  cerr << "range: " << range << " max_range: " << max_range <<endl;
  while (range<max_range) {
    hit = origin + direction*range;
    Vec2i int_endpoint=world2grid(hit);
    cerr << "ep: " << int_endpoint << endl;
    range+=resolution;
    if (!inside(int_endpoint))
      return false;
    uint8_t val=at(int_endpoint[1], int_endpoint[0]);
    // cerr << "range: " << range << " ep: " << hit[0] << " " << hit[1]
    //      << " iep: " << int_endpoint[0] << " " << int_endpoint[1] << " " << (int) val << endl; 
    if (val < 127) {
      return true;
    }
  }
  return false;
}

void GridMap::loadFromImage(const char *filename, Scalar res){
  resolution=res;
  inv_resolution=1./res;
  cerr << "loading [" << filename << "]" << endl;
  cv::Mat m=cv::imread(filename);
  if (m.rows==0) {
    throw std::runtime_error("unable to load image");
  }
  cv::Mat loaded_image;
  cv::cvtColor(m, loaded_image, cv::COLOR_BGR2GRAY);
  int size=loaded_image.rows*loaded_image.cols;
  values=new uint8_t[loaded_image.rows*loaded_image.cols];
  rows=loaded_image.rows;
  cols=loaded_image.cols;
  origin[0]=cols/2;
  origin[1]=rows/2;
  
  memcpy(values, loaded_image.data, size);
}

void GridMap::draw(Canvas& dest) {
  dest=cv::Mat(rows, cols, CV_8UC1);
  memcpy(dest.data, values, rows*cols);
}

void drawLine(Canvas& dest, const Vec2i& p0, const Vec2i& p1, uint8_t color) {
  cv::line(dest, cv::Point(p0[0], p0[1]), cv::Point(p1[0], p1[1]), cv::Scalar(color, color, color), 1);
}

int showCanvas(Canvas& canvas, int timeout_ms) {
  cv::imshow("canvas", canvas);
  int key=cv::waitKey(timeout_ms);
  if (key==27) // exit on ESC
    exit(0);
  //cerr << "key" << key << endl;
  return  key;
}
