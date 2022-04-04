#include "../include/convert.hpp"
#include <vector>
#include "math.h"

/**
 * @brief convert a list of gps coordinates to a list of waypoints
 * @param gps_coordinates_list 
 * @return Convert 
 */
Convert Convert::convert_gps_to_waypoint(const std::vector<GPSCoordinates>& gps_coordinates_list) {
    Convert converter;

    Waypoint temp_waypoint{};

    if (!gps_coordinates_list.empty()) {
        for (auto& temp_gps: gps_coordinates_list) {
            // First gps point in vector is reference point
            if (converter.waypoints.empty()) {
                converter.origin_x_ = temp_gps.latitude;
                converter.origin_y_ = temp_gps.longitude;
                converter.yaw_ = converter.get_yaw(temp_gps.orientation);

                temp_waypoint = {0, 0, converter.z_, converter.roll_, converter.pitch_, converter.yaw_, converter.tolerance_};
                converter.waypoints.push_back(temp_waypoint);
            }
            else {
                converter.x_ = converter.get_x(temp_gps.latitude);
                converter.y_ = converter.get_y(temp_gps.longitude);
                converter.yaw_ = converter.get_yaw(temp_gps.orientation);

                temp_waypoint = {converter.x_, converter.y_, converter.z_, converter.roll_, converter.pitch_, converter.yaw_, converter.tolerance_};
                converter.waypoints.push_back(temp_waypoint);
            }
        }
    }

    /*
    CONVERT CARTESIAN TO SPHERICAL COORDINATE
    Cartesian (x, y, z)
    Spherical (r, theta, phi)

    r = sqrt((x * x) + (y * y) + (z * z))
    theta = arctan(y / x)
    phi = arctan(sqrt((x * x) + (y * y)) / z)
    */ 

    return converter;
}

/**
 * @brief return a list of converted waypoints
 * @return std::vector<Waypoint> 
 */
std::vector<Waypoint> Convert::get_waypoints() {
    return waypoints;
}

/**
 * @brief convert the x of gps coordinate to x of waypoint
 * @param gps_x
 * @return double 
 */
double Convert::get_x(double gps_x) {
    return gps_x - origin_x_;
}

/**
 * @brief convert the y of gps coordinate to y of waypoint
 * @param gps_y 
 * @return double 
 */
double Convert::get_y(double gps_y) {
    return gps_y - origin_y_;
}

/**
 * @brief convert the angle of gps coordinate (degree) to yaw (radian)
 * @param angle 
 * @return double 
 */
double Convert::get_yaw(double angle) {
    return angle * M_PI / 180;
}