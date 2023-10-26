#include <iostream>

#include "vec_x.h"
#include "isometry_2.h"

using namespace std;

int main(int argc, char** argv) {
  if (argc<2) {
    cout << "usage: " << argv[0] << " <image_file> <resolution>" << endl;
    return -1;
  }

  const char* fileimage = argv[1];
  Scalar resolution = atof(argv[2]);

  cout << "Running " << argv[0] 
       << "with arguments: " << endl
       << "-filename: " << argv[1] << endl
       << "-resolution: " << argv[2] << endl;

  
  Vec2i v0;
  v0[0] = 1;
  v0[1] = 2;
  cout << "v0" << v0 << endl;
  Vec2i v1 = v0 * 2;
  cout << "v1" << v1 << endl;
  v1 += v1;
  cout << "v1" << v1 << endl;
  Vec2i v2 = v0 + v1;
  cout << "v2" << v2 << endl;
  Vec2i vk = v0;
  vk *= v1;
  cout << "vk" << vk << endl;

  Vec3 v3;
  v3[0] = 1;
  v3[1] = 2;
  v3[2] = 0.2;
  cout << "v3" << v3 << endl;

  Vec3 iso_vec;
  iso_vec[0] = 1;
  iso_vec[1] = 1;
  iso_vec[2] = M_PI_2;

  Isometry2 iso(iso_vec);
  cout << "iso" << iso << endl;
  cout << "iso.inverse() " << iso.inverse() << endl;
  cout << "iso * iso.inverse() " << iso * iso.inverse() << endl;
  Vec2 test_vect;
  test_vect[0] = 1;
  test_vect[1] = 0;
  Vec2 res = iso * test_vect;
  cout << "iso * test_vect " << res << endl;
}
