#include "Camera.h"
#include "Globals.h"

using namespace irr;
using namespace core;

Camera::Camera()
{
  position_ = vector3df(0,0,0);
  orientation_ = vector3df(0,0,0);
  target_ = 0;
  minDistance_ = MIN_CAMERA_DIST;
  maxDistance_ = MAX_CAMERA_DIST;
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
