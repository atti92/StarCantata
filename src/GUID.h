#ifndef GUID_H
#define GUID_H
#include "irrlicht.h"

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
