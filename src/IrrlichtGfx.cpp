#include "IrrlichtGfx.h"

using namespace irr;
using namespace core;

IrrlichtGfx::IrrlichtGfx()
{
  frameTime_ = 0.0f;
  lastUpdatedTime_ = 0;
}

u32 IrrlichtGfx::drawAll (Map *map)
{

  scenemgr_->drawAll ();
  guienv_->drawAll ();

  return 0;
}

Camera* IrrlichtGfx::getCamera ()
{
  return camera_;
}

Gui* IrrlichtGfx::getGui ()
{
  return gui_;
}

ObjectMgr* IrrlichtGfx::getObjectMgr ()
{
  return objectMgr_;
}

f32 IrrlichtGfx::getFrameTime ()
{
  return frameTime_;
}

void IrrlichtGfx::updateTimer ()
{
  frameTime_ = static_cast<f32>(getTime() - lastUpdatedTime_);
  lastUpdatedTime_ += static_cast<u32>(frameTime_);
}

void IrrlichtGfx::initIrrlicht ()
{
  IrrlichtCore::initIrrlicht ();
  objectMgr_ = new ObjectMgr();
  gui_ = new Gui();
  camera_ = new Camera(scenemgr_->addCameraSceneNode());
  camera_->getSceneNode()->setFOV(irr::core::PI/5.0f);
}
