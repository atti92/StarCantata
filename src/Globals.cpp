#include "Globals.h"

Globals::Globals()
{
  init();
}

void Globals::init ()
{
  if(this->irrlichtGfx_ == 0)
    irrlichtGfx_ = new IrrlichtGfx();
  if(this->user_ == 0)
    user_ = new User();
}

IrrlichtGfx* Globals::getIrrlichtGfx()
{
  return irrlichtGfx_;
}

User* Globals::getUser ()
{
  return user_;
}

void Globals::setIrrlichtGfx (IrrlichtGfx* irrlichtGfx)
{
  irrlichtGfx_ = irrlichtGfx;
}

void Globals::setUser (User* user)
{
  user_ = user;
}

