#include "world_item.h"
#include <iostream>

using namespace std;
Isometry2 WorldItem::globalPose() const {
  if (!parent) return pose_in_parent;
  return parent->globalPose() * pose_in_parent;
}


const GridMap& WorldItem::gridMap() const {
  if (grid_map) return *grid_map;

  WorldItem* p = parent;
  if (p) {
    while (p->parent) {
      if (p->grid_map) return (*p->grid_map);
      p = p->parent;
    }
  }

  throw std::runtime_error("No GridMap available in this branch");
  return *grid_map;
}

void WorldItem::draw(Canvas& canvas, bool show_parent) const {
  Vec2i center = grid_map->world2grid(globalPose().translation);
  int radius_px = radius * grid_map->inv_resolution;
  drawCircle(canvas, center, radius_px, 0);

  Vec2 x_in_item = {radius, 0};
  Vec2 x_in_world = globalPose() * x_in_item;
  Vec2i x_in_grid = grid_map->world2grid(x_in_world);
  drawLine(canvas, center, x_in_grid, 0);

  if (show_parent == true && parent != nullptr) {
    Vec2i parent_in_grid =
      grid_map->world2grid(parent->globalPose().translation);
    drawLine(canvas, center, parent_in_grid, 100);
  }
}

bool WorldItem:: checkCollision() const  {
  Isometry2 pose= globalPose();
  int radius_px=radius * grid_map->inv_resolution;
  int r2=radius_px*radius_px;
  
  Vec2i origin_px=grid_map->world2grid(pose.translation);

  for (int r=-radius_px; r<=radius_px; ++r) {
    for (int c=-radius_px; c<=radius_px; ++c){
      if (r*r+c*c>r2)
        continue;
      Vec2i offset = {c,r};
      Vec2i p_px = origin_px + offset;

      if (! grid_map->inside(p_px))
        return true;

      if (grid_map->at(p_px)<127)
        return true;
    }
  }
  return false;
}

void WorldItem::tick(float time_interval){
}
