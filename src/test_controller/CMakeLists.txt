cmake_minimum_required(VERSION 3.8)
project(test_controller)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)
link_directories(src)

set (
  DEPENDENCY_LIST
  unitree_go
  rclcpp
  std_msgs
)

# find dependencies
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(ament_cmake REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(unitree_go REQUIRED)
find_package(unitree_api REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosbag2_cpp REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(pinocchio REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIRS})
# pkg_check_modules(pinocchio REQUIRED pinocchio)
# message(STATUS "pinocchio_CONFIG: ${pinocchio_CONFIG}")

# executables

add_executable(test_controller src/stand_go2.cpp src/motor_crc.cpp)
ament_target_dependencies(test_controller ${DEPENDENCY_LIST})
target_link_libraries(test_controller pinocchio::pinocchio)

install(TARGETS 
        test_controller
        ${PROJECT_NAME})
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
