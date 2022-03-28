cmake_minimum_required(VERSION 3.8)

project(Example)

add_subdirectory(
  ${PROJECT_SOURCE_DIR}/..

  # Out of source, we need to provide the build directory
  ${CMAKE_CURRENT_BINARY_DIR}/tickscheduler.dir
)

add_executable(${PROJECT_NAME} example.cpp)
target_link_libraries(${PROJECT_NAME} tickscheduler)