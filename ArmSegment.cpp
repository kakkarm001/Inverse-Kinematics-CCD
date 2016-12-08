
#include <string>
#include <sstream>
#include <cmath>
#include "Vect.h"
#include "ArmSegment.h"

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

    // ArmSegment::ArmSegment() {
    // }

    ArmSegment::ArmSegment(double length, double angle, double maxAngle) {
        // endPoint = new Vector3d();
        // mountPoint = new Vector3d();
        

        this->angle = angle;
        this->length = length;
        this->maxAngle = maxAngle;
    }

    void ArmSegment::updateEndpoint(ArmSegment mountedOnArm) {
        calculatedAngle = mountedOnArm.calculatedAngle + angle;
        // NOTE: Angle is 90 degrees shifted counter clock wise.
        endPoint.x = mountedOnArm.endPoint.x + length * cos(toRadians(calculatedAngle));
        endPoint.y = mountedOnArm.endPoint.y + length * sin(toRadians(calculatedAngle));

        mountPoint.x = mountedOnArm.endPoint.x;
        mountPoint.y = mountedOnArm.endPoint.y;
        mountPoint.z = mountedOnArm.endPoint.z;
    }

    double ArmSegment::toRadians(double angleInDegrees){
         return (angleInDegrees * pi)  / 180; //TODO: maybe turn into double
    }

    double ArmSegment::toDegrees(double radians) {
        return radians * (180.0 / pi);
    }

    // void drawSegment(GraphicsContext gc) {
    //     gc.strokeLine(300 + mountPoint.y, 250 - mountPoint.x, 300 + endPoint.y, 250 - endPoint.x);
    //     gc.fillOval(297 + endPoint.y, 247 - endPoint.x, 6, 5);
    // }

    
    std::string ArmSegment::toString() {
        return "Arm mountpoint:" + doubleToString(mountPoint.x) + "," +
        doubleToString(mountPoint.y) + 
        " endpoint:" + doubleToString(endPoint.x) + "," + doubleToString(endPoint.y);
       // return "I coudnt fix this yet so I return this random string";
    }

    void ArmSegment::setAngle(double d) {
        this->angle = d;
    }

    
  /**
 * Rotate current segment in direction of the endpoint. 
 * @param  targetEndpoint armEndpoint          
 * @return void.
 */
    void ArmSegment::rotateMe(Vect targetEndpoint, Vect armEndpoint) {
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

        cross = r.cross(p); //doublecheck if r or p should be used or if it dousnt matter

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

    std::string ArmSegment::doubleToString(double value){
        std::ostringstream strs;
        strs << value;
        std::string str = strs.str();
        return str;
    }