#pragma once
#include "grid_map.h"
#include "isometry_2.h"

// TODO 2: add to a WorldItem a null terminated array
// containing the list of its children
// Each time a world item is constructed, if it has a parent
// its pointer should end up in the children array of the parent.

class WorldItem {
public:
  static constexpr int CHILDREN_MAX_NUM = 10;
  Isometry2 pose_in_parent;
  WorldItem* parent;
  const GridMap* grid_map = 0;
  Scalar radius = 1;
  WorldItem * children[CHILDREN_MAX_NUM];
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

  //TODO 3: write a method "isAncestor(const WorldItem& other)
  //        that returns true if other is an ancestor of this
  
  // TODO 4:  rewrite the checkCollision for an object
  // so that it returns true if either an object collides
  // OR one of its descendants collides with the map

  // TODO 5:  add another checkCollision2(const WorldItem& other)
  // that returns true if this (or one of its descendants
  // collides with other (or one of its descendants)
  
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
            
  virtual void draw(Canvas& canvas, bool show_parent) const;
  
  virtual void tick(float time_interval);
};
