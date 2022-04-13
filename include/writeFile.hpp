#include "convert.hpp"
#include "readFile.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace WriteFile {
    void write(const std::string& file_path){
        std::ofstream file("waypoints.csv");

        if (file.is_open()){
    
            std::vector<Waypoint> pile;
            pile = convert_gps_to_waypoint(ReadFile::read(filepath)));

            file<< "X,Y,Z,Roll,Pitch,Yaw,Tolerance\n";

            for (int i =0; i<pile.size();++i){

                file<< pile.at(i).x<<","<<pile.at(i).y<<","
                <<pile.at(i).z<<","<< pile.at(i).roll<<","<<pile.at(i).pitch
                <<","<<pile.at(i).yaw<<","<<pile.at(i).tolerance<<std::endl;
            }
        } 
        else {
            std::cout<<"File could not open"<<std::endl;
            return;
        } 
    }
} // namespace writefile