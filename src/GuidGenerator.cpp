#include "GuidGenerator.h"

using namespace irr;

core::array<GUID> GuidGenerator::nextGuid_ = core::array<GUID>();

GuidGenerator::GuidGenerator()
{
  init();
}

GuidGenerator::~GuidGenerator ()
{
  nextGuid_.clear ();
}

void GuidGenerator::init ()
{
  for (u32 i = 0; i < GUID_MAX_NUMBER; ++i) {
    nextGuid_.insert (GUID(0, Guid_High(i)), i);
  }
}

GUID GuidGenerator::generateGuid (Guid_High type)
{
  nextGuid_[type] += 1;
  return GUID(nextGuid_[type] - 1, type);
}


