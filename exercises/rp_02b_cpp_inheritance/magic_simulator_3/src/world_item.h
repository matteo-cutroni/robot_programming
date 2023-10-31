#pragma once
#include "grid_map.h"
#include "isometry_2.h"

// TODO 2:
// add another class derived from WorldItem, that represents the World
// frame.
// Override the draw method so that it draws the x and  the y axes on the map.
// Once done change the type of the variable world_object in test_stuff
// to the new type (World);

class WorldItem {
public:
// TODO 3: add to a WorldItem a null terminated array
// containing the pointers to its children
// Each time a world item is constructed, if it has a parent
// its pointer should end up in the children array of the parent.

  static constexpr int CHILDREN_MAX_NUM = 10;
  Isometry2 pose_in_parent;
  WorldItem* parent;
  const GridMap* grid_map = 0;
  Scalar radius = 1;
  WorldItem * children[CHILDREN_MAX_NUM+1];
  int num_children = 0;

protected:
  WorldItem(const GridMap* g, WorldItem* p, const Isometry2& iso=Isometry2::Identity()) :
    grid_map(g),
    parent(p),
    pose_in_parent(iso){
    memset(children, 0, sizeof(WorldItem*)*(CHILDREN_MAX_NUM+1));
  }

public:
  WorldItem(const GridMap& g):
    WorldItem(&g, 0)
  {}

  WorldItem(WorldItem& p, const Isometry2& iso=Isometry2::Identity()):
    WorldItem(p.grid_map, &p, iso)
  {}
  
  Isometry2 globalPose() const;

  const GridMap& gridMap() const;

  
  //TODO 4:
  // write a method "isAncestor(const WorldItem& other)
  // hat returns true if other is an ancestor of this
  
  // TODO 5:
  // rewrite the checkCollision for an object
  // so that it returns true
  // if
  //   an object 
  // OR
  //   one of its descendants
  // collide with the map
  //
  // TEST IT

  // TODO 6:  add another checkCollision(const WorldItem& other)
  // that returns true if *this 
  // collides with other (or one of its descendants)
  //
  // TEST IT

  // TODO 7:
  // adjust the check_collision() method so that
  // only for objects whose parent is the root of the tree
  // we check a collision against the map (using TODO 5)
  // AND a collision between *this and all his siblings (using TODO 6)
  //
  // TEST IT

  // TODO 8:
  // add another class derived from WorldItem, and call it UnicyclePlatform
  // a Unicycle is a world_object that has a translational
  // and rotational velocity
  // override the tick(float dt) method so that, when it is invoked it calls the
  // method move, on an isometry that moves the object by
  //  dt*translational velocity along its x axis and
  //  rotates by*rotatonal_velocity
  //
  // TEST IT

  // TODO 9:
  // give the LaserScanner a notion of frequency
  // it calls getScan each time the interval between the last acquired scan and
  // now is above 1/frequency
  // the time can be measured by accumulating the dt passed to the tick method
  // override the tick(float dt) method and all the needed variables to the
  // class
  
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
            
  // TODO 10:
  // make the draw to draw all children's draw
  virtual void draw(Canvas& canvas, bool show_parent) const;

  
  // this will be called by the simulator
  // the argument time_interval specifies the time elapsed between the previous call of
  // tick and now
  // TODO 11
  // make the tick call the tick of all other objects
  virtual void tick(float time_interval);
};
