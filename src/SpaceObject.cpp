#include "SpaceObject.h"
#include "Globals.h"

using namespace irr;
using namespace core;
using namespace scene;

void SpaceObject::control(){
  u32 frameTime = sIGfx->getFrameTime ();
  setOrientation (this->getOrientation () +
                  this->getRotationSpeed () * frameTime);
  setPosition (this->getPosition () +
               this->getMovementSpeed () * frameTime);
}

SpaceObject::SpaceObject(IAnimatedMeshSceneNode* node)
{
  sceneNode_ = node;
  parent_ = 0;
  mass_ = 1;
  movementSpeed_ = vector3df(0,0,0);
  rotationSpeed_ = vector3df(0,0,0);
}

void SpaceObject::setPositionRelative (vector3df pos, SpaceObject* parent)
{
  vector3df newPos(0,0,0);
  if(parent != 0)
    {
      newPos = parent->getPosition();
    }
  newPos += pos;
  setPosition(newPos);
}

SpaceObjectType SpaceObject::strToSpaceObject (stringc arg)
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

void SpaceObject::turn(f32 radian)
{
  this->setOrientation(this->getOrientation() + vector3df(0,radian,0));
}
