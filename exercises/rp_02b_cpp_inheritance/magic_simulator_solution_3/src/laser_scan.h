#pragma once

#include "grid_map.h"
#include "isometry_2.h"
#include "precision.h"

struct LaserScan {
  Scalar range_min = 0.1, range_max = 10, angle_min = -M_PI / 2,
         angle_max = M_PI / 2;
  int ranges_num = 0;
  Scalar* ranges = nullptr;

  LaserScan(Scalar range_min = 0.1, Scalar range_max = 10,
            Scalar angle_min = -M_PI / 2, Scalar angle_max = M_PI / 2,
            int ranges_num = 180);

  ~LaserScan();

  void draw(Canvas& canevasso, const GridMap& grid_map, const Isometry2& pose);
};