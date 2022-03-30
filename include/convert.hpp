#include <vector>

struct Waypoint{
    double x;
    double y;
    double z;

    double roll;
    double pitch;
    double yaw;

    double tolerance;
};

struct GPS_coordinates{

    double latitude;
    double longitude;
    double orientation;

};

class Convert {
public:
    void convert_gps_to_waypoint(std::vector<GPS_coordinates>);
    std::vector<Waypoint> get_waypoints();
    double get_x(double);
    double get_y(double);
    double get_yaw(double);

private:
    double origin_x_, x_;
    double origin_y_, y_;
    double yaw_;

    // constant??
    double z_ = 0;
    double roll_ = 0;
    double pitch_ = 0;
    double tolerance_ = 0.3;

    std::vector<Waypoint> waypoints;
};