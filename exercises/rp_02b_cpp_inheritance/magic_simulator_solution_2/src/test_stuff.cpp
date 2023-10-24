#include <iostream>

#include "grid_map.h"
#include "isometry_2.h"

using namespace std;

struct WorldItem {
  Isometry2 pose_in_parent;
  WorldItem* parent;

  WorldItem() {
    parent = 0;
    pose_in_parent.setIdentity();
  }
  WorldItem(const Isometry2& iso) {
    pose_in_parent = iso;
    parent = 0;
  }
  // WorldItem(const Isometry2& iso, WorldItem& p) {
  //   pose_in_parent = iso;
  //   parent = &p;
  // }
  Isometry2 globalPose() const {
    if (!parent) return pose_in_parent;
    return parent->globalPose() * pose_in_parent;
  }

  /**
   * D -> C
   * C -> B
   * B -> A
   * A Returns
   * B returns
   * C returns
   * D Returns
   */

  // nullptr -> A -> B -> C -> D
  // pos(D) wrt A = pos(D) wrt C + pos(C) wrt B + pos(B) wrt A + pos(A) wrt
  // WORLD

  // TODO 3.
  // add to this class the notion of "belonging" to a grid_map
  // the grid_map is shared between an instance and its parent
  // to do this you will have to
  // 1. add a constructor that gives to an object a grid map (if no parent)
  // 2. add a constructor that, once an object is created and is assigned, and
  // the parent has
  //    a grid_map it assignes it to the object
  // ALTERNATIVE
  // make the grid_map a child of WorldItem

  // struct Foo { float[1000000]; }
  // Foo A;
  // A = sumOnes(A); Foo sumOnes(Foo x) {...}
  // sumOnes(&A, &B); void sumOnes(Foo* source, Foo* dest) {...}
  // sumOnes(A, B); void sumOnes(const Foo& source, Foo& dest) {source.float[0]
  // = 1} void sumOnes(const Foo* source, Foo* dest) {
  // (*source).float[0] = 1
  // }

  WorldItem(GridMap& grid) {
    pose_in_parent.setIdentity();
    parent = nullptr;
    grid_map = &grid;
  }

  WorldItem(const Isometry2& iso, WorldItem& p) {
    pose_in_parent = iso;
    parent = &p;
    if (p.grid_map) {
      grid_map = p.grid_map;
    }
  }

  // TODO 4.
  // implement a method that returns a grid_map (by climbing the hierarchy of
  // parents) this might require some file shuffling
  const GridMap& gridMap() const {
    // Recursive Case
    // if (parent == nullptr && grid_map == nullptr) {
    //   throw std::runtime_error("No GridMap available in this branch");
    // }
    // if (grid_map) return *grid_map;
    // return parent->gridMap();

    // Non-Recursive Case
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

    // write here
    // (*pointer) = Reference = SegFAult
  }
  // nullptr -> A -> B -> C -> D

  // TODO 5.
  // add a method "draw" that paints on a canvas
  // - a circle of 1m radius centered in "global frame" where the object is
  // located (translation)
  // - a tick to denote the orientation of the object, drawn as a segment
  // - going from the origin of the object, oriented as the X axis of the
  // rotation matrix
  //   and 1 m long
  // if show_parent is toggled, draw a segment between the center of the object
  // and the center of the parent
  void draw(Canvas& canvas, bool show_parent) const {
    // write here
    Vec2i center = grid_map->world2grid(globalPose().translation);
    int radius = 1.0 * grid_map->inv_resolution;
    drawCircle(canvas, center, radius, 0);

    Vec2 x_in_item = {1, 0};
    Vec2 x_in_world = globalPose() * x_in_item;
    Vec2i x_in_grid = grid_map->world2grid(x_in_world);
    drawLine(canvas, center, x_in_grid, 0);

    if (show_parent == true && parent != nullptr) {
      Vec2i parent_in_grid =
          grid_map->world2grid(parent->globalPose().translation);
      drawLine(canvas, center, parent_in_grid, 100);
    }
  }

  GridMap* grid_map = 0;

  // 1) Constructor : (GridMap&) : save ref to object
  // 2) Constructor : (Worlditem&) : save gridmap ref from parent

  // GridMap grid;
  // WorldItem A(grid);
  // WorldItem B(Isometry2(1, 0, 0), A)

  // grid <- A <- B
  // grid <- B
  //
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

bool checkCollision(const GridMap& grid_map, const Isometry2& pose,
                    const float radius);

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
  WorldItem object_0(Isometry2(1, 0, 0.5), world_object);
  items[1] = &object_0;
  WorldItem object_1(Isometry2(0, -1, -0.5), world_object);
  items[2] = &object_1;
  WorldItem object_2(Isometry2(0, -1, -0.5), object_1);
  items[3] = &object_2;
  printItems(items);

  drawItems(canvas, items);
  showCanvas(canvas, 0);

  // TODO 7. write here something to test the drawing function
  // on the list of objects just created and a map loaded from disk,
  // as in grid_map_test. Between one round and the next, change the position of
  // the origin use arrow keys (up/down/left/right) + and - to rotate
  while (true) {
    grid_map.draw(canvas);
    drawItems(canvas, items);
    int ret = showCanvas(canvas, 0);
    std::cerr << "Key pressed: " << ret << std::endl;

    if (ret == 81) {  // left
      object_1.pose_in_parent.translation[0] -= 0.5;
    }
    if (ret == 82) {  // up
      object_1.pose_in_parent.translation[1] += 0.5;
    }
    if (ret == 83) {  // right
      object_1.pose_in_parent.translation[0] += 0.5;
    }
    if (ret == 84) {  // down
      object_1.pose_in_parent.translation[1] -= 0.5;
    }
    if (ret == 61) {  // +
      object_1.pose_in_parent = object_1.pose_in_parent * Isometry2(0, 0, 0.1);
    }
    if (ret == 45) {  // -
      object_1.pose_in_parent = object_1.pose_in_parent * Isometry2(0, 0, -0.1);
    }
  }

  // TODO 9. test the check_collision
}
