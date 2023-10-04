# ROBO_DC_UFSCar

This package offers a toolkit for autonomous robots.
 
| Operational System 	         |  Ubuntu 20.04            | 
| ---------------------------- | ------------------------ |
| ROS 	                       | ![image](https://user-images.githubusercontent.com/74054598/149457205-fd48db89-0658-4511-af36-bcd8662562da.png)| 
| Gazebo    	                 | Gazebo multi-robot simulator - version 11.13.0     | 

**Features**
   - Mobile robot
   - RPLidar
   - Velodyne

## Required packages in GIT links:

    git clone https://github.com/rrdpereira/envrobotz.git

    git clone https://github.com/rrdpereira/mobile_rob_dev_sim.git  

## Required packages in apt-get:

    sudo apt-get install ros-noetic-amcl ros-noetic-costmap-converter ros-noetic-depthimage-to-laserscan ros-noetic-dynamic-reconfigure ros-noetic-ddynamic-reconfigure ros-noetic-ddynamic-reconfigure-dbgsym ros-noetic-ddynamic-reconfigure-python ros-noetic-geometry2 ros-noetic-hector-slam ros-noetic-move-base ros-noetic-move-base-flex ros-noetic-navigation ros-noetic-openslam-gmapping ros-noetic-rplidar-ros ros-noetic-slam-gmapping ros-noetic-spatio-temporal-voxel-layer ros-noetic-teb-local-planner ros-noetic-teleop-twist-keyboard ros-noetic-teleop-twist-joy ros-noetic-urg-node ros-noetic-rtabmap ros-noetic-rtabmap-ros ros-noetic-octomap ros-noetic-octomap-ros ros-noetic-octomap-rviz-plugins ros-noetic-octomap-server ros-noetic-octovis ros-noetic-imu-filter-madgwick ros-noetic-robot-localization ros-noetic-robot-pose-ekf ros-noetic-pointcloud-to-laserscan ros-noetic-rosbridge-server ros-noetic-map-server ros-noetic-realsense2-camera ros-noetic-realsense2-description ros-noetic-cmake-modules ros-noetic-velodyne-gazebo-plugins ros-noetic-ompl ros-noetic-navfn ros-noetic-dwa-local-planner ros-noetic-global-planner ros-noetic-costmap-2d ros-noetic-robot-self-filter ros-noetic-ros-numpy ros-noetic-pcl-ros ros-noetic-pcl-conversions ros-noetic-grid-map-costmap-2d ros-noetic-grid-map-ros ros-noetic-grid-map-filters ros-noetic-grid-map-visualization ros-noetic-tf2-tools pcl-tools

## Check dependences on workspace with:

        rosdep install --from-paths src --ignore-src -r -y

## Build workspace command:

    catkin_make -DCMAKE_BUILD_TYPE=Release   

## Step 0 - Ubuntu 20.04

**0.1 - Create Installation Media**

Download Ubuntu 20.04:* Visit the official Ubuntu website at [https://ubuntu.com/download](https://ubuntu.com/download) and download the **Ubuntu 20.04 LTS ISO image**.
> [!Warning]
> Ensure you select the correct version for your system's architecture (32-bit or 64-bit) and the "Download" option for the desktop.

Create a bootable USB drive using a tool like "Rufus" on Windows or "Etcher" on Linux or macOS. This will allow you to boot Ubuntu from the USB drive.

**0.2 - Booting into Ubuntu 20.04**

> [!WARNING]
> Before you begin, make sure to back up your important data, as the installation of the operating system typically involves disk formatting.
```bash
 0.2.1 - Connect the bootable USB drive to your computer.
 
 0.2.2 - Restart your computer and access the boot menu (usually by pressing a specific key like F2, F12, or Delete during startup).
 
 0.2.3 - In the boot menu, choose the option corresponding to the USB drive you created and press Enter.
```
**0.3: Installing Ubuntu 20.04**
```bash
0.3.1 - The Ubuntu Live USB will start. You can try Ubuntu without installing it, but for installation, click the "Install Ubuntu" icon on the desktop.

0.3.2 -Follow the on-screen instructions to select your language, time zone, and keyboard layout.

0.3.3 -When you reach the disk partitioning screen, you have the following options:

   "Erase disk and install Ubuntu": This option will erase all contents of the disk and install Ubuntu. Use this option if you no longer need any existing operating system.
 
   "Install alongside [another operating system]": This option allows you to keep your existing operating system and install Ubuntu alongside it, creating a dual-boot configuration. You can choose which operating system to boot when starting your computer.
  
   "Something else": If you want to configure partitions manually, you can select this option.

0.3.4 -Follow the instructions to create a user account, set a password, and choose a computer name.

0.3.5 -Complete the installation process and restart your computer when prompted.

0.3.6 -After restarting, you will be running **Ubuntu 20.04**. You can log in with the user account you created during the installation.
```

## Step 1 - Preparing the Environment 

> [!IMPORTANT]
> Before installing the MRS System, set up the environment and ensure proper graphics driver compatibility. 

### Graphics card

To check and configure a graphics card correctly on an Ubuntu 20.04 system, you can follow these steps:

**1.1: Check if you have a graphics card.**

You can use the following command to list information about your graphics card:

```bash
sudo update-pci ids
lspci | grep -i vga
```

This command will display information about your graphics card if you have one. 

> [!NOTE]
> `lspci` command lists PCI devices, including their manufacturer and model information. When you execute the `lspci | grep -i vga` command, you filter the list to display only information related to the graphics card.

If a graphics card is installed in your system, the output of the command typically looks something like this:

```
01:00.0 VGA compatible controller: NVIDIA Corporation GP106 [GeForce GTX 1060 6GB] (rev a1)
```
In this example, the manufacturer is "NVIDIA Corporation," and the model is "GeForce GTX 1060 6GB."  

**1.2. Check graphics card compatibility:**

To ensure smooth performance, verify the appropriate driver of your graphics card. 

Open a terminal and enter the following command to list available drivers:
```bash
   ubuntu-drivers devices
```

**1.3: Install graphics driver** 

If the drivers are available, install them using the `ubuntu-drivers` command (a tool for managing system-recommended drivers). Run the following commands:

```bash
sudo apt-get update
sudo apt-get install ubuntu-drivers-common
sudo ubuntu-drivers autoinstall
```

This will install the recommended drivers for your graphics card.

> [!NOTE]
> If you have an NVIDIA graphics card. You also can check that NVIDIA drivers are available for your graphics card by visiting the NVIDIA website (https://www.nvidia.com/Download/index.aspx). If needed, you might have to replace it with a supported version.

**1.4: Update NVIDIA Driver:** 

If your current NVIDIA driver version is not supported, you'll need to update it. For example, if your driver version is nvidia-driver-510-server, use the appropriate version number and execute the following commands:

 ```bash 
sudo apt install nvidia-driver-X  # Replace X with your supported version
sudo reboot
```
After installing the drivers, you can verify if the graphics card has been correctly recognized using the following command:

```bash
nvidia-smi
```

**1.5: Restart the system:**
Remember to restart your system if required after installing the drivers.

```bash
sudo reboot
```

### Install Dependencies:
Ensure you have the necessary tools installed for a smooth installation. Run these commands:

```bash 
sudo apt-get install nautilus-open-terminal ssh libjpeg-dev libpng-dev libtiff-dev libx11-dev libavformat-dev libavdevice-dev libavcodec-dev libavutil-dev libswresample-dev libglu-dev libdc1394-22-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev python-pip3 git gitman tmux tmuxinator
```

** Updating pip** 

To ensure you have the latest version of pip, you can run the following command:

```bash
python3 -m pip install --upgrade pip
```

```bash
pip install numpy scipy scikit-learn scikit-image
```

With the environment set up and graphics drivers, you're now ready to install the MRS System.


## Step 2 - Instal MRS System

Follow the instructions [here](https://github.com/ctu-mrs/mrs_uav_system#installation) (on Installation topic) to install MRS System or use the commands:

```bash 
cd /tmp
echo '
GIT_PATH=~/git
mkdir -p $GIT_PATH
cd $GIT_PATH
sudo apt-get -y install git
git clone https://github.com/ctu-mrs/mrs_uav_system
cd mrs_uav_system
git checkout master
git pull
./install.sh -g $GIT_PATH
source ~/.bashrc' > clone.sh && source clone.sh
```
## Step 3 - Upload class's package

```bash 
cd ~/workspace/src 
git clone https://github.com/vivaldini/RMA.git 
catkin build 
bash ../devel/setup.bash
```

## Step 4 - Setting Gazebo

Start Gazebo by entering the following at the command prompt.

```bash 
gazebo
```

Click on Edit -> Model Editor

Click in File -> Save as

Save the model in the Location: /workspace/src/RMA/models.

## Step 5

To add the directory to models and worlds:

   - Open gazebo
   - Click on "Insert" (upper left)
   - Click "Add Path" (upper left)
   - Choose the paste ~/workspace/src/RMA/models
   - Close gazebo

## Step 6 - Test the environment

- UAV
```bash 
cd
bash ~/workspace/src/RMA/src/start/start.sh
```

- Multi UAVs run

```bash
cd
bash ~/workspace/src/RMA/src/start/multiStart.sh

```

### Extra 1: Ways to stop the simulation

Press “CTRL + a” and after “k” in the prompt.

If something remains open:

```bash
Ctrl + K  A
alias killg='killall gzclient && killall gzserver && killall rosmaster'
killall px4
tmux kill-server
```


### Extra 2 - Learning ROS

Communication with the MRS is done through ROS. If you are not yet aware, it is interesting to carry out the tutorial 1.1.1 to 1.1.18 link: http://wiki.ros.org/ROS/Tutorials

## Note:
    1. It is important to improve your expertise to do the tutorials. That will be passed as Frequency Activities.
    
### Extra 3: Use algorithms and information available from MRS

Repository 1: https://ctu-mrs.github.io/docs/system/uav_ros_interface.html#uavmanager

Repository 2: https://ctu-mrs.github.io/docs/software/mavros.html#used-topics-and-services

Topic Informations:

   - Localization: /uav1/odometry/odom_main
   - Laser: /uav1/garmin/range
   - Global motion: /uav1/control_manager/reference
   - Local motion: /uav1/control_manager/goto_fcu


## Support

For support, send an email to vivaldini@ufscar.br.

