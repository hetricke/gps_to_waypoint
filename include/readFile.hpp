#pragma once

#include "convert.hpp"
#include "vector"
#include "string"


class ReadFile{

public:
ReadFile();

std::vector<GPS_coordinates> read(std::string file_name);


};