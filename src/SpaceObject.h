#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include "irrlicht.h"
#include "Object.h"
#include "GUID.h"
#include "Map.h"


enum SpaceObjectType  //not used
{
  SOB_NONE        = 0,
  SOB_SPACESHIP   = 1,
  SOB_SUN         = 2,
  SOB_PLANET      = 3,
  SOB_MOON        = 4,
  SOB_ASTEROID    = 5
};
class Map;

class SpaceObject : public Object
{
protected:
  irr::core::vector3df movementSpeed_, rotationSpeed_;
  irr::f32 mass_;
  SpaceObject *parent_;
  GUID guid_;
  Map* currentMap_;
  irr::scene::IAnimatedMeshSceneNode* sceneNode_;
public:
  SpaceObject(irr::scene::IAnimatedMeshSceneNode* node = 0);
  const GUID& getGUID() const;
  void setGUID(const GUID& guid);

  Map* getMap();
  void setMap(Map* map);

  void setSceneNode(irr::scene::IAnimatedMeshSceneNode* node);
  irr::scene::IAnimatedMeshSceneNode* getSceneNode();

  const irr::core::vector3df getPosition() const;
  void setPosition(const irr::core::vector3df& pos);
  const irr::core::vector3df getOrientation() const;
  void setOrientation(const irr::core::vector3df& orientation);
  const irr::core::vector3df& getMovementSpeed() const;
  void setMovementSpeed(const irr::core::vector3df& movementSpeed);
  const irr::core::vector3df& getRotationSpeed() const;
  void setRotationSpeed(const irr::core::vector3df& rotationSpeed);
  const irr::f32 getMovementSpeedAbs() const;
  void setMovementSpeedAbs(const irr::f32& speedValue);
  const irr::f32 getRotationSpeedAbs() const;
  void setRotationSpeedAbs(const irr::f32& speedValue);

  const irr::f32& getMass() const;
  void setMass(const irr::f32& mass);
  const irr::core::vector3df getPositionRelative(const SpaceObject* parent) const;
  void setPositionRelative(const irr::core::vector3df& pos, const SpaceObject* parent);

  void turn(const irr::f32& radian);
  virtual void control();
  virtual void setOrbit(SpaceObject *parent = 0, const irr::f32& semiMajorAxis = 0, const irr::f32& fociDistance = 0, const irr::f32& initOrientation = 0);


  static const irr::core::vector3df rotToMovVector(const irr::core::vector3df& rotation)
  {
    return irr::core::vector3df(sin(rotation.Y*irr::core::PI/180), 0,
                                cos(rotation.Y*irr::core::PI/180));
  }
  static const SpaceObjectType strToSpaceObject(const irr::core::stringc& arg);
};

#endif
