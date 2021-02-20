#pragma once

#include <cmath>
#include <cstdio>
#include <iostream>
#include <proj.h>

namespace trunk {
namespace nav {
namespace core {

/**
 * @brief convert utm to lonlat
 * @param x_e x(east) of current point in UTM
 * @param y_n y(north) of current point in UTM
 */
// bool utm2ll(double x_e, double y_n, std::string zone, double &lon,
//             double &lat) {
//     PJ_CONTEXT *C;
//     PJ *P;
//     PJ *P_for_GIS;
//     PJ_COORD tmp, a, b, m;
//     C = proj_context_create();

//     std::string conf =
//         "+proj=utm +ellps=WGS84 +datum=WGS84 +units=m +no_defs +zone=" + zone;

//     P = proj_create_crs_to_crs(C, conf.c_str(), "EPSG:4326", NULL);
//     tmp = proj_coord(x_e, y_n, 0, 0);
//     a = proj_trans(P, PJ_FWD, tmp);
//     lon = a.lp.lam;
//     lat = a.lp.phi;

//     proj_destroy(P);
//     proj_context_destroy(C);

//     return true;
// };


/**
 * @brief convert lonlat  to  utm
 * @param x_e x(east) of current point in UTM
 * @param y_n y(north) of current point in UTM
 */
// bool ll2utm(double lon, double lat, double &out_x, double &out_y) {
//     PJ_CONTEXT *C;
//     PJ *P;
//     PJ *P_for_GIS;
//     PJ_COORD tmp, a, b, m;
//     C = proj_context_create();

//     int zone = int((lon + 180.0) / 6.0) + 1;
//     std::string conf = "+proj=utm +datum=WGS84 +units=m +no_defs +zone=" +
//                        std::to_string(zone);

//     P = proj_create_crs_to_crs(C, "EPSG:4326", conf.c_str(), NULL);

//     if (0 == P) {
//         fprintf(stderr, "dis2utm: bad latitude or longitude\n");
//         return false;
//     }

//     P_for_GIS = proj_normalize_for_visualization(C, P);
//     if (0 == P_for_GIS) {
//         fprintf(stderr, "input: longtitude, latitude\n");
//         return false;
//     }
//     proj_destroy(P);
//     P = P_for_GIS;

//     tmp = proj_coord(lon, lat, 0, 0);
//     a = proj_trans(P, PJ_FWD, tmp);

//     out_x = a.enu.e ;
//     out_y = a.enu.n  ;


//     proj_destroy(P);
//     proj_context_destroy(C);

//     return true;
// };

/**
 * @brief convert distance to  utm
 * @param distance  distance from current point to start point
 * @param start_lon longitude of start point on crane track
 * @param start_lat latitude of start point on crane track
 * @param start_lon longitude of start point on crane track
 * @param start_lat latitude of end point on  crane track
 * @param start_lon longitude of end point  on crane track
 * @param out_x x(east) of current point in UTM
 * @param out_y y(north) of current point in UTM
 * @param out_lon longitude of current point
 * @param out_lat latitude of current point
 * @return successed or not
 */

bool dis2utm(double distance, double start_lon, double start_lat,
             double end_lon, double end_lat, double &out_x, double &out_y,
             double &out_lon, double &out_lat) {
    PJ_CONTEXT *C;
    PJ *P;
    PJ *P_for_GIS;
    PJ_COORD tmp, a, b, m;
    C = proj_context_create();

    int zone = int((start_lon + 180.0) / 6.0) + 1;
    std::string conf = "+proj=utm +datum=WGS84 +units=m +no_defs +zone=" +
                       std::to_string(zone);

    P = proj_create_crs_to_crs(C, "EPSG:4326", conf.c_str(), NULL);

    if (0 == P) {
        fprintf(stderr, "dis2utm: bad latitude or longitude\n");
        return false;
    }

    P_for_GIS = proj_normalize_for_visualization(C, P);
    if (0 == P_for_GIS) {
        fprintf(stderr, "input: longtitude, latitude\n");
        return false;
    }
    proj_destroy(P);
    P = P_for_GIS;

    tmp = proj_coord(start_lon, start_lat, 0, 0);
    a = proj_trans(P, PJ_FWD, tmp);
    tmp = proj_coord(end_lon, end_lat, 0, 0);
    b = proj_trans(P, PJ_FWD, tmp);

    double theta = atan2((b.enu.n - a.enu.n), (b.enu.e - a.enu.e));
    out_x = a.enu.e + distance * cos(theta);
    out_y = a.enu.n + distance * sin(theta);

    tmp = proj_coord(out_x, out_y, 0, 0);
    m = proj_trans(P, PJ_INV, tmp);

    out_lon = m.lpz.lam;
    out_lat = m.lpz.phi;

    proj_destroy(P);
    proj_context_destroy(C);

    return true;
};

} // namespace core
} // namespace nav
} // namespace trunk