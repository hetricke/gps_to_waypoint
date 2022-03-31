#pragma once

#include "convert.hpp"
#include "vector"
#include "string"


class ReadFile{

public:
ReadFile() = delete;

static std::vector<GPSCoordinates> read(std::string file_name);


};