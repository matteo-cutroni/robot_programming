#pragma once
#include "laser_scan.h"
#include "world_item.h"

struct LaserScanner : public WorldItem {
  LaserScan& scan;
  Scalar period = 0;  // 1 / frequency;
  Scalar counter = 0;
  bool scan_ready = false;

  LaserScanner(LaserScan& scn, WorldItem& par, const Isometry2& pos,
               Scalar frequency);

  void draw(Canvas& canvas, bool show_parent) const;

  void tick(float dt) override;

  void getScan();
};