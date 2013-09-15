#include "XMLhandler.h"
#include "time.h"
#include "Gui.h"
#include <iostream>
#include <fstream>

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.a")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif



using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;



int main()
{
	srand ((unsigned int)time(NULL) ); //initialize random seed
	User user;
	Display* display = &user.display();
    GUI overlayGui = GUI(user);
    user.setGUI(overlayGui);
	XMLhandler xmlhandler;
	xmlhandler.loadMap("maps/testmap.xml", user);
	
    SpaceShip testship = SpaceShip(0, *display, vector3df(230,0,0));
	display->addObject(&testship);
	user.assignShip(&testship);
    overlayGui.createChatWindow();
	while(display->device->run())
    {
		user.timings();
		user.keys(display->receiver);
		display->refreshObjects(user.getDeltaTime(), user.getTime());
		user.refreshCamera();
		display->Driver()->beginScene(true, true, SColor(0,0,0,0));

        display->Smgr()->drawAll();
        display->Guienv()->drawAll();

        display->Driver()->endScene();
	}
	display->Device()->drop();


    return 0;
}
