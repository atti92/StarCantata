#ifndef IRRLICHTCORE_H
#define IRRLICHTCORE_H

#include "irrlicht.h"
#include "GUID.h"
#include "MyEventReceiver.h"
#include <iostream>


class IrrlichtCore
{
private:
    static bool isFullScreen_;
    static irr::video::E_DRIVER_TYPE videoMode_;
protected:
    static irr::IrrlichtDevice* device_;
    static irr::video::IVideoDriver* driver_;
    static irr::scene::ISceneManager* scenemgr_;
    static irr::gui::IGUIEnvironment* guienv_;
    static myEventReceiver receiver_;
public:
    IrrlichtCore();
    static void initIrrlicht();
    void irrlichtGfx();
    static myEventReceiver& getEventReceiver();
    static irr::IrrlichtDevice* getDevice();
    static irr::video::IVideoDriver* getDriver();
    static irr::scene::ISceneManager* getSceneManager();
    static irr::gui::IGUIEnvironment* getGuiEnvironment();
    static irr::u32 getTime();

};

#endif // IRRLICHT_CORE_H
