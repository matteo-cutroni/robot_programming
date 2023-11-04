#include "laser_scan.h"

LaserScan::LaserScan(Scalar range_min, Scalar range_max, Scalar angle_min,
                     Scalar angle_max, int ranges_num) {
  this->range_min = range_min;
  this->range_max = range_max;
  this->angle_min = angle_min;
  this->angle_max = angle_max;
  this->ranges_num = ranges_num;

  ranges = new Scalar[ranges_num];
  for (int i = 0; i < ranges_num; ++i) ranges[i] = range_max;
}

LaserScan::~LaserScan() { delete[] ranges; }

void LaserScan::draw(Canvas& canevasso, const GridMap& grid_map,
                     const Isometry2& pose) {
  Vec2i center_px = grid_map.world2grid(pose.translation);
  Scalar angle_increment = (angle_max - angle_min) / ranges_num;
  Isometry2 rotation = pose;
  rotation.translation.setZero();

  for (int i = 0; i < ranges_num; ++i) {
    Scalar beam_angle = angle_min + angle_increment * i;
    Vec2 d = {cos(beam_angle), sin(beam_angle)};
    d = rotation * d;
    Vec2 ep = pose.translation + d * ranges[i];
    Vec2i ep_px = grid_map.world2grid(ep);
    drawLine(canevasso, center_px, ep_px, 90);
  }
}