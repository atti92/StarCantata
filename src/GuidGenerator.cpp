#include "GuidGenerator.h"

GuidGenerator::GuidGenerator()
{

}

void GuidGenerator::init ()
{
  Guid_High
  nextGuid_ = 0;
}

GUID GuidGenerator::generateGuid ()
{
  return GUID(nextGuid_);
}


