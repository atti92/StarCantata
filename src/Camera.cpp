#include "Camera.h"
#include "Globals.h"

using namespace irr;
using namespace core;


irr::f32 Camera::movementSpeed() const
{
  return movementSpeed_;
}

void Camera::setMovementSpeed(const irr::f32& movementSpeed)
{
  movementSpeed_ = movementSpeed;
}

irr::f32 Camera::rotateSpeed() const
{
  return rotateSpeed_;
}

void Camera::setRotateSpeed(const irr::f32& rotateSpeed)
{
  rotateSpeed_ = rotateSpeed;
}
Camera::Camera()
{
  reset(true);
}

void Camera::attach(SpaceObject* object)
{
  target_ = object;
}

void Camera::attach(GUID guid)
{
  SpaceObject* spaceObject = sIGfx->getObjectMgr()->getObject(guid);
  attach(spaceObject);
}

void Camera::detach()
{
  target_ = 0;
}

void Camera::setDistance(int distance)
{
  position_.Z = static_cast<float> distance;
}

int Camera::getDistance()
{
  return position_.Z;
}

void Camera::setPosition(vector3df position)
{
  position = position;
}

vector3df Camera::getPosition()
{
  return position_;
}

void Camera::setOrientation(vector3df orientation)
{
  orientation_ = orientation;
}

vector3df Camera::getOrientation()
{
  return orientation_;
}

void Camera::setMaxDistance(int maxDistance)
{
  maxDistance_ = maxDistance;
}

int Camera::getMaxDistance()
{
  return maxDistance_;
}

void Camera::setMinDistance(int minDistance)
{
  minDistance_ = minDistance;
}

int Camera::getMinDistance()
{
  return minDistance_;
}

void Camera::move(vector3df direction, u32 frameTime)
{
  position_ += direction * movementSpeed_ * frameTime;
}

void Camera::rotate(vector3df direction, u32 frameTime)
{
  orientation_ += direction * frameTime * rotateSpeed_;
  orientation_ = orientation_.normalize ();
}

void Camera::reset(bool isFullReset)
{
  if(isFullReset)
  {
    target_ = 0;
    position_ = vector3df(0,0,0);
  }
  orientation_ = vector3df(0,0,0);
  minDistance_ = MIN_CAMERA_DIST;
  maxDistance_ = MAX_CAMERA_DIST;
  movementSpeed_ = DEF_MOVEMENT_SPEED;
}

void Camera::control()
{
  //refresh camera position
}
