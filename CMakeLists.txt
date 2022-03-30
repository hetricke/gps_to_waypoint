cmake_minimum_required(VERSION 3.16)
project(gps_to_waypoint)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(fmt)

add_executable(gps_to_waypoint src/main.cpp src/readFile.cpp src/convert.cpp src/writeFile.cpp)

target_include_directories(
        gps_to_waypoint
        PUBLIC
        include
)

target_link_libraries(gps_to_waypoint fmt::fmt)
