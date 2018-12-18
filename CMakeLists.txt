cmake_minimum_required(VERSION 3.8)

set(CMAKE_BUILD_TYPE Debug)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.123.tar.gz"
    SHA1 "57d07480686f82ddc916a5980b4f2a18e5954c2b"
)

project(scheme)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

hunter_add_package(OpenCV)
find_package(OpenCV REQUIRED)
add_executable(
  output
  main.cpp
  header.cpp
)
target_link_libraries(output PRIVATE ${OpenCV_LIBS})
