cmake_minimum_required(VERSION 3.0.2)
project(mono_depth2)

# set(Torch_DIR /home/alwen/anaconda3/envs/slam/lib/python3.7/site-packages/torch/share/cmake/Torch)
# find_package(Torch REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  geometry_msgs
  visualization_msgs
  message_generation
  roscpp
  rospy
  std_msgs
  sensor_msgs
)
catkin_python_setup()


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  # ${Torch_INSTALL_INCLUDE}
  # ${Torch_DIR}
)



add_service_files(
  FILES
  MonoDepth.srv
)

#add_message_files(
#    FILES
#)

generate_messages(DEPENDENCIES actionlib_msgs geometry_msgs std_msgs sensor_msgs)

catkin_package(
#  INCLUDE_DIRS include
  #LIBRARIES flow_net
  CATKIN_DEPENDS rospy std_msgs message_runtime
#  DEPENDS system_lib
)



