/*
 * robotMain.cpp
 *
 * Created by: rsinoue on 20.Out.2022
 * Last Modified: rsinoue
 *
 * Description: This is the main function that forces the controller to run at X Hz, 
 *				where X is assigned in loop_rate(X).
 *
 * Serial port tutorial: https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
 */

#include "mobile_rob_dev/robotSystem.h"

int main(int argc, char **argv) // Argumentos em padrão: argc = número de parâmetros; **argv = endereço de cada parâmetro ?????
{
	// Initiate new ROS node named "mobile_rob_dev motion_estimation_node
	ros::init(argc, argv, "mobile_rob_dev");

	try {
		ROBOT::System node;  
		ros::Rate loop_rate(40); 

		while (ros::ok())
		{
			node.loop(); // Chama a função/método 
		    ros::spinOnce(); // Função para permitir executar o "node.control()";
		    loop_rate.sleep(); // Complementa o tempo restante para o período estipulado 10Hz
		}
		ros::spin();
	}
	// catch (const std::exception &e) {
	catch (const std::exception &e) {
		ROS_FATAL_STREAM("An error has occurred: " << e.what());
		exit(1);
	}

  	return 0;
}