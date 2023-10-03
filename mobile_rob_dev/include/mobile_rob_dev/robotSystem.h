//*********************************************************************
// Code developep by LARIS-UFSCar team.
// Team:
// Undergrad student: João Carlos Tonon Campi
// Master student: Leandro José Evilásio Campos
// Master student:José Ceron Neto
// Doctor student:Robson Rogério Dutra Pereira
// Prof. Roberto Santos Inoue
// Universidade Federal de São Carlos (UFSCar)
// Departamento de Computação (DC)
// Laboratory of Autonomous Robots and Intelligent Systems (LARIS)

// E-mail: rsinoue@ufscar.br

//**************************************************************************

#ifndef ROBOTSYSTEM_H_
#define ROBOTSYSTEM_H_


#include "ros/ros.h"
#include <iostream>
#include <fstream>
//#include <string>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>


#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

#include "mobile_rob_dev/robot.h"

#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/String.h"
// #include "sensor_msgs/NavSatFix.h"

// // #include "Eigen/Dense"
#include "tf/transform_datatypes.h"
#include <tf/transform_broadcaster.h>

using namespace std;


namespace ROBOT {

	class System {

	    ros::NodeHandle n;

        ros::Publisher odom_pub;
        ros::Publisher pose_pub;
        ros::Subscriber cmd_vel_sub;
		ros::Subscriber msg_sub;
		
		ros::Time current_time;
		ros::Time last_time;

		tf::TransformBroadcaster odom_broadcaster;
        std::string port_name;
		int serial_port;
		unsigned int baudrate;
		int num_bytes;
		double x, y, alpha, dt;
		char inChar;
		char inMessage[27];

		unsigned int action;

	  private:
	  

	  public:
		System();
		~System ();

		Robot robot;
		
        void loadTopics(ros::NodeHandle &n);
	    void loadSettings(ros::NodeHandle &n);
		void openSerial();
		void closeSerial();
		int getSerialPort();
		void setPortName(const string& portPathInput);
		void setBaudRate (const int& baudRateInput);
		void messageCallback (const std_msgs::String::ConstPtr& message);
	    void cmdVelCallback (const geometry_msgs::Twist::ConstPtr& cmdVel);
		void loop();


	};


} // namespace ROBOT


#endif /* MOBILE_ROB_DEV_INCLUDE_ROBOTSYSTEM_H_ */