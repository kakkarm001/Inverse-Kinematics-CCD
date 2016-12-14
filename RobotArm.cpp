
#include <math.h>
#include "Arm.h"
#include <cstring>
#include "Vect.h"
#include <iostream>

using namespace std;


/**
 *
 * @author manish, inspired by Ferrie
 */

    //jssc.SerialPort sPort = new jssc.SerialPort("/dev/tty.usbserial-12TC46G");

    int main() {
            Arm a;
            cout << "main is reached running program\n";

            //create new position vector
            Vect newDest(30.0, 100.0, 30.0);

            a.reset();
            a.updateArm();
            //move arm to new dest

            a.moveEndpointToDest(newDest);

            cout << "\n AFTER POSITION: ";  
            cout <<  a.toString()+"\n";
            
            return 0;
          
        }

