cmake_minimum_required(VERSION 3.0.2)
project(demo)
SET(CMAKE_BUILD_TYPE "Debug")

set(OpenCV_DIR /home/alwen/thrid_party/opencv-3.4.0/opencv_3.4.0_install/share/OpenCV)
find_package(OpenCV 3.4 REQUIRED)

find_package(Pangolin REQUIRED)

set(cv_bridge_DIR /home/alwen/thrid_party/vision_opencv/cv_bridge/cv_bridge_install/share/cv_bridge/cmake)
set(cv_bridge_INCLUDE_DIRS /home/alwen/thrid_party/vision_opencv/cv_bridge/cv_bridge_install/include)
set(cv_bridge_LIBRARIES /home/alwen/thrid_party/vision_opencv/cv_bridge/cv_bridge_install/lib)

find_package(cv_bridge REQUIRED)
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "    LIBRARIES: ${OpenCV_LIBRARIES}")




find_package(catkin REQUIRED COMPONENTS
	rosbag
	roscpp
	tf2_ros
	tf2_sensor_msgs
	image_transport
	flow_net
	mask_rcnn
	mono_depth2
	visualization_msgs
	message_generation
	std_msgs
	# cv_bridge
	nav_msgs
	sensor_msgs)

catkin_package(
  LIBRARIES ${PROJECT_NAME}
	CATKIN_DEPENDS
	roscpp
	rosbag
	rosbag_storage
	image_transport
	std_msgs
	tf2_ros
	tf2_sensor_msgs
	nav_msgs
	sensor_msgs
	# cv_bridge
	flow_net
	mask_rcnn
	mono_depth2
	message_runtime
)

# file(GLOB_RECURSE OLD_OPENCV "/usr/lib/x86_64-linux-gnu/libopencv*")
# list(REMOVE_ITEM catkin_LIBRARIES ${OLD_OPENCV})

include_directories(
    ${catkin_INCLUDE_DIRS}
	${cv_bridge_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/../../vido_slam/include/
)


add_executable(${PROJECT_NAME}
		  src/run_vido.cc
		  src/utils.cc
		  
           )



target_link_libraries(${PROJECT_NAME}
		${catkin_LIBRARIES}
		${cv_bridge_LIBRARIES}
		${OpenCV_LIBRARIES}
		${Pangolin_LIBRARIES}
		${PROJECT_SOURCE_DIR}/../../vido_slam/lib/libvido_slam.so
		)
message(STATUS "    catkin_LIBRARIES: ${catkin_LIBRARIES}")
