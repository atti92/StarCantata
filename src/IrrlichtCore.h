#ifndef IRRLICHTCORE_H
#define IRRLICHTCORE_H

#include "irrlicht.h"
#include "GUID.h"
#include "Controls.h"
//#include "Singleton.h"
#include <iostream>


class IrrlichtCore
{
private:
    bool isFullScreen_;
    irr::video::E_DRIVER_TYPE videoMode_;
protected:
    irr::IrrlichtDevice* device_;
    irr::video::IVideoDriver* driver_;
    irr::scene::ISceneManager* scenemgr_;
    irr::gui::IGUIEnvironment* guienv_;
    myEventReceiver receiver_;
public:
    IrrlichtCore();
    void initIrrlicht();
    void irrlichtGfx();
    myEventReceiver& getEventReceiver();
    irr::IrrlichtDevice* getDevice();
    irr:video::IVideoDriver* getDriver();
    irr::scene::ISceneManager* getSceneManager();
    irr::gui::IGUIEnvironment* getGuiEnvironment();

};

#endif // IRRLICHT_CORE_H
