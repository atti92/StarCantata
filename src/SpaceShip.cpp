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

  this->init();
  io::path shipType[20];  // A list could be loaded from a file
  shipType[0] = "RPG_Scythe_1.obj";

  ISceneManager* smgr = sIGfx->getSceneManager ();
  sceneNode_ = smgr->addAnimatedMeshSceneNode(
        smgr->getMesh(static_cast<io::path>(SPACESHIP_MESH_PATH)+"/"+shipType[type]), 0, -1, pos, rot);  //create ship scene
  if(sceneNode_ == 0)
    return ;
  sceneNode_->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true); //scaled object
  sceneNode_->getMaterial(0).AmbientColor.set(255,255,255,255);
  sceneNode_->getMaterial(0).EmissiveColor.set(0,0,0,0);
  sceneNode_->getMaterial(0).DiffuseColor.set(255,0,0,255);
  sceneNode_->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER , true);
  //sceneNode_->setRotation (vector3df(1,0,0));
  this->setPosition(pos);
  this->setOrientation(rot);
}

void SpaceShip::init()
{
  maxEnergy_ = 100;
  maxHitPoints_ = 100;
  maxTravelSpeed_ = 0.5f;
  maxTurnSpeed_ = 0.1f;
  movement_ = 0;
  movementSpeed_ = vector3df(0,0,0);
  rotationSpeed_ = vector3df(0,0,0);
  mass_ = 1;
}



bool SpaceShip::isThrusting() const
{
  return (movement_ & DIR_FORWARD) == DIR_FORWARD;
}

bool SpaceShip::isBreaking() const
{
  return (movement_ & DIR_BACKWARD) == DIR_BACKWARD;
}

bool SpaceShip::isTurningACW() const
{
  return (movement_ & DIR_ANTI_CLOCKWISE) == DIR_ANTI_CLOCKWISE;
}

bool SpaceShip::isTurningCW() const
{
  return (movement_ & DIR_CLOCKWISE) == DIR_CLOCKWISE;
}

void SpaceShip::moveBy(const vector3df& speedvector)
{
  this->setPositionRelative (speedvector, this);
}

const f32& SpaceShip::getCurrentEnergy() const
{
  return energy_;
}

const f32& SpaceShip::getCurrentHp() const
{
  return hitPoints_;
}

const f32& SpaceShip::getMaxEnergy() const
{
  return maxEnergy_;
}

const f32& SpaceShip::getMaxHp() const
{
  return maxHitPoints_;
}

const f32& SpaceShip::getMaxTurnSpeed() const
{
  return maxTurnSpeed_;
}

const f32& SpaceShip::getMaxTravelSpeed() const
{
  return maxTravelSpeed_;
}

f32 SpaceShip::getBaseThrustValue() const
{
  return 0.01f;     //will be the engine's value
}

f32 SpaceShip::getModdedThrustValue() const
{
  return getBaseThrustValue ();
}

f32 SpaceShip::getRealThrustValue() const
{
  return getBaseThrustValue()/(1 + getMass());
}

f32 SpaceShip::getRealBreakValue() const
{
  return getBaseThrustValue()/(1 + 2 * getMass());
}

void SpaceShip::setMaxTravelSpeed (const f32 &sp)
{
  maxTravelSpeed_ = sp;
}

void SpaceShip::setMaxTurnSpeed (const f32 &sp)
{
  maxTurnSpeed_ = sp;
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

void SpaceShip::control()
{
  f32 frameTime = sIGfx->getFrameTime();

  if(isThrusting())
  {
    movementSpeed_ += rotToMovVector(getOrientation())*
        frameTime *
        getRealThrustValue();
    if(getMaxTravelSpeed() < movementSpeed_.getLength())
    {
      setMovementSpeedAbs (getMaxTravelSpeed());
    }
  }
  if(isBreaking())
  {
    if((getMovementSpeedAbs() - frameTime * getRealBreakValue()) < 0)
      setMovementSpeedAbs(0);
    else
      setMovementSpeedAbs (getMovementSpeedAbs() - frameTime * getRealBreakValue());
  }
  if(isTurningACW() || isTurningCW())
  {
    setOrientation (this->getOrientation() + frameTime * getMaxTurnSpeed() *
                    vector3df(0.0f, static_cast<f32>(isTurningCW() - isTurningACW()), 0.0f));
  }
  movement_ = 0;   //not sticky
  SpaceObject::control();
}
