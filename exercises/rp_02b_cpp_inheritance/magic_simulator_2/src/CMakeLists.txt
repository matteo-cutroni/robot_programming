add_library(simple_sim_library SHARED
  vec_x.cpp
  isometry_2.cpp
  grid_map.cpp
  draw_helpers.cpp)

target_link_libraries(simple_sim_library
  ${OpenCV_LIBS}
)

add_executable(test_geometry_2d
  test_geometry_2d.cpp)

target_link_libraries(test_geometry_2d
  simple_sim_library
  ${OpenCV_LIBS}
)

add_executable(test_grid_map
  test_grid_map.cpp)

target_link_libraries(test_grid_map
  simple_sim_library
  ${OpenCV_LIBS}
)

add_executable(test_stuff
  test_stuff.cpp)

target_link_libraries(test_stuff
  simple_sim_library
  ${OpenCV_LIBS}
)
