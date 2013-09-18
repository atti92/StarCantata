#ifndef GUIDGENERATOR_H
#define GUIDGENERATOR_H
#include "GUID.h"
#include "SpaceObject.h"

class GuidGenerator{
private:
    static GUID nextGuid_;
public:
    GuidGenerator();
    static GUID generateGuid();
};

#endif // GUIDGENERATOR_H
