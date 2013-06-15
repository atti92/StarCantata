#ifndef Visuals_H
#define Visuals_H

#include "irrlicht.h"
#include <string>
#include "Controls.h"
#include "SOB.h"
#include "Camera.h"

class Display
{
public:
	irr::scene::ICameraSceneNode *camera;
	irr::scene::ISceneManager* smgr;
	irr::gui::IGUIEnvironment* guienv;
	irr::IrrlichtDevice* device;
	irr::video::IVideoDriver* driver;
	myEventReceiver receiver;
	core::array<SOB*> objects;
public:
	Display();
	irr::IrrlichtDevice* Device(){ return device; }
	irr::gui::IGUIEnvironment* Guienv(){ return guienv; }
	irr::scene::ICameraSceneNode* Camera(){ return camera; }
	irr::scene::ISceneManager* Smgr(){ return smgr; }
	irr::video::IVideoDriver* Driver(){ return driver; }
	void Set(irr::IrrlichtDevice* _device){ device = _device; }
	void Set(irr::gui::IGUIEnvironment* _guienv){ guienv = _guienv; }
	void Set(irr::scene::ICameraSceneNode* _camera){ camera = _camera; }
	void Set(irr::scene::ISceneManager* _smgr){ smgr = _smgr; }
	void Set(irr::video::IVideoDriver* _driver){ driver = _driver; }
	void addObject(SOB *object){objects.insert(object);}
	SOB* getObject(const u32 i){return objects[i];}
	void refreshObjects(const f32 frameTime, const u32 time);
};

#endif
