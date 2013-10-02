#include "Globals.h"

//static member variables:

IrrlichtGfx* Globals::irrlichtGfx_ = 0;
User* Globals::user_ = 0;

Globals::Globals()
{

}

Globals::~Globals ()
{

}

void Globals::init ()
{
  srand ((unsigned int)time(NULL) );
  if(this->irrlichtGfx_ == 0)
  {
    this->irrlichtGfx_ = new IrrlichtGfx();
    irrlichtGfx_->initIrrlicht ();
  }
  if(this->user_ == 0)
    this->user_ = new User();
}

IrrlichtGfx* Globals::getIrrlichtGfx()
{
  return Globals::irrlichtGfx_;
}

User* Globals::getUser ()
{
  return Globals::user_;
}

void Globals::setIrrlichtGfx (IrrlichtGfx* irrlichtGfx)
{
  irrlichtGfx_ = irrlichtGfx;
}

void Globals::setUser (User* user)
{
  user_ = user;
}

