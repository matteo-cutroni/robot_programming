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

// adjust the check_collision() method so that
// only for objects whose parent is the root of the tree
// we check a collision against the map (using TODO 5)
// AND a collision between *this and all his siblings (using TODO 6)
bool WorldItem::checkCollision() const {
  Isometry2 pose = globalPose();
  int radius_px = radius * grid_map->inv_resolution;
  int r2 = radius_px * radius_px;

  Vec2i origin_px = grid_map->world2grid(pose.translation);

  for (int r = -radius_px; r <= radius_px; ++r) {
    for (int c = -radius_px; c <= radius_px; ++c) {
      if (r * r + c * c > r2) continue;
      Vec2i offset = {c, r};
      Vec2i p_px = origin_px + offset;

      if (!grid_map->inside(p_px)) return true;

      if (grid_map->at(p_px) < 127) return true;
    }
  }

  for (int i = 0; i < num_children; ++i) {
    if (children[i]->checkCollision() == true) return true;
  }

  if (parent && !parent->parent) {
    for (int i = 0; i < parent->num_children; ++i) {
      if (parent->children[i] == this) continue;
      if (checkCollision(*parent->children[i])) return true;
    }
  }

  return false;
}

bool WorldItem::checkCollision(const WorldItem& other) const {
  if (isAncestor(other)) return false;

  Vec2 origin = globalPose().translation;
  Vec2 other_origin = other.globalPose().translation;

  float dx = origin[0] - other_origin[0];
  float dy = origin[1] - other_origin[1];
  float distance = sqrt(dx * dx + dy * dy);

  if (distance < (radius + other.radius)) return true;
  for (int i = 0; i < num_children; ++i) {
    if (children[i]->checkCollision(other)) return true;
  }

  return false;
}

void WorldItem::tick(float time_interval) {}

void World::draw(Canvas& canvas, bool show_parent) const {
  Vec2 x_axis = {1, 0};
  Vec2 y_axis = {0, 1};

  Vec2i origin = grid_map->world2grid(globalPose().translation);
  Vec2i x_axis_on_frame = grid_map->world2grid(globalPose() * x_axis);
  Vec2i y_axis_on_frame = grid_map->world2grid(globalPose() * y_axis);

  drawLine(canvas, origin, x_axis_on_frame, 200);
  drawLine(canvas, origin, y_axis_on_frame, 200);
}
