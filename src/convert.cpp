#include "../include/convert.hpp"
#include <vector>
#include <cmath>

/**
 * @brief convert a list of gps coordinates to a list of waypoints
 * @param gps_coordinates_list 
 * @return Convert 
 */
Convert Convert::convert_gps_to_waypoint(std::vector<GPSCoordinates> gps_coordinates_list) {
    Convert obj;

    Waypoint temp_waypoint;

    if (!gps_coordinates_list.empty()) {
        for (auto temp_gps: gps_coordinates_list) {
            if (obj.waypoints.empty()) {
                // assign the first GPS coordinate in the list as origin, then convert to waypoint
                obj.origin_x_ = temp_gps.latitude;
                obj.origin_y_ = temp_gps.longitude;
                obj.yaw_ = obj.get_yaw(temp_gps.orientation);
                temp_waypoint = {0, 0, obj.z_, obj.roll_, obj.pitch_, obj.yaw_, obj.tolerance_};
                obj.waypoints.push_back(temp_waypoint);
            }
            else {
                // convert the remaining GPS coordinates in the list to waypoint
                obj.x_ = obj.get_x(temp_gps.latitude);
                obj.y_ = obj.get_y(temp_gps.longitude);
                obj.yaw_ = obj.get_yaw(temp_gps.orientation);

                temp_waypoint = {obj.x_, obj.y_, obj.z_, obj.roll_, obj.pitch_, obj.yaw_, obj.tolerance_};
                obj.waypoints.push_back(temp_waypoint);
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

    return obj;
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