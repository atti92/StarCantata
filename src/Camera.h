#ifndef CAMERA_H
#define CAMERA_H

#include "irrlicht.h"
#include "SpaceObject.h"

#define MIN_CAMERA_DIST 100
#define MAX_CAMERA_DIST 2000
#define MOVEMENT_SPEED 1
#define ROTATE_SPEED 3.14


class Camera{
  SpaceObject* target_;
  irr::f32 movementSpeed_, rotateSpeed_;
  int minDistance_, maxDistance_;
  irr::core::vector3df position_, orientation_;
public:
  Camera();
  void attach(SpaceObject* object);
  void attach(const GUID& guid);
  void detach();
  const int& getDistance() const;
  void setDistance(const int& distance);
  const irr::core::vector3df& getPosition() const;
  void setPosition(const irr::core::vector3df& position);
  const irr::core::vector3df& getOrientation() const;
  void setOrientation(const irr::core::vector3df& orientation);
  const int& getMaxDistance() const;
  void setMaxDistance(const int& maxDistance);
  const int& getMinDistance() const;
  void setMinDistance(const int& minDistance);
  const irr::f32& getMovementSpeed() const;
  void setMovementSpeed(const irr::f32& movementSpeed);
  const irr::f32& getRotateSpeed() const;
  void setRotateSpeed(const irr::f32& rotateSpeed);
  void move(const irr::core::vector3df& direction, const irr::u32& frameTime);
  void rotate(const irr::core::vector3df& direction, const irr::u32& frameTime);
  void reset(const bool& isFullReset);
  void control();
};

#endif // CAMERA_H
