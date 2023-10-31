#pragma once
#include "laser_scan.h"
#include "world_item.h"

struct LaserScanner : public WorldItem {
  LaserScan& scan;

  LaserScanner(LaserScan& scn, WorldItem& par, const Isometry2& pos);

  void draw(Canvas& canvas, bool show_parent) const;

  void getScan();
};