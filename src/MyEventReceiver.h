#ifndef Controls_H
#define Controls_H

#include "irrlicht.h"

//Recording Events
class MyEventReceiver : public irr::IEventReceiver
{
private:
  bool isKeyDown_[irr::KEY_KEY_CODES_COUNT];
public:
  virtual bool OnEvent (const irr::SEvent& event);
  virtual bool isKeyDown(irr::EKEY_CODE keycode);
  void changeKey(irr::EKEY_CODE keycode);
  MyEventReceiver();
};

#endif
