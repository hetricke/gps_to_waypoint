
#include <iostream>
#include "../include/readFile.hpp"
#include "fmt/core.h"
#include <string>


int main(int argc, char* argv[]){
        std::cout<<"hewwo";


        std::string fn = "/home/hetricke/Documents/ISC/Testing/gps_test_read.txt";
        std::vector<GPSCoordinates> result = ReadFile::read(fn);

        for (int i = 0; i<result.size(); i++){
            printf("%lf, %lf, %lf", result[i].longitude, result[i].latitude, result[i].orientation);

        }

    return 0;
}
