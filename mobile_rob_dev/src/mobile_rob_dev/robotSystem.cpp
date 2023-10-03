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

//**************************************************************************/

#include "mobile_rob_dev/robotSystem.h"

namespace ROBOT {

	// CONSTRUCTOR
	System::System() {

		cout << "Starting Mobile Robot Node" << endl;
		current_time  = ros::Time::now();
		last_time = ros::Time::now();
		port_name = "/dev/ttyACM0";
		baudrate = 115200;
		action = 0;

		loadTopics(n);
		loadSettings(n);

		openSerial();

	}

	// DESTRUCTOR
	System::~System () {
		closeSerial();
	}


	void System::loadTopics(ros::NodeHandle &n) {
		odom_pub 		 = n.advertise<nav_msgs::Odometry>("/odom",1);
		pose_pub 		 = n.advertise<geometry_msgs::Pose2D>("/pose2d",1);
		cmd_vel_sub		 = n.subscribe<geometry_msgs::Twist>("/robot/cmd_vel", 1, &System::cmdVelCallback, this);
		msg_sub          = n.subscribe<std_msgs::String>("/robot/message", 1, &System::messageCallback, this);
 	}

	void System::loadSettings(ros::NodeHandle &n) {

		cout << "+----------------------------------+" <<endl;
		cout << "|        Loading ROS PARAMS        |" <<endl;
		cout << "+----------------------------------+" <<endl;
		
		// Loading Serial Port Path
		string portName;
		if(n.getParam("/robot/portName", portName)){
			setPortName(portName);			
			cout << " - Serial Port Name = " << portName << endl;
		}

		// Loading Serial Baud Rate
		int baudRate;
		if(n.getParam("/robot/baudRate", baudRate)){
			setBaudRate(baudRate);
			cout << " - Serial Port Baudrate = " << baudRate << endl;
		}

		// Loading Robot Wheel Radius (r)
		double wheelRadius;
		if (n.getParam("/robot/wheelRadius",wheelRadius)){
			robot.setWheelRadius(wheelRadius);
			cout << " - Wheel Radius = " << robot.getWheelRadius() << endl;
		}

		// Loading Robot Plataform Radius (b)
		double robotRadius;
		if(n.getParam("/robot/robotRadius",robotRadius)){
			robot.setRobotRadius(robotRadius);
			cout << " - Robot Radius = " << robot.getRobotRadius() << endl;
		}
		cout << "====================================" <<endl;
	}

	void System::openSerial() {
		//https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
		//serial_port = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY);
		serial_port = open(port_name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
		//cout << port_name.c_str() << endl;
		struct termios tty;

		// Read in existing settings, and handle any error
		if(tcgetattr(serial_port, &tty) != 0) {
			printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
			//return 1;
		}
		//
		// Set in/out baud rate to be 9600int& serial_port
		//cfsetispeed(&tty, B115200);
		//cfsetospeed(&tty, B115200);

		cfsetispeed(&tty, baudrate);
		cfsetospeed(&tty, baudrate);
	}

	void System::closeSerial() {
		close(serial_port);

	}

	int System::getSerialPort() {
		return serial_port;
	}

	void System::setPortName(const string &portPathInput){
		string DEFAULT_PORT = "/dev/ttyACM0";

		if (portPathInput.compare(" ") != 0){
			port_name = portPathInput;
		}
		else {
			port_name = DEFAULT_PORT;
		}
		
	}

	void System::setBaudRate(const int& baudRateInput){
		int DEFAULT_BAUDRATE = 115200;

		if (baudRateInput < 0){
			baudrate = DEFAULT_BAUDRATE;
		}else{
			baudrate = baudRateInput;
		}
	}

	void System::messageCallback (const std_msgs::String::ConstPtr& message) {
			char messageBreak[] = "break";
			char messageStart[] = "start";
			char msg[50];
			int n;
			//cout << message->data.c_str() << endl;
			if (strcmp(message->data.c_str(),messageBreak) ==0) {
				action = 1;
				n = sprintf(msg,"$%8.3f,%8.3f,%d#",0.0 ,0.0,action); 
				write(serial_port, msg, sizeof(msg));
				cout << "Break\n\r" << endl;

			}
			else if (strcmp(message->data.c_str(),messageStart) ==0 ) {
				action = 0;
				cout << "Start\n\r" << endl;
			}
			

	}

	void System::cmdVelCallback (const geometry_msgs::Twist::ConstPtr& cmdVel) {

		double dx, dy, dalpha, dthR, dthL, dthR_RPM, dthL_RPM;
		double r, b;

		char msg[50];
		int n;

		r = robot.getWheelRadius();
		b = robot.getRobotRadius();

		dx = cmdVel->linear.x;
		dy = cmdVel->linear.y;
		dalpha = cmdVel->angular.z;

		dthR = (dx+b*dalpha)/r;
		dthL = (dx-b*dalpha)/r;

		dthR_RPM = dthR/(M_PI)*30;
		dthL_RPM = dthL/(M_PI)*30;

		
		n = sprintf(msg,"$%8.3f,%8.3f,%d#",dthL_RPM ,dthR_RPM,action); 

		// cout << "msg: " << msg << endl;

		write(serial_port, msg, sizeof(msg));

	}
	
	void System::loop() {
		current_time = ros::Time::now();
		dt = (current_time-last_time).toSec();
		robot.setRobotdt(dt);

		//cout << "dt: " << dt<< endl;

		// Read bytes. The behaviour of read() (e.g. does it block?,
		// how long does it block for?) depends on the configuration
		// settings above, specifically VMIN and VTIME
		num_bytes = read(serial_port, &inChar, sizeof(inChar));
		//num_bytes = read(serial_port2, &inChar, sizeof(inChar));
		// cout << "Teste" << endl;
		// cout << "num_bytes: " << num_bytes << endl;
		// cout << "inChar: " << inChar << endl;
		if (inChar == '#') {
			// cout << "Ok1" << endl;
			// cout << inChar << endl;
			//write(node.getSerialPort(), &inChar, sizeof(inChar));
			num_bytes = read(serial_port, &inMessage, sizeof(inMessage));
			tcflush(serial_port,TCIFLUSH);
			if (inMessage[26] == '$') {
				// cout << inMessage << endl;
				// cout << "Ok2" << endl;

				x = double(atof(&inMessage[0]));
				y = double(atof(&inMessage[9]));
				alpha = robot.normalizeAngle(double(atof(&inMessage[18]))* (M_PI/30),-M_PI);

				// cout << "x:" << x << endl;
				// cout << "y:" << y << endl;
				// cout << "alpha:" << alpha << endl;
			}
			else{
				tcflush(serial_port,TCIFLUSH);
			}


		}
		robot.setRobotPosition(x,y,alpha);

		//since all odometry is 6DOF we'll need a quaternion created from yaw
		geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(alpha);

		//first, we'll publish the transform over tf
		geometry_msgs::TransformStamped odom_trans;
		odom_trans.header.stamp = current_time;
		odom_trans.header.frame_id = "odom";
		odom_trans.child_frame_id = "base_link";
  
		odom_trans.transform.translation.x = x;
		odom_trans.transform.translation.y = y;
		odom_trans.transform.translation.z = 0.0;
		odom_trans.transform.rotation = odom_quat;

		//send the transform
		odom_broadcaster.sendTransform(odom_trans);

		//next, we'll publish the odometry message over ROS
		nav_msgs::Odometry odom;
		odom.header.stamp = current_time;
		odom.header.frame_id = "odom";

		//set the position
		odom.pose.pose.position.x = x;
		odom.pose.pose.position.y = y;
		odom.pose.pose.position.z = 0.0;
		odom.pose.pose.orientation = odom_quat;
		//set the velocity
		// odom.child_frame_id = "odom";
		odom.child_frame_id = "base_link";
		odom.twist.twist.linear.x = robot.getRobotdx();
		odom.twist.twist.linear.y = robot.getRobotdy();
		odom.twist.twist.angular.z = robot.getRobotdalpha();

		//publish the message
		odom_pub.publish(odom);

		geometry_msgs::Pose2D pose;

		pose.x = x;
		pose.y = y;
		pose.theta = alpha;

		pose_pub.publish(pose);

		last_time = current_time;

	}
	
} // namespace ROBOT