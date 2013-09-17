#ifndef Controls_H
#define Controls_H

#include "irrlicht.h"

using namespace irr;

//Recording Events
class myEventReceiver : public IEventReceiver
{
private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
public:
	virtual bool OnEvent(const SEvent& event);
    virtual bool IsKeyDown(EKEY_CODE keycode) const;
	void changeKey(EKEY_CODE keycode);
	myEventReceiver();
};

#endif
