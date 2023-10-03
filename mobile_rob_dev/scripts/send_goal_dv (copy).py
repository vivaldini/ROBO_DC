#!/usr/bin/env python3

import rospy
# Brings in the SimpleActionClient
import actionlib
# Brings in the .action file and messages used by the move base action
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal

def movebase_client(x):
   # Create an action client called "move_base" with action definition file "MoveBaseAction"
    client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
 
   # Waits until the action server has started up and started listening for goals.
    client.wait_for_server()

   # Creates a new goal with the MoveBaseGoal constructor
    goal = MoveBaseGoal()
    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()
    
    if x==1:
        # Sala Roberto
        # goal.target_pose.pose.position.x = 27.6
        # goal.target_pose.pose.position.y = 24.7
        # goal.target_pose.pose.orientation.z = -1
        # goal.target_pose.pose.orientation.w = 0
        # Em frente ao elevador
        # goal.target_pose.pose.position.x = 23
        # goal.target_pose.pose.position.y = 16
        # goal.target_pose.pose.orientation.z = 1
        # goal.target_pose.pose.orientation.w = 0
        # Cozinha
        # goal.target_pose.pose.position.x = 59
        # goal.target_pose.pose.position.y = 13.7
        # goal.target_pose.pose.orientation.z = 1
        # goal.target_pose.pose.orientation.w = 0
        # Corredor Central
        # goal.target_pose.pose.position.x = 22
        # goal.target_pose.pose.position.y = 3
        # goal.target_pose.pose.orientation.z = 0.7071
        # goal.target_pose.pose.orientation.w = 0.7071
        # Proximo ao Lab00
        # goal.target_pose.pose.position.x = 6
        # goal.target_pose.pose.position.y = 0
        # goal.target_pose.pose.orientation.z = -1.0
        # goal.target_pose.pose.orientation.w = 0.0
        # Proximo ao Lab01
        # goal.target_pose.pose.position.x = 18
        # goal.target_pose.pose.position.y = 0
        # goal.target_pose.pose.orientation.z = 0.0
        # goal.target_pose.pose.orientation.w = 1.0
        # Corredor Central2
        goal.target_pose.pose.position.x = 22.666
        goal.target_pose.pose.position.y = 3.8
        goal.target_pose.pose.orientation.z = -0.7071
        goal.target_pose.pose.orientation.w = 0.7071
        # Pos Central
        # goal.target_pose.pose.position.x = 28
        # goal.target_pose.pose.position.y = 0
        # goal.target_pose.pose.orientation.z = -1.0
        # goal.target_pose.pose.orientation.w = 0.0        
        # Robovisor 00
        # goal.target_pose.pose.position.x = 5.8
        # goal.target_pose.pose.position.y = 0.5
        # goal.target_pose.pose.orientation.z = 0.0
        # goal.target_pose.pose.orientation.w = 1.0
        # Robovisor 01
        # goal.target_pose.pose.position.x = 9
        # goal.target_pose.pose.position.y = -2.55
        # goal.target_pose.pose.orientation.z = 0.7071
        # goal.target_pose.pose.orientation.w = 0.7071       
    elif x==2:
        # Em frente ao elevador
        # goal.target_pose.pose.position.x = 23
        # goal.target_pose.pose.position.y = 16
        # goal.target_pose.pose.orientation.z = 1
        # goal.target_pose.pose.orientation.w = 0
        # Cozinha
        # goal.target_pose.pose.position.x = 59
        # goal.target_pose.pose.position.y = 13.7
        # goal.target_pose.pose.orientation.z = 1
        # goal.target_pose.pose.orientation.w = 0
        # Corredor Central
        # goal.target_pose.pose.position.x = 22
        # goal.target_pose.pose.position.y = 3
        # goal.target_pose.pose.orientation.z = 0.7071
        # goal.target_pose.pose.orientation.w = 0.7071
        # Robovisor 00
        # goal.target_pose.pose.position.x = 5.8
        # goal.target_pose.pose.position.y = 0.5
        # goal.target_pose.pose.orientation.z = 0.0
        # goal.target_pose.pose.orientation.w = 1.0        
        # Robovisor 01
        # goal.target_pose.pose.position.x = 9
        # goal.target_pose.pose.position.y = -2.55
        # goal.target_pose.pose.orientation.z = 0.7071
        # goal.target_pose.pose.orientation.w = 0.7071
        # Corredor Central2
        # goal.target_pose.pose.position.x = 22.666
        # goal.target_pose.pose.position.y = 3.8
        # goal.target_pose.pose.orientation.z = -0.7071
        # goal.target_pose.pose.orientation.w = 0.7071
        # Pos Central
        goal.target_pose.pose.position.x = 28
        goal.target_pose.pose.position.y = 0
        goal.target_pose.pose.orientation.z = -1.0
        goal.target_pose.pose.orientation.w = 0.0               
    elif x==3:
        # Sala Roberto
        # goal.target_pose.pose.position.x = 27.6
        # goal.target_pose.pose.position.y = 24.7
        # goal.target_pose.pose.orientation.z = -1
        # goal.target_pose.pose.orientation.w = 0
        # Corredor Central2
        goal.target_pose.pose.position.x = 22.666
        goal.target_pose.pose.position.y = 3.8
        goal.target_pose.pose.orientation.z = -0.7071
        goal.target_pose.pose.orientation.w = 0.7071          
        # Pos Central
        # goal.target_pose.pose.position.x = 28
        # goal.target_pose.pose.position.y = 0
        # goal.target_pose.pose.orientation.z = -1.0
        # goal.target_pose.pose.orientation.w = 0.0          
    elif x==4:
        # Sala Vania
        # goal.target_pose.pose.position.x = 9.4
        # goal.target_pose.pose.position.y = 25.6
        # goal.target_pose.pose.orientation.z = 0
        # goal.target_pose.pose.orientation.w = 1
        # Corredor Central2
        # goal.target_pose.pose.position.x = 22.666
        # goal.target_pose.pose.position.y = 3.8
        # goal.target_pose.pose.orientation.z = -0.7071
        # goal.target_pose.pose.orientation.w = 0.7071
        # Proximo ao Lab01
        goal.target_pose.pose.position.x = 18
        goal.target_pose.pose.position.y = 0
        goal.target_pose.pose.orientation.z = 0.0
        goal.target_pose.pose.orientation.w = 1.0                 
    elif x==5:
        # Em frente ao elevador
        # goal.target_pose.pose.position.x = 23
        # goal.target_pose.pose.position.y = 16
        # goal.target_pose.pose.orientation.z = 1
        # goal.target_pose.pose.orientation.w = 0
        # Proximo ao Lab01
        # goal.target_pose.pose.position.x = 18
        # goal.target_pose.pose.position.y = 0
        # goal.target_pose.pose.orientation.z = 0.0
        # goal.target_pose.pose.orientation.w = 1.0
        # Corredor Central2
        goal.target_pose.pose.position.x = 22.666
        goal.target_pose.pose.position.y = 3.8
        goal.target_pose.pose.orientation.z = -0.7071
        goal.target_pose.pose.orientation.w = 0.7071        
    elif x==6:
        # Corredor Central
        # goal.target_pose.pose.position.x = 22
        # goal.target_pose.pose.position.y = 3
        # goal.target_pose.pose.orientation.z = 0.7071
        # goal.target_pose.pose.orientation.w = 0.7071
        # Corredor Central2
        # goal.target_pose.pose.position.x = 22.666
        # goal.target_pose.pose.position.y = 3.8
        # goal.target_pose.pose.orientation.z = -0.7071
        # goal.target_pose.pose.orientation.w = 0.7071
        # Pos Central
        goal.target_pose.pose.position.x = 28
        goal.target_pose.pose.position.y = 0
        goal.target_pose.pose.orientation.z = -1.0
        goal.target_pose.pose.orientation.w = 0.0  
    elif x==7:
        # Corredor Central
        # goal.target_pose.pose.position.x = 22
        # goal.target_pose.pose.position.y = 3
        # goal.target_pose.pose.orientation.z = 0.7071
        # goal.target_pose.pose.orientation.w = 0.7071
        # Corredor Central2
        goal.target_pose.pose.position.x = 22.666
        goal.target_pose.pose.position.y = 3.8
        goal.target_pose.pose.orientation.z = -0.7071
        goal.target_pose.pose.orientation.w = 0.7071
        # Pos Central
        # goal.target_pose.pose.position.x = 28
        # goal.target_pose.pose.position.y = 0
        # goal.target_pose.pose.orientation.z = -1.0
        # goal.target_pose.pose.orientation.w = 0.0          
    else:
        # Origem
        # goal.target_pose.pose.position.x = 1
        # goal.target_pose.pose.position.y = 0
        # goal.target_pose.pose.orientation.z = 0
        # goal.target_pose.pose.orientation.w = 1
        # Robovisor 00
        # goal.target_pose.pose.position.x = 5.8
        # goal.target_pose.pose.position.y = 0.5
        # goal.target_pose.pose.orientation.z = 0.0
        # goal.target_pose.pose.orientation.w = 1.0
        # Proximo ao Lab01
        goal.target_pose.pose.position.x = 18
        goal.target_pose.pose.position.y = 0
        goal.target_pose.pose.orientation.z = 0.0
        goal.target_pose.pose.orientation.w = 1.0                 

   # Sends the goal to the action server.
    client.send_goal(goal)
   # Waits for the server to finish performing the action.
    wait = client.wait_for_result()
   # If the result doesn't arrive, assume the Server is not available
    if not wait:
        rospy.logerr("Action server not available!")
        rospy.signal_shutdown("Action server not available!")
    else:
    # Result of executing the action
        return client.get_result()   

# If the python node is executed as main process (sourced directly)
if __name__ == '__main__':
    try:
       # Initializes a rospy node to let the SimpleActionClient publish and subscribe
        rospy.init_node('movebase_client_py')
        result = movebase_client(1)
        rospy.loginfo("1 Goal execution done!")
        rospy.sleep(2.5)
        result = movebase_client(2)
        rospy.loginfo("2 Goal execution done!")
        rospy.sleep(2.5)
        result = movebase_client(3)
        rospy.loginfo("3 Goal execution done!")
        rospy.sleep(2.5)
        result = movebase_client(4)
        rospy.loginfo("4 Goal execution done!")
        rospy.sleep(2.5)
        result = movebase_client(5)
        rospy.loginfo("5 Goal execution done!")
        rospy.sleep(2.5)
        result = movebase_client(6)
        rospy.loginfo("6 Goal execution done!")
        rospy.sleep(2.5)
        result = movebase_client(7)
        rospy.loginfo("7 Goal execution done!")
        rospy.sleep(2.5)                       
        result = movebase_client(8)
        rospy.loginfo("Home Goal execution done!")
        if result:
            rospy.loginfo("Goal execution done!"+str(result))
    except rospy.ROSInterruptException:
        rospy.loginfo("Navigation test finished.")