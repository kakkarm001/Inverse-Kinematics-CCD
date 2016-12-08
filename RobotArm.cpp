
#include <math.h>
#include "Arm.h"
#include <cstring>
#include "Vect.h"
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

            //create new position vector
            Vect newDest(80.0, 100.0, 0.0);

            cout << "\n BEFORE POSITION: ";  
            // cout <<  newDest.getX();  
            // cout <<  newDest.getY();  
            // cout <<  newDest.getZ();  
             cout <<  a.toString()+"\n";
            

            a.reset();
            a.updateArm();
            //move arm to new dest

            a.moveEndpointToDest(newDest);

            cout << "\n AFTER POSITION: ";  
            cout <<  a.toString()+"\n";

             // gc.fillOval((t.getX()), (t.getY()), 6, 5);
            //gc.clearRect(0, 0, 600, 250);
            //a.drawArm();
            return 0;
          
        }

