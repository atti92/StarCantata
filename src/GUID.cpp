#include "GUID.h"

using namespace irr;

GUID::GUID(const u64 num, Guid_High type)
{
  guid_ = core::array<u8>(8);
  for (int i = 7; i >= 4; --i) {
	  guid_.insert(static_cast<u8>(static_cast<u32>(0xFF << ((i - 4) * 8)) & type));
  }
  for (int i = 3; i >= 0; --i) {
	  guid_.insert(static_cast<u8>(static_cast<u32>(0xFF << (i * 8)) & num));
  }
}

GUID::GUID(const GUID &theOther)
{
  for (int i = 0; i < 7; ++i) {
    guid_[i] = theOther.getByte (i);
  }
}

u32 GUID::getHigh () const
{
  return static_cast<u32>(guid_[4] + (guid_[5] << 8) + (guid_[6] << 16) + (guid_[7] << 24));
}

u32 GUID::getLow () const
{
  return static_cast<u32>(guid_[0] + (guid_[1] << 8) + (guid_[2] << 16) + (guid_[3] << 24));
}

const u8& GUID::getByte (const u8 &id) const
{
  if(id > 7)
    return guid_[id % 8];
  return guid_[id];
}

u8& GUID::operator [] (const u8& id)
{
  if(id > 7)
    return guid_[0];
  return guid_[id];
}

GUID::operator u64() const
{
  return static_cast<u64>(((u64)getHigh() << 32) + getLow());
}

GUID GUID::operator + (const GUID& num)
{
  GUID temp;
  u16 sum = 0;
  u8 remain = 0;
  for (int i = 0; i < 7; ++i) {
    sum = this->getByte(i) + num.getByte(i) + remain;  //add digits and the previous digits remainder
    remain = sum / 256;   //new remainder
    temp[i] = sum % 256;      //new digit
  }
  return temp;
}

GUID& GUID::operator =(const GUID& num)
{
  if(this != &num)
  {
    for (int i = 0; i < 7; ++i) {
      this->guid_[i] = num.getByte (i);
    }
  }
  return *this;
}

GUID& GUID::operator +=(const GUID& num)
{
  *this = *this + num;
  return *this;
}

void GUID::set(const u64 &num)
{
  *this = num;
}
