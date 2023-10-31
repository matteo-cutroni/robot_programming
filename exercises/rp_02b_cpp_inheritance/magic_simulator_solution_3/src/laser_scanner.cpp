#include "laser_scanner.h"

LaserScanner::LaserScanner(LaserScan& scn, WorldItem& par, const Isometry2& pos)
    : WorldItem(par, pos), scan(scn) {}

void LaserScanner::draw(Canvas& canvas, bool show_parent) const {
  scan.draw(canvas, *grid_map, globalPose());
}

void LaserScanner::getScan() {
  Isometry2 gp = globalPose();
  Isometry2 rotation = gp;
  rotation.translation = {0, 0};
  Scalar angle_increment = (scan.angle_max - scan.angle_min) / scan.ranges_num;

  for (int i = 0; i < scan.ranges_num; ++i) {
    Scalar beam_angle = scan.angle_min + angle_increment * i;
    Vec2 d = {cos(beam_angle), sin(beam_angle)};
    d = rotation * d;
    scan.ranges[i] = grid_map->scanRay(gp.translation, d, scan.range_max);
  }
}