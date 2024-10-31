cmake_minimum_required(VERSION 2.8)
project(vido_slam)


IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

# ======  start c++ compile  ======

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -pthread")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall   -O3 -march=native")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall   -O3 -w")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -Og -Wall ")

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

# set(Torch_DIR /home/alwen/anaconda3/envs/slam/lib/python3.7/site-packages/torch/share/cmake/Torch)
# find_package(Torch REQUIRED)

set(OpenCV_DIR /home/alwen/thrid_party/opencv-3.4.0/opencv_3.4.0_install/share/OpenCV)
find_package(OpenCV 3 QUIET)
#find_package(OpenCV 3.3.4 QUIET)

if(NOT OpenCV_FOUND)
   message(FATAL_ERROR "OpenCV > 3.4.0 not found.")
   find_package(OpenCV 2.4.3 QUIET)
   if(NOT OpenCV_FOUND)
      message(FATAL_ERROR "OpenCV > 2.4.3 not found.")
   endif()
endif()

find_package(Eigen3 3.1.0 REQUIRED)
find_package(CSparse REQUIRED)
set(Pangolin_DIR /home/alwen/thrid_party/Pangolin/build/src)
find_package(Pangolin REQUIRED)

include_directories(
   ${PROJECT_SOURCE_DIR}
   ${PROJECT_SOURCE_DIR}/include
   ${EIGEN3_INCLUDE_DIR}
   ${CSPARSE_INCLUDE_DIR}
   ${Pangolin_INCLUDE_DIRS}
   # ${Torch_INSTALL_INCLUDE}
   # ${Torch_DIR}
)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


add_library(${PROJECT_NAME} SHARED
   src/System.cc
   src/ImuTypes.cc
   src/Tracking.cc
   src/ORBextractor.cc
   src/Converter.cc
   src/G2oTypes.cc
   src/Map.cc
   src/Optimizer.cc
   src/Frame.cc
   src/viewer/VidoViewer.cc
   src/cvplot/color.cc
   src/cvplot/figure.cc
   src/cvplot/highgui.cc
   src/cvplot/window.cc
)

target_link_libraries(
   ${PROJECT_NAME}
   ${OpenCV_LIBS}
   ${EIGEN3_LIBS}
   ${CSPARSE_LIBRARY}
   ${Pangolin_LIBRARIES}
   ${PROJECT_SOURCE_DIR}/3rdparty/g2o/lib/libg2o.so
)

add_executable(run_vido demo/run_vido_slam.cc)
target_link_libraries(run_vido ${PROJECT_NAME}
                               ${OpenCV_LIBS}
                               ${Pangolin_LIBRARIES})
            
# add_executable(test1 demo/test1.cc)
# target_link_libraries(test1 ${PROJECT_NAME}
#                               ${OpenCV_LIBS})


