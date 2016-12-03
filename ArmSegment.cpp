
#include <cstring>
#include <cmath>
#include "Vector.h"

using namespace std;

#define pi 3.14159265359


/**
 *
 * @author Manish
 *
 * For 3D you must think of a sphere, rather than just a circle. Let r = radius,
 * t = angle on x-y plane, & p = angle off of z-axis. Then you get: x = r *
 * sin(p) * cos(t) y = r * sin(p) * sin(t) z = r * cos(p)
 *
 * If you already have x,y,z and want to switch it back, this is the conversion:
 * r = sqrt(x*x + y*y + z*z) t = arctan(y/x) p = arccos(z/r) For computing p,
 * it's easier to compute r first, then use it as the denominator (assuming ![x
 * = y = z = 0]).  *
 */

    class ArmSegment{
      public:
        double calculatedAngle;  // Degrees
        Vect endPoint;
        Vect mountPoint;

        double lenght;
        double angle; // degrees
        double maxAngle; // degrees
    };

    // ArmSegment::ArmSegment() {
    // }

    ArmSegment::ArmSegment(double length, double angle, double maxAngle) {
        // endPoint = new Vector3d();
        // mountPoint = new Vector3d();
        

        this.angle = angle;
        this.lenght = length;
        this.maxAngle = maxAngle;
    }

    void updateEndpoint(ArmSegment mountedOnArm) {
        calculatedAngle = mountedOnArm.calculatedAngle + angle;
        // NOTE: Angle is 90 degrees shifted counter clock wise.
        endPoint.x = mountedOnArm.endPoint.x + lenght * cos(toRadians(calculatedAngle));
        endPoint.y = mountedOnArm.endPoint.y + lenght * sin(toRadians(calculatedAngle));

        mountPoint.x = mountedOnArm.endPoint.x;
        mountPoint.y = mountedOnArm.endPoint.y;
        mountPoint.z = mountedOnArm.endPoint.z;
    }

    double toRadians(angleInDegrees){
         reuturn (degrees * pi)  / 180; //TODO: maybe turn into double
    }


    // void drawSegment(GraphicsContext gc) {
    //     gc.strokeLine(300 + mountPoint.y, 250 - mountPoint.x, 300 + endPoint.y, 250 - endPoint.x);
    //     gc.fillOval(297 + endPoint.y, 247 - endPoint.x, 6, 5);
    // }

    
    String toString() {
        return "Arm mountpoint:" + mountPoint.x + "," + mountPoint.y + " endpoint:" + endPoint.x + "," + endPoint.y;
    }

    void setAngle(double d) {
        this.angle = d;
    }

    
  /**
 * Rotate current segment in direction of the endpoint. 
 * @param  targetEndpoint armEndpoint          
 * @return void.
 */
    void rotateMe(Vect targetEndpoint, Vect armEndpoint) {
        Vect r;
        Vect p;
        Vect cross;

        r.x = targetEndpoint.x - mountPoint.x;
        r.y = targetEndpoint.y - mountPoint.y;
        r.z = targetEndpoint.z - mountPoint.z;

        p.x = armEndpoint.x - mountPoint.x;
        p.y = armEndpoint.y - mountPoint.y;
        p.z = armEndpoint.z - mountPoint.z;

        double adiff = toDegrees(p.angle(r));

        cross.cross(r, p);
        // Which way to rotate  3d trick
        if ( adiff < 10 ) {
            adiff /= 1 ;
        }
        else if ( adiff < 30 ) {
            adiff /= 2 ;
        }
        else if ( adiff < 60 ) {
            adiff /= 3 ;
        }
        else {
            adiff /= 4 ;
        }
        
        if (cross.z > 0) {
            angle = angle - adiff;
        }
        else {
            angle = angle + adiff;            
        }
        if ( angle > maxAngle ) angle = maxAngle ; 
        if ( angle < -maxAngle ) angle = -maxAngle ; 
    }

