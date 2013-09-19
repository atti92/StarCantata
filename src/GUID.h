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
  irr::u64 guid;
  GUID(irr::u64 num = 0);
  irr::u32 getLow();
  irr::u32 getHigh();
  irr::u8 getByte(irr::u8 id);
  irr::u8 operator [] (irr::u8 id);
  operator irr::u64();
}

#endif // GUID_H
