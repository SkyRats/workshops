#!/bin/bash

## Bash script for setting up the main software requirements for drone development on Skyrats.
## This script was designed to work on Ubuntu 18.04 LTS (Last updated: 16/03/2020).
##
## Installs:
## - pip2
## - pip3
## - ROS Melodic
## - Gazebo 9
## - MAVROS
## - MAVLink
## - Dronecontrol
## - QGroundControl
## - PX4 Firmware (from Skyrats repository) and its dependencies

catkin_ws_dir=$HOME/catkin_ws ## You can change this workspace to any location on your PC
fastrtps_dir=$HOME/eProsima_FastRTPS-1.7.1-Linux
px4_firm_dir=$HOME/src

## Get sudo privileges and update the repositories
echo "=== Getting sudo privileges and updating repositories ==="
sudo echo ""
sudo apt update


echo ""
echo "Installing pip2 and pip3"
echo "========================"
echo ""
sudo apt-get install python-pip -y
sudo apt-get install python3-pip -y
sudo pip2 install --upgrade pip
sudo pip3 install --upgrade pip


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
## Create catkin workspace
echo "Creatig catkin workspace at ${catkin_ws_dir}"
mkdir -p ${catkin_ws_dir}/src
cd $catkin_ws_dir
catkin init
wstool init src


echo ""
echo "Installing MAVROS and MAVLink"
echo "============================="
echo ""
## Install MAVLink
# We use the Kinetic reference for all ROS distros as it's not distro-specific and up to date
echo "Installing MAVLink"
rosinstall_generator --rosdistro kinetic mavlink | tee /tmp/mavros.rosinstall
## Build MAVROS
echo "Building MAVROS"
rosinstall_generator --upstream mavros | tee -a /tmp/mavros.rosinstall
## Setup workspace & install deps
echo "Setting up workspace & installing deps"
wstool merge -t src /tmp/mavros.rosinstall
wstool update -t src -j4
rosdep install --from-paths src --ignore-src -y
## Install geographiclib
echo "Installing geographiclib"
sudo ./src/mavros/mavros/scripts/install_geographiclib_datasets.sh
## Install Dronecontrol package
echo "Installing dronecontrol package"
cd ${catkin_ws_dir}/src
git clone https://github.com/SkyRats/dronecontrol.git
## Build catkin workspace
echo "Building catkin workspace"
catkin build
## Re-source environment to reflect new packages/build environment
echo "Re-sourcing catkin workspace environment variables"
catkin_ws_source="source ${catkin_ws_dir}/devel/setup.bash"
if grep -Fxq "$catkin_ws_source" ~/.bashrc; then echo ROS catkin_ws setup.bash already in .bashrc;
else echo "$catkin_ws_source" >> ~/.bashrc; fi
eval $catkin_ws_source


echo ""
echo "Installing PX4 Firmware and dependencies"
echo "========================================"
echo ""
## Remove modemmanager
echo "Removing modemmanager"
sudo apt-get remove modemmanager -y
## Install common dependencies
echo "Installing common dependencies"
sudo apt-get install git zip qtcreator cmake build-essential genromfs ninja-build exiftool astyle -y
# make sure xxd is installed, dedicated xxd package since Ubuntu 18.04 but was squashed into vim-common before
which xxd || sudo apt install xxd -y || sudo apt-get install vim-common --no-install-recommends -y
# Required python packages
sudo apt-get install python-argparse python-empy python-toml python-numpy python-dev python-pip -y
sudo -H pip install --upgrade pip
sudo -H pip install pandas jinja2 pyserial pyyaml
# optional python tools
sudo -H pip install pyulog
## Install FastRTPS 1.7.1 and FastCDR-1.0.8
echo "Installing FastRTPS to: $fastrtps_dir"
if [ -d "$fastrtps_dir" ]
then
    echo " FastRTPS already installed."
else
    pushd .
    cd ~
    wget https://www.eprosima.com/index.php/component/ars/repository/eprosima-fast-rtps/eprosima-fast-rtps-1-7-1/eprosima_fastrtps-1-7-1-linux-tar-gz -O eprosima_fastrtps-1-7-1-linux.tar.gz
    tar -xzf eprosima_fastrtps-1-7-1-linux.tar.gz eProsima_FastRTPS-1.7.1-Linux/
    tar -xzf eprosima_fastrtps-1-7-1-linux.tar.gz requiredcomponents
    tar -xzf requiredcomponents/eProsima_FastCDR-1.0.8-Linux.tar.gz
    cpucores=$(( $(lscpu | grep Core.*per.*socket | awk -F: '{print $2}') * $(lscpu | grep Socket\(s\) | awk -F: '{print $2}') ))
    (cd eProsima_FastCDR-1.0.8-Linux && ./configure --libdir=/usr/lib && make -j$cpucores && sudo make install)
    (cd eProsima_FastRTPS-1.7.1-Linux && ./configure --libdir=/usr/lib && make -j$cpucores && sudo make install)
    rm -rf requiredcomponents eprosima_fastrtps-1-7-1-linux.tar.gz
    popd
fi
## jMAVSim simulator dependencies
echo "Installing jMAVSim simulator dependencies"
sudo apt-get install ant openjdk-8-jdk openjdk-8-jre -y
## Clone PX4 firmware (from Skyrats repository)
echo "Cloning PX4 to: $px4_firm_dir"
if [ -d "$px4_firm_dir" ]
then
    echo " Firmware already cloned."
else
    mkdir -p $px4_firm_dir
    cd $px4_firm_dir
    git clone https://github.com/SkyRats/Firmware --recursive
fi


echo ""
echo "Installing QGroundControl"
echo "========================="
echo ""
sudo usermod -a -G dialout $USER
sudo apt install gstreamer1.0-plugins-bad gstreamer1.0-libav -y
cd
wget https://s3-us-west-2.amazonaws.com/qgroundcontrol/latest/QGroundControl.AppImage
chmod +x QGroundControl.AppImage


echo ""
echo "Installations completed, upgrading all software"
echo "==============================================="
echo ""
sudo apt update -y
sudo apt upgrade -y
