#pragma once

#include "convert.hpp"
#include "vector"
#include "string"


class ReadFile{

public:
ReadFile();

std::vector<gps_coordinates> read(std::string file_name);


};