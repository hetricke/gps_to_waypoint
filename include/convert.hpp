#include <vector>
#include <numbers>

struct Waypoint {
    double x;
    double y;
    double z;

    double roll;
    double pitch;
    double yaw;

    double tolerance;
};

struct GPSCoordinates {

    double latitude;
    double longitude;
    double orientation;

};


namespace converter {
    double get_x(double gps_x, double origin_x) {
        return gps_x - origin_x;
    }
    double get_y(double gps_y, double origin_y) {
        return gps_y - origin_y;
    }

    double get_yaw(double angle) {
        return angle * std::numbers::pi / 180;
    }

    std::vector<Waypoint> convert_gps_to_waypoint(std::vector<GPSCoordinates>& gps_coordinates_list) {
        Waypoint temp_waypoint;
        std::vector<Waypoint> waypoints;

        double origin_x{}, x{};
        double origin_y{}, y{};
        double yaw{};

        // constant??
        double z = 0;
        double roll = 0;
        double pitch = 0;
        double tolerance = 0.3;

        if (!gps_coordinates_list.empty()) {
            for (auto temp_gps: gps_coordinates_list) {
                if (waypoints.empty()) {
                    // assign the first GPS coordinate in the list as origin, then convert to waypoint
                    origin_x = temp_gps.latitude;
                    origin_y = temp_gps.longitude;
                    yaw = get_yaw(temp_gps.orientation);
                    temp_waypoint = {0, 0, z, roll, pitch, yaw, tolerance};
                    waypoints.push_back(temp_waypoint);
                }
                else {
                    // convert the remaining GPS coordinates in the list to waypoint
                    x = get_x(temp_gps.latitude, origin_x);
                    y = get_y(temp_gps.longitude, origin_y);
                    yaw = get_yaw(temp_gps.orientation);

                    temp_waypoint = {x, y, z, roll, pitch, yaw, tolerance};
                    waypoints.push_back(temp_waypoint);
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


        return waypoints;
    }
} // namepsace converter