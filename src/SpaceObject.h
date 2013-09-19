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

class SpaceObject : public Object
{
protected:
    irr::core::vector3df movementSpeed_, rotationSpeed_;
    irr::f32 mass_;
    SpaceObject *parent_;
    GUID guid_;
    irr::scene::IAnimatedMeshSceneNode* sceneNode_;
public:
    SpaceObject(irr::scene::IAnimatedMeshSceneNode* node = 0);
    GUID getGUID();
    void setGUID(GUID guid);

    Map* getMap();
    void setMap(Map* map);

    void setSceneNode(irr::scene::IAnimatedMeshSceneNode* node);
    irr::scene::IAnimatedMeshSceneNode* getSceneNode();

    irr::core::vector3df getPosition();
    void setPosition(irr::core::vector3df pos);
    irr::core::vector3df getOrientation();
    void setOrientation(irr::core::vector3df orientation);
    irr::core::vector3df getMovementSpeed();
    void setMovementSpeed(irr::core::vector3df movementSpeed);
    irr::core::vector3df getRotationSpeed();
    void setRotationSpeed(irr::core::vector3df rotationSpeed);
    irr::f32 getMass();
    void setMass(irr::f32 mass);
    irr::core::vector3df getPositionRelative(SpaceObject* parent);
    void setPositionRelative(irr::core::vector3df pos, SpaceObject* parent);


    irr::f32 getMovementSpeedAbs();
    void setMovementSpeedAbs(irr::f32 speedValue);
    irr::f32 getRotationSpeedAbs();
    void setRotationSpeedAbs(irr::f32 speedValue);

    void turn(irr::f32 radian);
    virtual void control(const irr::f32 frameTime, const irr::u32 time);
    virtual void setOrbit(SpaceObject *parent = 0, const irr::f32 semiMajorAxis = 0, const irr::f32 fociDistance = 0, const irr::f32 initOrientation = 0);


    static const irr::core::vector3df rotToMovVector(const irr::core::vector3df rotation)
    {
        return irr::core::vector3df(sin(rotation.Y*irr::core::PI/180), 0, cos(rotation.Y*irr::core::PI/180));
    }
    static SpaceObjectType strToSpaceObject(irr::core::stringc arg);
};

#endif
