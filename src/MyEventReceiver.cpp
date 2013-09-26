#include "MyEventReceiver.h"
//Recording Events

using namespace irr;

bool MyEventReceiver::OnEvent(const SEvent& event)  //When an event occurs
{
  if(event.EventType == irr::EET_KEY_INPUT_EVENT) //when a key is pressed
  {
    isKeyDown_[event.KeyInput.Key] = event.KeyInput.PressedDown; //change the variable entry.
  }
  return false;
}

void MyEventReceiver::changeKey(EKEY_CODE keycode)
{
  isKeyDown_[keycode] = !isKeyDown_[keycode];
}

const bool MyEventReceiver::isKeyDown (EKEY_CODE keycode)
{
  return isKeyDown_[keycode];
}
MyEventReceiver::MyEventReceiver()  //Initialize
{
  for(u32 i = 0; i < KEY_KEY_CODES_COUNT; i++)
  {
    isKeyDown_[i] = false;
  }
}
