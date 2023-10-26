#pragma once
#include "grid_map.h"
#include "isometry_2.h"

class WorldItem {
public:
  Isometry2 pose_in_parent;
  WorldItem* parent;
  const GridMap* grid_map = 0;
  Scalar radius = 1;
protected:
  WorldItem(const GridMap* g, WorldItem* p, const Isometry2& iso=Isometry2::Identity()) :
    grid_map(g),
    parent(p),
    pose_in_parent(iso){}

public:
  WorldItem(const GridMap& g):
    WorldItem(&g, 0)
  {}

  WorldItem(WorldItem& p, const Isometry2& iso=Isometry2::Identity()):
    WorldItem(p.grid_map, &p, iso)
  {}
  
  Isometry2 globalPose() const;

  const GridMap& gridMap() const;

  bool checkCollision() const;

  inline bool move(const Isometry2& iso) {
    Isometry2 restored_pose_in_parent=pose_in_parent;
    pose_in_parent = pose_in_parent * iso;
    if (checkCollision()) {
      pose_in_parent=restored_pose_in_parent;
      return false;
    }
    return true;
  }
            
  void draw(Canvas& canvas, bool show_parent) const;

  
};
