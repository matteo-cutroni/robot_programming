#pragma once
#include "grid_map.h"
#include "isometry_2.h"

//TODO 3:
// in the following class blast the chidren array and replace it with a set of pointers to WorldItem.  (pointers admit the < operator)

//TODO 4:
// edit the destructor of a world item so that, if the destroyed instance
// has a parent, its pointer disappears from the parent children's list

//TODO 5 [hard]:
// implement a tricycle like kinematics on the robot
// origin in the middle of the back wheels
//
// Traction drive parameters:
// - baseline between the back wheels and the front wheel

// Traction drive controls:
// - angle of the steering wheel (alpha)
// - velocity of the steering wheel (v)

// Traction drive incremental motion,
// T: time interval
// dth = v*T*sin(alpha)/baseline 
// dx  = v*T*sin(dth)/dth
// dy  = v*T*(1-cos(dth))/dth
//
// 1st order approx:
// dth = v*T*sin(alpha)/baseline 
// dx  = v*T
// dy  = 0

// upon instantiation the Bicycle casts another chidren object
// which is located at position [baseline, 0, 0] w.r.t
// the local origin
// this object represents the front wheel.
// @simone (look at repo srrg2_ems_robot/kinematic_model_traction_drive)
// this is a "forklift" model: one active wheel in front that does all the work
// and two passive admin wheels in the back

class WorldItem {
 public:

  static constexpr int CHILDREN_MAX_NUM = 10;
  Isometry2 pose_in_parent;
  WorldItem* parent;
  const GridMap* grid_map = 0;
  Scalar radius = 1;
  WorldItem* children[CHILDREN_MAX_NUM + 1];
  int num_children = 0;

 protected:
  WorldItem(const GridMap* g, WorldItem* p,
            const Isometry2& iso = Isometry2::Identity())
      : grid_map(g), parent(p), pose_in_parent(iso) {
    memset(children, 0, sizeof(WorldItem*) * (CHILDREN_MAX_NUM + 1));

    if (parent) {
      parent->children[parent->num_children] = this;
      parent->num_children++;
    }
  }

 public:
  WorldItem(const GridMap& g) : WorldItem(&g, 0) {}

  WorldItem(WorldItem& p, const Isometry2& iso = Isometry2::Identity())
      : WorldItem(p.grid_map, &p, iso) {}

  Isometry2 globalPose() const;

  const GridMap& gridMap() const;

  inline bool isAncestor(const WorldItem& other) const {
    if (!parent) return false;
    if (parent == &other) return true;
    return parent->isAncestor(other);
  }


  bool checkCollision() const;
  bool checkCollision(const WorldItem& other) const;

  inline bool move(const Isometry2& iso) {
    Isometry2 restored_pose_in_parent = pose_in_parent;
    pose_in_parent = pose_in_parent * iso;
    if (checkCollision()) {
      pose_in_parent = restored_pose_in_parent;
      return false;
    }
    return true;
  }

  virtual void draw(Canvas& canvas, bool show_parent) const;

  virtual void tick(float time_interval);
};

class World : public WorldItem {
 public:
  World(const GridMap& g) : WorldItem(g) {}

  void draw(Canvas& canvas, bool show_parent) const override;
};

class UnicyclePlatform : public WorldItem {
 public:
  Scalar tvel = 0, rvel = 0;
  UnicyclePlatform(WorldItem& p, const Isometry2& iso = Isometry2::Identity())
      : WorldItem(p.grid_map, &p, iso) {}

  inline void tick(float time_interval) override {
    Isometry2 delta_state(tvel * time_interval, 0, rvel * time_interval);
    move(delta_state);
  }
};
