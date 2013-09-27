#ifndef GUID_H
#define GUID_H

#include "irrlicht.h"

enum Guid_High{
  GUID_PLAYER = 0,
  GUID_SPACESHIP_AI = 1,
  GUID_SPACESHIP = 2,
  GUID_STAR = 3,
  GUID_PLANET = 4,
  GUID_MOON = 5,
  GUID_ASTEROID = 6,
  GUID_GARBAGE = 8,
  GUID_LOOTOBJECT = 9,
  GUID_TRIGGER = 10,
  GUID_MAX_NUMBER = 11,
  GUID_UNK = 255
};

class GUID
{
private:
  irr::core::array<irr::u8> guid_;
public:
  GUID(const irr::u64 num = 0, Guid_High type = GUID_UNK);
  GUID(const GUID& theOther);
  void set(const irr::u64& num = 0);
  irr::u32 getLow() const;
  irr::u32 getHigh() const;
  const irr::u8& getByte(const irr::u8& id) const;
  irr::u8& operator [] (const irr::u8& id);
  operator irr::u64() const;
  GUID operator+ (const GUID& num);
  GUID& operator= (const GUID& num);
  GUID& operator+= (const GUID& num);
};

#endif // GUID_H
