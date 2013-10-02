#include "Camera.h"
#include "Globals.h"

using namespace irr;
using namespace core;


const f32& Camera::getMovementSpeed() const
{
  return movementSpeed_;
}

void Camera::setMovementSpeed(const irr::f32& movementSpeed)
{
  movementSpeed_ = movementSpeed;
}

const f32& Camera::getRotateSpeed() const
{
  return rotateSpeed_;
}

void Camera::setRotateSpeed(const irr::f32& rotateSpeed)
{
  rotateSpeed_ = rotateSpeed;
}
Camera::Camera(scene::ICameraSceneNode *node)
{
  sceneNode_ = node;
  reset(true);
}

void Camera::attach(SpaceObject* object)
{
  target_ = object;
}

void Camera::attach(const GUID& guid)
{
  SpaceObject* spaceObject = sIGfx->getObjectMgr()->getObject(guid);
  attach(spaceObject);
}

void Camera::detach()
{
  target_ = 0;
  sceneNode_->setParent (0);
}

void Camera::setDistance(const int &distance)
{
  position_.Y = static_cast<float>(distance);
}

int Camera::getDistance() const
{
  return position_.Y;
}

scene::ICameraSceneNode* Camera::getSceneNode ()
{
  return sceneNode_;
}

void Camera::setSceneNode (scene::ICameraSceneNode *node)
{
  sceneNode_ = node;
}

void Camera::setPosition(const vector3df &position)
{
  position_ = position;
}

const vector3df& Camera::getPosition() const
{
  return position_;
}

void Camera::setOrientation(const vector3df &orientation)
{
  orientation_ = orientation;
}

const vector3df& Camera::getOrientation() const
{
  return orientation_;
}

void Camera::setMaxDistance(const int &maxDistance)
{
  maxDistance_ = maxDistance;
}

const int& Camera::getMaxDistance() const
{
  return maxDistance_;
}

void Camera::setMinDistance(const int &minDistance)
{
  minDistance_ = minDistance;
}

const int& Camera::getMinDistance() const
{
  return minDistance_;
}

void Camera::move(const vector3df& direction, const u32& frameTime)
{

  vector3df position = position_ + direction * movementSpeed_ * frameTime;
  if(position.getLength () <= maxDistance_ && position.getLength () >= minDistance_)
    setPosition (position);
}

void Camera::rotate(const vector3df &direction, const u32 &frameTime)
{
  orientation_ += direction * frameTime * rotateSpeed_;
  orientation_ = orientation_.normalize ();
}

void Camera::reset(const bool &isFullReset)
{
  if(isFullReset)
  {
    target_ = 0;
    if(sceneNode_ != 0)
      sceneNode_->setPosition (vector3df(0,0,0));
  }
  position_    = vector3df(0,500,0);
  orientation_ = vector3df(0,0,0);
  minDistance_ = MIN_CAMERA_DIST;
  maxDistance_ = MAX_CAMERA_DIST;
  movementSpeed_ = MOVEMENT_SPEED;
  rotateSpeed_ = ROTATE_SPEED/100;
}

void Camera::control()
{
  sceneNode_->setPosition (((target_ != 0) ? target_->getPosition () : vector3df(0,0,0)) + position_);
  sceneNode_->setTarget ((target_ != 0) ? target_->getPosition () : vector3df(0,0,0));
}
