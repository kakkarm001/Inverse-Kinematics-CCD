
#include <math.h>
#include "Arm.cpp"
#include <cstring>
#include "Vector.h"
#include <iostream>

using namespace std;


/**
 *
 * @author ferry
 */

    //jssc.SerialPort sPort = new jssc.SerialPort("/dev/tty.usbserial-12TC46G");

    int main() {
            Arm a;
            cout << "main is reached running program\n";
            a.reset();
            a.updateArm();

            /* gc.clearRect(0, 0, 600, 250); //clear rectangle?
             a.drawArm();
            AxServo ax = null ;
            try {
                sPort.openPort();
                ax = new AxServo((byte) 1, sPort);
            } catch (SerialPortException ex) {
                Logger.getLogger(RobotArm.class.getName()).log(Level.SEVERE, null, ex);
             }
            ax.setPosition(100);*/

            cout << "New position: ";  
            //create new position vector
            Vect newDest(120.0, 100.0, 0.0);

            cout <<  newDest.getX();  

            a.reset();
            a.updateArm();
            //move arm to new dest

           // a.moveEndpointToDest(new Vector3d((250 - t.getY()), (t.getX() - 300), 0));
             // gc.fillOval((t.getX()), (t.getY()), 6, 5);
            //gc.clearRect(0, 0, 600, 250);
            //a.drawArm();
            return 0;
          
        }

