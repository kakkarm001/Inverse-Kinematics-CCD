#ifndef ArmSegment_GUARD
#define ArmSegment_GUARD
#include <string>

class ArmSegment{
  public:
    //variables
    double calculatedAngle;  // Degrees
    Vect endPoint;
    Vect mountPoint;
    double length;
    double angle; // degrees
    double maxAngle; // degrees

    //functions
    ArmSegment(double length, double angle, double maxAngle);
    void updateEndpoint(ArmSegment mountedOnArm);
    double toRadians(double angleInDegrees);
    double toDegrees(double radians);
    std::string toString();
    void setAngle(double d);
    void rotateMe(Vect targetEndpoint, Vect armEndpoint);
    std::string doubleToString(double value);
    private:
};

#endif