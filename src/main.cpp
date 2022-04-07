#include <iostream>
#include "../include/readFile.hpp"
#include "convert.hpp"
#include <string>
//#include "fmt/core.h"


int main(int argc, char *argv[]) {

    std::string fp = "/home/hetricke/Documents/ISC/Testing/gps_test_read";
    std::vector<GPSCoordinates> result = ReadFile::read(fp);


    for (int i = 0; i < result.size(); i++) {
        printf("%lf, %lf, %lf", result[i].longitude, result[i].latitude, result[i].orientation);
    }

    auto converted = converter::convert_gps_to_waypoint(result);

    return 0;
}
