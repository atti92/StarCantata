#ifndef Controls_H
#define Controls_H

#include "irrlicht.h"

using namespace irr;

//Recording Events
class MyEventReceiver : public IEventReceiver
{
private:
    bool isKeyDown_[KEY_KEY_CODES_COUNT];
public:
    virtual bool OnEvent (const SEvent& event);
    virtual bool isKeyDown(EKEY_CODE keycode) const;
	void changeKey(EKEY_CODE keycode);
    MyEventReceiver();
};

#endif
