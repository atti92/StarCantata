#include "time.h"
#include "Gui.h"
#include "Globals.h"
#include "MapLoader.h"
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
  //srand ((unsigned int)time(NULL) ); //initialize random seed
  Globals globals;
  globals.init();
  MapLoader mapLoader;
  mapLoader.load ("maps/testmap.xml");
  Map* baseMap = mapLoader.getMap ();
  sIGfx->initIrrlicht ();
  sIGfx->getObjectMgr ()->addMap (baseMap);
  SpaceShip testShip = SpaceShip(0, vector3df(230,0,0));
  sIGfx->getObjectMgr ()->addObject (&testShip);
  sUser->assignShip (&testShip);
  sIGfx->getGui ()->createChatWindow ();
  while(sIGfx->getDevice ()->run ())
    {
      sIGfx->getDriver ()->beginScene(true, true, SColor(255,100,101,140));
      sIGfx->updateTimer ();
      sIGfx->drawAll (baseMap);
      sIGfx->getObjectMgr ()->updateAll();
      sIGfx->getDriver ()->endScene ();
    }

  sIGfx->getDevice ()->drop ();


  return 0;
}
