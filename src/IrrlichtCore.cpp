#include "IrrlichtCore.h"

using namespace irr;
using namespace core;

//Static member variable default values:

bool IrrlichtCore::isFullScreen_ = 0;
video::E_DRIVER_TYPE IrrlichtCore::videoMode_ = video::EDT_OPENGL;
IrrlichtDevice* IrrlichtCore::device_ = 0;
video::IVideoDriver* IrrlichtCore::driver_ = 0;
scene::ISceneManager* IrrlichtCore::scenemgr_ = 0;
gui::IGUIEnvironment* IrrlichtCore::guienv_ = 0;
MyEventReceiver* IrrlichtCore::receiver_ = 0;

IrrlichtCore::IrrlichtCore()
{

}

void IrrlichtCore::initIrrlicht ()
{
  receiver_ = new MyEventReceiver();
  device_ = createDevice(videoMode_, dimension2d<u32>(800, 600), 16, false, false, true, receiver_);

  driver_ = device_->getVideoDriver();
  scenemgr_ = device_->getSceneManager();
  guienv_ = device_->getGUIEnvironment();
  device_->setWindowCaption(L"Star Cantata Production");
  scenemgr_->setAmbientLight(video::SColorf(0.05f, 0.05f, 0.05f, 1.0f));
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
  if(device_ != 0)
    return device_->getTimer ()->getTime();
  return 0;
}
