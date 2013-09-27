#ifndef GUIDGENERATOR_H
#define GUIDGENERATOR_H

#include "GUID.h"
#include "SpaceObject.h"

class GuidGenerator{
private:
  static irr::core::array<GUID> nextGuid_;
public:
  GuidGenerator();
  ~GuidGenerator();
  void init();
  static GUID generateGuid(Guid_High type);
};


#endif // GUIDGENERATOR_H
