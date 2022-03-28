cmake_minimum_required(VERSION 3.8)

project(tickscheduler)

add_library(${PROJECT_NAME} src/TickScheduler.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)