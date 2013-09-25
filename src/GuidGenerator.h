#ifndef GUIDGENERATOR_H
#define GUIDGENERATOR_H

#include "GUID.h"
#include "SpaceObject.h"

class GuidGenerator{
private:
  static GUID nextGuid_;
  static array<GUID> nextGuids_;
public:
  GuidGenerator();
  ~GuidGenerator();
  void init();
  static GUID generateGuid();
};

#endif // GUIDGENERATOR_H
