#include "Controls.h"
//Recording Events

bool myEventReceiver::OnEvent(const SEvent& event)  //When an event occurs
{
    if(event.EventType == irr::EET_KEY_INPUT_EVENT) //when a key is pressed
    {
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown; //change the variable entry.
    }
    return false;
}

void myEventReceiver::changeKey(EKEY_CODE keycode)
{
    KeyIsDown[keycode] = !KeyIsDown[keycode];
}

const bool myEventReceiver::IsKeyDown(EKEY_CODE keycode) const
{
    return KeyIsDown[keycode];
}
myEventReceiver::myEventReceiver()  //Initialize
{
    for(u32 i = 0; i < KEY_KEY_CODES_COUNT; i++)
    {
        KeyIsDown[i] = false;

    }
}
