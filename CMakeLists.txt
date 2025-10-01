cmake_minimum_required(VERSION 3.8)
project(sim_zby_barna)

if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)


set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
)


add_executable(jelgen src/jelgen.cpp)
ament_target_dependencies(jelgen rclcpp std_msgs)

add_executable(osszeg src/osszeg.cpp)
ament_target_dependencies(osszeg rclcpp std_msgs)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS
  jelgen
  osszeg
  DESTINATION lib/${PROJECT_NAME})

ament_package()