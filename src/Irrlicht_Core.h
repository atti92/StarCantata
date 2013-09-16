#ifndef IRRLICHT_CORE_H
#define IRRLICHT_CORE_H

#include "irrlicht.h"
#include <iostream>

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;
using namespace gui;
using namespace io;
using namespace std;

class Irrlicht_Core
{
private:
    bool fullscreen;
    E_DRIVER_TYPE VideoMode;

public:
    Irrlicht_Core();
    void init_Irrlicht();
    void GFX_Irrlicht();
    IrrlichtDevice *device;
    IVideoDriver *driver;
    ISceneManager *scenemgr;
    IGUIEnvironment *guienv;

};

#endif // IRRLICHT_CORE_H
