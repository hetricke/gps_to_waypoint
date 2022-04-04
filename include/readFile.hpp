#pragma once

#include "convert.hpp"
#include "string"
#include "vector"
#include <fstream>
#include <iostream>
#include <sstream>
namespace ReadFile {

std::vector<GPSCoordinates> read(std::string file_path){

  int state = 0;
  std::vector<GPSCoordinates> results;

  // used to process the file line by line
  std::ifstream WaypointsList(file_path);
  std::string wp;

  // used to split the gps coordinates into different components
  std::vector<std::string> tok;
  std::stringstream split(wp);
  std::string token;

  // Runs if the file is found
  if (WaypointsList) {

    // runs until it reaches the end of file
    while (getline(WaypointsList, wp)) {

      // changes to different states based on tag
      if (wp.find("[") != std::string::npos) {

        if (wp.find("start") != std::string::npos) {

          state = 1;
        }

        else if (wp.find("points") != std::string::npos) {

          state = 0;
        }

        continue;
      }

      // splits line into long, lat, and orientation
      while (getline(split, token, ',')) {
        tok.push_back(token);
      }

      GPSCoordinates new_gps_point;
      new_gps_point.longitude = stod(tok[0]);
      new_gps_point.latitude = stod(tok[1]);
      new_gps_point.orientation = stod(tok[2]);

      // adds gps point to vector based on state
      if (state == 0) {
        results.push_back(new_gps_point);

      }

      else if (state == 1) {
        results.insert(results.begin(), new_gps_point);
      }
    }

    WaypointsList.close();

  }

  else {

    std::cout << "File not found" << std::endl;
    return {};
  }

  return results;
};

}