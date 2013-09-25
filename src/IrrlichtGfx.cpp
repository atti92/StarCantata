#include "IrrlichtGfx.h"

using namespace irr;
using namespace core;

IrrlichtGfx::IrrlichtGfx()
{
  frameTime_ = 0;
  lastUpdatedTime_ = getTime();
}

u32 IrrlichtGfx::drawAll (Map *map)
{
  map->updateAll ();
}

u32 IrrlichtGfx::drawAll (u16 mapId)
{
  getObjectMgr ()->getMap (mapId)->updateAll ();
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

u32 IrrlichtGfx::getFrameTime ()
{
  return frameTime_;
}

void IrrlichtGfx::updateTimer ()
{
  frameTime_ = getTime() - lastUpdatedTime_;
  lastUpdatedTime_ = getTime();
}

void IrrlichtGfx::initIrrlicht ()
{
  IrrlichtCore::initIrrlicht ();
  camera_ = scenemgr_->addCameraSceneNode();
  camera_->setFOV(irr::core::PI/5.0f);
}
