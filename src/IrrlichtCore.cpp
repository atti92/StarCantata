#include "IrrlichtCore.h"

using namespace irr;
using namespace core;


IrrlichtCore::IrrlichtCore()
{

}

void IrrlichtCore::initIrrlicht ()
{
  receiver_ = new MyEventReceiver();
  device_ = createDevice( video::EDT_OPENGL, dimension2d<u32>(800, 600), 16, false, false, true, receiver_);

  driver_ = device_->getVideoDriver();
  scenemgr_ = device_->getSceneManager();
  guienv_ = device_->getGUIEnvironment();
  //camera_ = scenemgr_->addCameraSceneNode();
  //camera_->setFOV(irr::core::PI/5.0f);
  device_->setWindowCaption(L"Star Cantata Production");
  scenemgr_->setAmbientLight(video::SColorf(0.05f, 0.05f, 0.05f, 1.0f));
}

void IrrlichtCore::irrlichtGfx ()
{

}

MyEventReceiver* IrrlichtCore::getEventReceiver ()
{
  return receiver_;
}

IrrlichtDevice* IrrlichtCore::getDevice ()
{
  return device_;
}

video::IVideoDriver* IrrlichtCore::getDriver ()
{
  return driver_;
}

scene::ISceneManager* IrrlichtCore::getSceneManager ()
{
  return scenemgr_;
}

gui::IGUIEnvironment* IrrlichtCore::getGuiEnvironment ()
{
  return guienv_;
}

u32 IrrlichtCore::getTime ()
{
  return ITimer::getTime ();
}
