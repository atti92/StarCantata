#include "SpaceObject.h"
#include "Globals.h"

using namespace irr;
using namespace core;
using namespace scene;


SpaceObject::SpaceObject(IAnimatedMeshSceneNode *node)
{
  sceneNode_ = node;
  parent_ = 0;
  mass_ = 1;
  movementSpeed_ = vector3df(0,0,0);
  rotationSpeed_ = vector3df(0,0,0);
}

const GUID& SpaceObject::getGUID() const
{
  return this->guid_;
}

void SpaceObject::setGUID (const GUID &guid)
{
  this->guid_ = guid;
}

Map* SpaceObject::getMap ()
{
  return this->currentMap_;
}

void SpaceObject::setMap (Map *map)
{
  if(this->currentMap_)
    this->currentMap_->removeObject (this);
  map->addObject (this);
}

void SpaceObject::setSceneNode (IAnimatedMeshSceneNode *node)
{
  this->sceneNode_ = node;
}

IAnimatedMeshSceneNode* SpaceObject::getSceneNode ()
{
  return this->sceneNode_;
}

const vector3df SpaceObject::getPosition() const
{
  if(sceneNode_ != 0)
    return this->sceneNode_->getAbsolutePosition ();
  return vector3df(0,0,0);
}

void SpaceObject::setPosition (const vector3df &pos)
{
  if(sceneNode_ != 0)
    this->sceneNode_->setPosition (pos);
}

const vector3df SpaceObject::getOrientation () const
{
  if(sceneNode_ != 0)
    return this->sceneNode_->getRotation ();
  return vector3df(0,0,0);
}

void SpaceObject::setOrientation (const vector3df &orientation)
{
  if(sceneNode_ != 0)
    this->sceneNode_->setRotation (orientation);
}

const vector3df& SpaceObject::getMovementSpeed() const
{
  return this->movementSpeed_;
}

void SpaceObject::setMovementSpeed (const vector3df &movementSpeed)
{
  this->movementSpeed_ = movementSpeed;
}

const vector3df& SpaceObject::getRotationSpeed() const
{
  return this->rotationSpeed_;
}

void SpaceObject::setRotationSpeed (const vector3df &rotationSpeed)
{
  this->rotationSpeed_ = rotationSpeed;
}

f32 SpaceObject::getMovementSpeedAbs () const
{
  return this->movementSpeed_.getLength ();
}

void SpaceObject::setMovementSpeedAbs (const f32 &speedValue)
{
  this->movementSpeed_.setLength (speedValue);
}

f32 SpaceObject::getRotationSpeedAbs () const
{
  return this->rotationSpeed_.getLength ();
}

void SpaceObject::setRotationSpeedAbs (const f32 &speedValue)
{
  this->rotationSpeed_.setLength (speedValue);
}

const f32& SpaceObject::getMass () const
{
  return this->mass_;
}

void SpaceObject::setMass (const f32 &mass)
{
  if(mass > 0)
    this->mass_ = mass;
}

const vector3df SpaceObject::getPositionRelative (const SpaceObject *parent) const
{
  if(parent != 0)
    return this->getPosition () - parent->getPosition ();
  return this->getPosition ();
}

void SpaceObject::setPositionRelative (const vector3df& pos, const SpaceObject* parent)
{
  if(parent != 0)
  {
    setPosition(parent->getPosition () + pos);
    return;
  }
  setPosition(pos);
}

void SpaceObject::turn (const f32 &radian)
{
  if(this->sceneNode_ != 0)
    this->sceneNode_->setRotation (this->sceneNode_->getRotation () + vector3df(0, radian, 0));
}

void SpaceObject::control(){
  u32 frameTime = sIGfx->getFrameTime ();
  setOrientation (this->getOrientation () +
                  this->getRotationSpeed () * frameTime);
  setPosition (this->getPosition () +
               this->getMovementSpeed () * frameTime);
}

void SpaceObject::setOrbit (SpaceObject *parent, const f32 &semiMajorAxis, const f32 &fociDistance, const f32 &initOrientation)
{
  parent_ = parent;
}

SpaceObjectType SpaceObject::strToSpaceObject (const stringc& arg)
{
  if(arg.equals_ignore_case("star"))
    return SOB_SUN;
  if(arg.equals_ignore_case("spaceship") || arg.equals_ignore_case("ship"))
    return SOB_SPACESHIP;
  if(arg.equals_ignore_case("planet"))
    return SOB_PLANET;
  if(arg.equals_ignore_case("moon"))
    return SOB_MOON;
  if(arg.equals_ignore_case("asteroid"))
    return SOB_ASTEROID;
  return SOB_NONE;
}
