#include "SpaceShip.h"
#include "Globals.h"

using namespace irr;
using namespace core;
using namespace scene;


SpaceShip::SpaceShip(IAnimatedMeshSceneNode* inode)
{
  sceneNode_ = inode;
  this->init();
}

SpaceShip::SpaceShip(u32 type, vector3df pos, vector3df rot)
{
  //Still working on the ObjectMgr class plan to make this work.
  this->init();
  io::path shipType[20];  // A list could be loaded from a file
  shipType[0] = "RPG_Scythe_1.obj";
  //NEED TO CHANGE END
  ISceneManager* smgr = sIGfx->getSceneManager ();
  sceneNode_ = smgr->addAnimatedMeshSceneNode(
        smgr->getMesh(static_cast<io::path>(SPACESHIP_MESH_PATH)+shipType[type]), 0, -1, pos, rot);  //create ship scene
  sceneNode_->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true); //scaled object
  sceneNode_->getMaterial(0).AmbientColor.set(255,255,255,255);
  sceneNode_->getMaterial(0).EmissiveColor.set(0,0,0,0);
  sceneNode_->getMaterial(0).DiffuseColor.set(255,0,0,255);
  sceneNode_->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER , true);
  this->setPosition(pos);
  this->setOrientation(rot);
}

void SpaceShip::init()
{
  maxEnergy_ = 100;
  maxHitPoints_ = 100;
  maxTravelSpeed_ = 100;
  maxTurnSpeed_ = 100;
  movement_ = 0;
  movementSpeed_ = vector3df(0,0,0);
  rotationSpeed_ = vector3df(0,0,0);
  mass_ = 1;
}

void SpaceShip::control()
{
  u32 frameTime = sIGfx->getFrameTime ();

  if(isThrusting())
  {
    movementSpeed_ += rotToMovVector(getOrientation ())*
        frameTime *
        getRealThrustValue();
    if(getMaxTravelSpeed() < movementSpeed_.getLength())
    {
      setMovementSpeedAbs (getMaxTravelSpeed ());
    }
  }
  if(isBreaking())
  {
    if(getMovementSpeedAbs () > 0)
      setMovementSpeedAbs (getMovementSpeedAbs () - frameTime * getRealBreakValue ());
    if(getMovementSpeedAbs () < 0)
      setMovementSpeedAbs (0);
  }
  if(isTurningACW() || isTurningCW())
  {
    setOrientation (this->getOrientation () + vector3df(0, (isTurningACW()?-1:1) *
                                                        frameTime * getMaxTurnSpeed (), 0) );
  }
  movement_ = 0;   //not sticky
}
void SpaceShip::thrust(Direction dir)
{
  switch (dir) {
    case DIR_FORWARD:
      movement_ = (movement_ & 0xFC) + 1;
      break;
    case DIR_BACKWARD:
      movement_ = (movement_ & 0xFC) + 2;
      break;
    default:
      movement_ = movement_ & 0xFC;
      break;
  }
}

void SpaceShip::turn(Direction dir)
{
  switch (dir) {
    case DIR_ANTI_CLOCKWISE:
      movement_ = (movement_ & 0xF3) + 4;
      break;
    case DIR_CLOCKWISE:
      movement_ = (movement_ & 0xF3) + 8;
      break;
    default:
      movement_ = movement_ & 0xF3;
      break;
  }
}



f32 SpaceShip::getMaxTurnSpeed()
{
  return maxTurnSpeed_;
}

f32 SpaceShip::getMaxTravelSpeed()
{
  return maxTravelSpeed_;
}

f32 SpaceShip::getBaseThrustValue()
{
  return 100;     //will be the engine's value
}

f32 SpaceShip::getModdedThrustValue()
{
  return getBaseThrustValue ();
}

f32 SpaceShip::getRealThrustValue()
{
  return getBaseThrustValue()/(1 + getMass());
}
f32 SpaceShip::getRealBreakValue()
{
  return getBaseThrustValue()/(1 + 2 * getMass());
}
