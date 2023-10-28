#include <iostream>

#include "grid_map.h"
#include "isometry_2.h"
#include "world_item.h"

//TODO 1: refactor this code, separating headers and cpp for laserScanner


using namespace std;

struct LaserScan {
  Scalar
    range_min=0.1,
    range_max=10,
    angle_min=-M_PI/2,
    angle_max=M_PI/2;
  int ranges_num= 0;
  Scalar * ranges = nullptr;

  LaserScan (Scalar range_min=0.1,
             Scalar range_max=10,
             Scalar angle_min=-M_PI/2,
             Scalar angle_max=M_PI/2,
             int ranges_num=180)
 {
   this->range_min= range_min;
   this->range_max= range_max;
   this->angle_min= angle_min;
   this->angle_max= angle_max;
   this->ranges_num = ranges_num;
  
   ranges = new Scalar[ranges_num];
   for (int i=0; i<ranges_num; ++i)
     ranges[i]=range_max;
 }

  ~LaserScan() {
    delete [] ranges;
  }

  void draw(Canvas& canevasso, const GridMap& grid_map, const Isometry2& pose) {

    Vec2i center_px=grid_map.world2grid(pose.translation);
    Scalar angle_increment = (angle_max-angle_min)/ranges_num;
    Isometry2 rotation=pose;
    rotation.translation.setZero();
    
    for (int i=0; i<ranges_num; ++i) {
      Scalar beam_angle=angle_min+angle_increment*i;
      Vec2 d={cos(beam_angle),
              sin(beam_angle)};
      d=rotation * d;
      Vec2 ep = pose.translation + d*ranges[i];
      Vec2i ep_px = grid_map.world2grid(ep);
      drawLine(canevasso, center_px, ep_px, 90); 
    }
  }
};


struct LaserScanner: public WorldItem{
  LaserScan& scan;

  LaserScanner(LaserScan& scn,
            WorldItem& par,
            const Isometry2& pos):
    WorldItem(par, pos),
    scan(scn)
  {}

  void draw(Canvas& canvas, bool show_parent) const {
    scan.draw(canvas, *grid_map, globalPose());
  }

  void getScan() {
    Isometry2 gp=globalPose();
    Isometry2 rotation=gp;
    rotation.translation = {0,0};
    Scalar angle_increment = (scan.angle_max-scan.angle_min)/scan.ranges_num;
    
    for (int i=0; i<scan.ranges_num; ++i) {
      Scalar beam_angle=scan.angle_min+angle_increment*i;
      Vec2 d={cos(beam_angle),
              sin(beam_angle)};
      d=rotation * d;
      scan.ranges[i] = grid_map->scanRay(gp.translation, d, scan.range_max);
    }
    
    
  }
};
  
  
void printItems(WorldItem** items) {
  while (*items) {
    WorldItem* v = *items;
    cout << "**************************************" << endl
         << "Item: " << v << endl
         << "pose: " << endl
         << v->pose_in_parent << endl
         << "parent: " << v->parent << endl;
    ++items;
  }
}

// TODO 6  write a function that draws the object array on the canvas
void drawItems(Canvas& canvas, WorldItem** items) {
  while (*items) {
    WorldItem* v = *items;
    v->draw(canvas, true);
    ++items;
  }
}

// TODO 8. write a function that returns true if there is at least one cell
//        with value < 127 within a radius of "radius", centered in  "center".


int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "usage: " << argv[0] << " <image_file> <resolution>" << endl;
    return -1;
  }
  const char* filename = argv[1];
  Scalar resolution = atof(argv[2]);

  cout << "Running " << argv[0] << " with arguments" << endl
       << "-filename:" << argv[1] << endl
       << "-resolution: " << argv[2] << endl;

  GridMap grid_map(0, 0, 0.1);
  grid_map.loadFromImage(filename, resolution);
  Canvas canvas;
  Vec2 center = grid_map.grid2world(grid_map.origin);
  cerr << "center: " << center[0] << "  " << center[1] << endl;
  cerr << "origin: " << grid_map.origin[0] << "  " << grid_map.origin[1]
       << endl;

  grid_map.draw(canvas);

  WorldItem* items[100];
  memset(items, 0, sizeof(WorldItem*) * 100);

  WorldItem world_object(grid_map);
  items[0] = &world_object;
  WorldItem object_0(world_object, Isometry2(1, 0, 0.5));
  items[1] = &object_0;

  WorldItem object_1(world_object, Isometry2(0, -1, -0.5));
  object_1.radius=2;
  items[2] = &object_1;

  LaserScan scan;

  LaserScanner scanner(scan, object_1, Isometry2(0, -1, -0.5));
  scanner.radius = 0.5;
  items[3] = &scanner;


  
  const Isometry2 forward(0.1, 0, 0);
  const Isometry2 backward(-0.1, 0, 0);
  const Isometry2 left(0, 0, 0.1);
  const Isometry2 right(0, 0, -0.1);

  while (true) {
    scanner.getScan();
    grid_map.draw(canvas);
    drawItems(canvas, items);
    //scan.draw(canvas, grid_map, object_1.globalPose());
    int ret = showCanvas(canvas, 0);
    std::cerr << "Key pressed: " << ret << std::endl;

    Isometry2 motion_iso=Isometry2::Identity();
    switch(ret) {
    case 81: //left;
      motion_iso=left;
      break;
    case 82: //up;
      motion_iso=forward;
      break;
    case 83: //right;
      motion_iso=right;
      break;
    case 84: //down;
      motion_iso=backward;
      break;
    default:;
    }
    object_1.move(motion_iso);
    
  }

  // TODO 9. test the check_collision
}
