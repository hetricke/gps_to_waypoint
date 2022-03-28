#pragma once


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "/home/hetricke/Documents/ISC/GPS to Waypoint/gps_to_waypoint/include/readFile.hpp"


    
    ReadFile::ReadFile(){
    }

   std::vector<gps_coordinates> ReadFile::read(std::string file_path){

        int state = 0;
        std::vector<gps_coordinates> results;

        std::ifstream WaypointsList(file_path);
        std::string wp;

        std::vector<std::string> tok;
        std::stringstream split(wp);
        std::string token;

        if(WaypointsList){

        while(getline(WaypointsList, wp)){

            if(wp.find("[") != std::string::npos){
                
                if (wp.find("start")!= std::string::npos){

                    state = 1;
                }

                else if (wp.find("points")!= std::string::npos){

                    state = 0;
                }

                continue;

            }


     
             while(getline(split, token, ','))
            {
                tok.push_back(token);
            }

            gps_coordinates new_gps_point;

            char *t;
            new_gps_point.longitude = stod(tok[0]);
            new_gps_point.latitude = stod(tok[1]);
            new_gps_point.orientation = stod(tok[2]);
     

            
            if (state == 0){
                results.push_back(new_gps_point);

            }

            else if (state == 1){
                results.insert(results.begin(), new_gps_point);

            }


        }


        WaypointsList.close();

        }

        else{

            std::cout<<"File not found"<<std::endl;
            return {};
        }


    return results;

    }