cmake_minimum_required(VERSION 3.17)
project(Testing)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Testing code/main.cpp  code/Testing_system.cpp  code/Question.cpp code/Question.h code/Testing_system.h)


target_link_libraries(Testing sfml-graphics sfml-audio)
