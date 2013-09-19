#ifndef GLOBALS_H
#define GLOBALS_H

#include "IrrlichtGfx.h"
#include "User.h"

#define sUser Globals::getUser()
#define sIGfx Globals::getIrrlichtGfx()

class Globals{
private:
  static IrrlichtGfx* irrlichtGfx_;
  static User* user_;
public:
  Globals();
  static IrrlichtGfx* getIrrlichtGfx();
  static User* getUser();
  void init();
  void setIrrlichtGfx();
};

#endif // GLOBALS_H
