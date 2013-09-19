#ifndef CAMERA_H
#define CAMERA_H

#include "irrlicht.h"
#include "SpaceObject.h"

enum CameraConsts
{
  MIN_CAMERA_DIST = 100,
  MAX_CAMERA_DIST = 2000
};

class Camera{
  irr::scene::IAnimatedMeshSceneNode* target_;
  int minDistance_, maxDistance_;
  irr::core::vector3df position_, orientation_;
public:
  Camera();
  void attach(SpaceObject* object);
  void attach(GUID guid);
  void detach();
  void setDistance(int distance);
  int getDistance();
  void setPosition(irr::core::vector3df position_);
  irr::core::vector3df getPosition();
  void setOrientation(irr::core::vector3df orientation);
  irr::core::vector3df getOrientation();
  void setMaxDistance(int maxDistance);
  int getMaxDistance();
  void setMinDistance(int minDistance);
  int getMinDistance();
};

#endif // CAMERA_H
