
#include <iostream>
#include "../include/readFile.hpp"
//#include "fmt/core.h"


int main(int argc, char* argv[]){
        std::cout<<"hewwo";


        std::vector<GPSCoordinates> result= ReadFile::read("/home/hetricke/Documents/ISC/Testing/gps_test_read.txt");

        for (int i = 0; i<result.size(); i++){
            printf("%lf, %lf, %lf", result[i].longitude, result[i].latitude, result[i].orientation);

        }

    return 0;
}
