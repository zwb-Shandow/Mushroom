#include <cmath>
#include <iomanip>
#include <iostream>

#include "coor.hpp"

int main(void) {
    double p0[] = {117.7891748, 38.97784858};
    double m[] = {117.7891872, 38.97784049};
    double p1[] = {117.7891996, 38.9778322};

    double x, y, lon, lat;
    double dist = 1.4;

    double x0, y0, x1, y1;
    trunk::nav::core::ll2utm(p0[0], p0[1], x0, y0);
    trunk::nav::core::ll2utm(p1[0], p1[1], x1, y1);

    trunk::nav::core::dis2utm(dist, p0[0], p0[1], p1[0], p1[1], x, y, lon, lat);

    std::cout << std::setprecision(15) << "ll2utm : (" << p0[0] << "," << p0[1]
              << ") ->  (" << x0 << "," << y0 << ")" << std::endl;

    std::cout << std::setprecision(15) << "(" << p1[0] << "," << p1[1]
              << ") ->  (" << x1 << "," << y1 << ")" << std::endl;

    std::cout << std::setprecision(15) << "dist to utm/ll : (" << m[0] << ","
              << m[1] << ") ->  (" << x << "," << y << ")->    (" << lon << ","
              << lat << ")" << std::endl;

//    double lon0, lat0;
//    trunk::nav::core::utm2ll(x, y, "50N", lon0, lat0);
//    std::cout << std::setprecision(15) << " utm2ll   :   (" << x << "," << y
//              << ") -> (" << lon0 << "," << lat0 << ")" << std::endl;
//
//    std::cout << std::setprecision(8)
//              << "dm_0=" << sqrt((y - y0) * (y - y0) + (x - x0) * (x - x0))
//              << "\n dm_1=" << sqrt((y - y1) * (y - y1) + (x - x1) * (x - x1))
//              << "\n d0_1="
//              << sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0))
//              << std::endl;
}


//#include "coor.hpp"

//using namespace std;
//
//double transfer(double distance, double start_lon, double start_lat,
//                double end_lon, double end_lat) {
//
//    double x, y, lon, lat;
//
//    trunk::nav::core::dis2utm(distance, start_lon, start_lat, end_lon, end_lat, x, y, lon, lat);
//    return x, y;
//
//}
////
////extern "C" {
////double transfer_to_utm(double distance, double start_lon, double start_lat,
////                       double end_lon, double end_lat) {
////    return transfer(distance, start_lon, start_lat, end_lon, end_lat);
////}
////}
//int main() {
//    double p0[] = {117.7891748, 38.97784858};
//    double m[] = {117.7891872, 38.97784049};
//    double p1[] = {117.7891996, 38.9778322};
//
////    double x, y, lon, lat;
//    double dist = 1.4;
//    double x, y;
//    x, y = transfer(dist,p0[0],p0[1],p1[0],p1[1]);
//    std::cout << "x: " << x << std::endl;
//    std::cout << "y: " << y << std::endl;
//    return 0;
}