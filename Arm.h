#ifndef ARM_GUARD
#define ARM_GUARD

#include <string>
#include <vector>
#include "Vect.h"
#include "ArmSegment.h"



class Arm {
         
        public:
            std::vector<ArmSegment> segments;
            Vect endPoint;

            Arm();
            void reset();
            std::string toString();
            void updateArm();
            void setArmAngle(double d, int armIndex);
            void moveEndpointToDest(Vect ep);

    };    

#endif