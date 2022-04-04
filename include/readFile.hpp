#pragma once

#include "convert.hpp"
#include "vector"
#include "string"


namespace ReadFile{

  std::vector<GPSCoordinates> read(std::string file_path);

};