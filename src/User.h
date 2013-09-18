#ifndef USER_H
#define USER_H

#include "SpaceShip.h"
#include "Controls.h"  // For the movement control
#include "Display.h"
#include "Gui.h"
#include <string>

class GUI;
//DEPRECATED
class User
{
protected:
    SpaceShip *myShip;
    Display *myDisplay;
    Camera *myCamera;
	f32 dtime;
	u32 time;
    GUI *gui;
public:
	User();		//Constructor
	void setGUI(GUI& g){this->gui = &g;}
    void assignShip(SpaceShip *target){ myShip = target;}
	void refreshCamera();	//Camera movement
    Display& display(){return *myDisplay;}		//getter for the display reference
	void keys(myEventReceiver& receiver);	//User input
	const bool checkCommand(const stringc text);
    SpaceShip& getMyShip(){return *myShip;}						//getter for the player's ship reference
	const u32 getTime(){return time;}							//current system time
	const f32 getDeltaTime(){return dtime;}						//delta time between frames
	void timings();												//calculate delta time
	static const vector3df rotToMovVector(const vector3df rotation);	//Vector conversion: translates the ship's rotation to the facing direction vector
};

#endif
