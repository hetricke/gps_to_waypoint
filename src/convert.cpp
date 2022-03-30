#include "../include/convert.hpp"
#include <vector>
#include <cmath>

Convert Convert::convert_gps_to_waypoint(std::vector<GPSCoordinates> gps_coordinates_list) {
    Convert obj;

    Waypoint temp_waypoint;

    if (!gps_coordinates_list.empty()) {
        for (auto temp_gps: gps_coordinates_list) {
            if (obj.waypoints.empty()) {
                obj.origin_x_ = temp_gps.latitude;
                obj.origin_y_ = temp_gps.longitude;
                obj.yaw_ = obj.get_yaw(temp_gps.orientation);
                temp_waypoint = {0, 0, obj.z_, obj.roll_, obj.pitch_, obj.yaw_, obj.tolerance_};
                obj.waypoints.push_back(temp_waypoint);
            }
            else {
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
    return angle * M_PI / 180;
}