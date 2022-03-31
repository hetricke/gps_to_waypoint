#include "../include/convert.hpp"
#include <vector>
#include <numbers>

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

std::vector<Waypoint> Convert::get_waypoints() {
    return waypoints;
}
double Convert::get_x(double gps_x) {
    return gps_x - origin_x_;
}

double Convert::get_y(double gps_y) {
    return gps_y - origin_y_;
}

double Convert::get_yaw(double angle) {
    return angle * std::numbers::pi / 180;
}