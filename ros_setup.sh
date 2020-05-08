#!/bin/bash

## Bash script for setting up ROS Melodic and Gazebo 9.
## This script was designed to work on Ubuntu 18.04 LTS (Last updated: 08/05/2020).
##
## Installs:
## - ROS Melodic
## - Gazebo 9

echo ""
echo "Installing ROS Melodic and Gazebo 9"
echo "==================================="
echo ""
## Setup keys
echo "Setting up keys."
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
sudo apt update
## Get ROS/Gazebo
echo "Installing ROS/Gazebo."
sudo apt install ros-melodic-desktop-full -y
## Initialize rosdep
echo "Initializing rosdep."
sudo rosdep init
rosdep update
## Setup environment variables
echo "Setting up environment variables."
rossource="source /opt/ros/melodic/setup.bash"
if grep -Fxq "$rossource" ~/.bashrc; then echo ROS setup.bash already in .bashrc;
else echo "$rossource" >> ~/.bashrc; fi
eval $rossource
## Install rosinstall and other dependencies
echo "Installing some ROS dependencies"
sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
## Install Gazebo dependencies
echo "Installing Gazebo dependencies"
sudo apt-get install protobuf-compiler libeigen3-dev libopencv-dev -y
