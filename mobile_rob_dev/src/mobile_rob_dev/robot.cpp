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


#include "mobile_rob_dev/robot.h"

namespace ROBOT {

	// CONSTRUCTOR
	Robot::Robot() {

		r= 1.0*0.065;  // wheel diamenter 13cm  # 1.2 gain to adjust
		b= 0.26;   // robot diamenter 52 cm

		x = 0;
		y = 0;
		alpha = 0;

		dt = 0.01;

		xo = 0.0;
		yo = 0.0;
		alphao = 0.0;

		x_offset = 0.0;
		y_offset = 0.0;
		alpha_offset = 0.0;

		dx = 0.0;
		dy = 0.0;
		dalpha = 0.0;
		dthR = 0.0;	
		dthL = 0.0;
		distFront = 250.0;
		distBack = 250.0;
		dist_L = 0.0;
		dist_R = 0.0;
		distC = 0.0;
		x_previous = 0.0;
		y_previous = 0.0;
		alpha_previous = 0.0;
	}
	
	void Robot::setWheelRadius(double& wheelRaidusInput){
		r = wheelRaidusInput*1.0;
	}

	void Robot::setRobotRadius(double& robotRadiusInput){
		b = robotRadiusInput*1.0;
	}

	double Robot::getWheelRadius() {
		return r;
	}

	double Robot::getRobotRadius() {
		return b;
	}

	double Robot::getRobotdx(){
		return dx;
	}
	double Robot::getRobotdy(){
		return dy;
	}
	double Robot::getRobotdalpha(){
		return dalpha;
	}
	double Robot::normalizeAngle(double ang, double low) {
		return ang -2*M_PI*floor((ang-low)/(2*M_PI));
	}

	double Robot::lowPassFilter(double alpha, double x, double xpf) {
		return alpha*xpf + (1-alpha)*x;
	}
	void Robot::setRobotdt(double & dtValue) {
		dt = dtValue;
	}

	void Robot::setRobotPosition(double& xValue, double& yValue, double& alphaValue) {
		x = xValue;
		y = yValue;
		alpha = alphaValue;

		double dx_raw, dy_raw, dalpha_raw;

		dx_raw=(x-x_previous)/dt;
		dy_raw=(y-y_previous)/dt;
		dalpha_raw = normalizeAngle((alpha-alpha_previous),-M_PI)/dt;

		dx = lowPassFilter(0.7,dx_raw,dx);
		dy = lowPassFilter(0.7,dy_raw,dy);
		dalpha = lowPassFilter(0.7,dalpha_raw,dalpha);

		x_previous = x;
		y_previous = y;
		alpha_previous = alpha;
	}


} // namespace ROBOT
