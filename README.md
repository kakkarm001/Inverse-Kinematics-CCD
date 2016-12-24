# Inverse Kinematics CCD
Inverse Kinematics implementation using CCD method in c++.

The result of this program gives the angles that the robot should have to go to a certain position. 
To compile this project: "g++ RobotArm.cpp Arm.cpp ArmSegment.cpp Vect.cpp -o RobotArm"
To run: "./RobotArm"

Result should be something like this at the end:

CALCULADEDANGLE 
0.184472
1.18447
91.1845

To change the target endpoint you need change 
"Vect newDest(y, x, z);" in RobotArm.cpp and recompile.
This is hardcoded so that people can easily replace it with their own destination input stream.


