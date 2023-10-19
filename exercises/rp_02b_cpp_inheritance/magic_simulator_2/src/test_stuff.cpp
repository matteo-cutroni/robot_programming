#include <iostream>
#include "grid_map.h"
#include "isometry_2.h"

using namespace std;

struct WorldItem {
  Isometry2  pose_in_parent;
  WorldItem* parent;

  WorldItem(){
    parent=0;
    pose_in_parent.setIdentity();
  }
  WorldItem(const Isometry2& iso){
    pose_in_parent=iso;
    parent=0;
  }
  WorldItem(const Isometry2& iso, WorldItem& p){
    pose_in_parent=iso;
    parent=&p;
  }
  Isometry2 globalPose() const {
    if (! parent)
      return pose_in_parent;
    return parent->globalPose()*pose_in_parent;
  }

  //TODO 3.
  // add to this class the notion of "belonging" to a grid_map
  // the grid_map is shared between an instance and its parent
  // to do this you will have to
  // 1. add a constructor that gives to an object a grid map (if no parent)
  // 2. add a constructor that, once an object is created and is assigned, and the parent has
  //    a grid_map it assignes it to the object
  // ALTERNATIVE
  // make the grid_map a child of WorldItem

  // TODO 4.
  // implement a method that returns a grid_map (by climbing the hierarchy of parents)
  // this might require some file shuffling
  const GridMap& gridMap() const {
    //write here
  }

  // TODO 5.
  // add a method "draw" that paints on a canvas
  // - a circle of 1m radius centered in "global frame" where the object is located (translation)
  // - a tick to denote the orientation of the object, drawn as a segment
  // - going from the origin of the object, oriented as the X axis of the rotation matrix
  //   and 1 m long
  // if show_parent is toggled, draw a segment between the center of the object and the
  // center of the parent
  void draw(Canvas& canvas, bool show_parent) const {
    // write here
  }
  
  GridMap* grid_map=0;
};

void printItems(WorldItem** items) {
  while (*items) {
    WorldItem* v=*items;
    cout << "**************************************" << endl
         << "Item: " << v << endl
         << "pose: " << endl << v->pose_in_parent << endl
         << "parent: " <<  v->parent << endl;
    ++items;
  }
}

//TODO 6  write a function that draws the object array on the canvas
void drawItems(Canvas& canvas, WorldItem** items) {
}

//TODO 8. write a function that returns true if there is at least one cell
//        with value < 127 within a radius of "radius", centered in  "center".

void checkCollision(const GridMap& grid_map, const Isometry2f& pose, const float radius);

int main(int argc, char** argv) {
 

 
  // if (argc<2) {
  //   cout << "usage: " << argv[0] << " <image_file> <resolution>" << endl;
  //   return -1;
  // }
  // const char* filename=argv[1];
  // Scalar resolution=atof(argv[2]);

  // cout << "Running " << argv[0]
  //      << " with arguments" << endl
  //      << "-filename:" << argv[1] << endl
  //      << "-resolution: " << argv[2] << endl;

  // GridMap grid_map(0,0, 0.1);
  // grid_map.loadFromImage(filename, resolution);
  // Canvas canvas;
  // Vec2 center=grid_map.grid2world(grid_map.origin);
  // cerr << "center: " << center[0] << "  "<< center[1] << endl;
  // cerr << "origin: " << grid_map.origin[0] << "  "<< grid_map.origin[1] << endl;
  
  // float alpha=0;
  // while(1) {
  //   grid_map.draw(canvas);
  //   Vec2 direction;
  //   direction[0]=cos(alpha);
  //   direction[1]=sin(alpha);
  //   Vec2 dest;
  //   bool hit = grid_map.scanRay(dest, center, direction, 100);
  //   drawLine(canvas, grid_map.world2grid(center), grid_map.world2grid(dest), 127);
    
  //   showCanvas(canvas, 0);
    
  //   alpha+=0.01;
  // }


  WorldItem* items[100];
  memset(items, 0, sizeof(WorldItem*)*100);
  WorldItem world_object;
  items[0]=&world_object;
  WorldItem object_0(Isometry2(1,0,0.5),world_object);
  items[1]=&object_0;
  WorldItem object_1(Isometry2(0,-1,-0.5),world_object);
  items[2]=&object_1;
  WorldItem object_2(Isometry2(0,-1,-0.5),object_1);
  items[3]=&object_2;
  printItems(items);

  // TODO 7. write here something to test the drawing function
  // on the list of objects just created and a map loaded from disk,
  // as in grid_map_test. Between one round and the next, change the position of
  // the origin use arrow keys (up/down/left/right) + and - to rotate


  // TODO 9. test the check_collision
}
