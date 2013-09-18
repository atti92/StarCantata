#ifndef GLOBALS_H
#define GLOBALS_H
#include "IrrlichtGfx.h"

class Globals{
private:
    static IrrlichtGfx* irrlichtGfx_;
public:
    Globals();
    static IrrlichtGfx* getIrrlichtGfx();
};

#endif // GLOBALS_H
