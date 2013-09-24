#ifndef GUID_H
#define GUID_H

#include "irrlicht.h"

enum GUID_HIGH{
  GUID_PLAYER = 0,
  GUID_SPACESHIP_AI = 1,
  GUID_SPACESHIP = 2,
  GUID_STAR = 100,
  GUID_PLANET = 101,
  GUID_MOON = 102,
  GUID_ASTEROID = 103,
  GUID_GARBAGE = 104,
  GUID_LOOTOBJECT = 200,
  GUID_TRIGGER = 1000
};

class GUID
{
private:
  irr::array<irr::u8> guid_;
public:
  GUID(const irr::u64& num = 0);
  void set(const irr::u64& num = 0);
  irr::u32 getLow() const;
  irr::u32 getHigh() const;
  irr::u8 getByte(const irr::u8& id) const;
  irr::u8& operator [] (const irr::u8& id);
  operator irr::u64() const;
  GUID& operator + (const irr::s64& num);
  GUID& operator + (const irr::u64& num);
  GUID& operator + (const GUID& num);
}

#endif // GUID_H
