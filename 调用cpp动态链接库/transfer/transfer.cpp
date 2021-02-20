//#include <iostream>

#include "coor.hpp"

using namespace std;

double transfer(double distance, double start_lon, double start_lat,
                double end_lon, double end_lat) {

    double x, y, lon, lat;

    trunk::nav::core::dis2utm(distance, start_lon, start_lat, end_lon, end_lat, x, y, lon, lat);
    return x, y;

}

extern "C" {
    double transfer_to_utm(double distance, double start_lon, double start_lat,
                double end_lon, double end_lat) {
                    return transfer(distance, start_lon, start_lat, end_lon, end_lat);
                }
}
