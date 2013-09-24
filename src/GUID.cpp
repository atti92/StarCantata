#include "GUID.h"

using namespace irr;

GUID::GUID(u64 num)
{
  guid_ = num;
}

u32 GUID::getHigh ()
{
  u32 temp = guid_[4] + (guid_[5] << 8) + (guid_[6] << 16) + (guid_[7] << 24);
  return temp;
}

u32 GUID::getLow ()
{
  u32 temp = guid_[0] + (guid_[1] << 8) + (guid_[2] << 16) + (guid_[3] << 24);
  return temp;
}

u8 GUID::getByte (u8 id)
{
  if(id > 7)
    return 0;
  return guid_[id];
}

u8 GUID::operator [] (u8 id)
{
  if(id > 7)
    return guid_[0];
  return guid_[id];
}

GUID::operator u64()
{
  //u64 temp = getHigh() << 32 + getLow();
  return static_cast<u64>(guid_);
}

GUID& GUID::operator + (u64 num)
{
  guid_ += num;
}

GUID& GUID::operator + (s64 num)
{
  guid_ += num;
}

GUID& GUID::operator + (GUID num)
{
  guid_ += static_cast<u64>(num);
}

void GUID::set(u64 num)
{
  guid_ = num;
}
