# coordinate transform 


## install proj-7.2.0

```
sudo apt install sqlite3

cd proj-7.2.0
mkdir build
cd build 
cmake ..
make 
sudo make install

```


## usage

```
#include "coor.hpp"

trunk::nav::core::dis2utm(dist,                         //distance_to_start_point_of_crane_track, ETMS提供
                          start_lon,                    //start_point_of_crane_track_longitude, 岸桥经度起点
                          start_lat,                    //start_point_of_crane_track_latitude, 岸桥纬度起点
                          end_lon,                      //end_point_of_crane_track_longitude, 岸桥经度终点
                          end_lat,                      //end_point_of_crane_track_latitude, 岸桥纬度终点
                          output_utm_x,                 //output x 岸桥utm
                          output_utm_y,                 //output y
                          output_lon, output_lat        //output in lon/lat
                          );
```



CMakeLists.txt
```
find_package(PROJ)
TARGET_LINK_LIBRARIES(your_app  ${PROJ_LIBRARIES})

```

```shell script
g++ -std=c++11 transfer.cpp -fPIC -shared -o transfer.so

```
