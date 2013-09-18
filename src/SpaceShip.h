#ifndef Ship_H
#define Ship_H

#include "SpaceObject.h"		//inherited from Space object

enum Direction {
    DIR_NONE = 0,
    DIR_FORWARD,
    DIR_BACKWARD,
    DIR_CLOCKWISE,
    DIR_ANTI_CLOCKWISE
};

class SpaceShip : public SpaceObject
{
protected:
    irr::f32 hitPoints_;
    irr::f32 energy_;
    irr::f32 maxHitPoints_;
    irr::f32 maxEnergy_;
    irr::f32 maxTurnSpeed_;
    irr::f32 maxTravelSpeed_;
    irr::u8 movement;
public:
    SpaceShip(irr::scene::IAnimatedMeshSceneNode* inode = 0); //example: Ship testship = someIsceneNodepointerobject; or Ship testship = Ship(someiscenenodeobj);
    SpaceShip(irr::u32 type, irr::core::vector3df pos = irr::core::vector3df(0,0,0), irr::core::vector3df rot = irr::core::vector3df(0,0,0));  //constructor for ship addition example: Ship testship = Ship(5, display); positions are defaulted to 0
    void init();
    irr::f32 getMaxTurnSpeed();
    irr::f32 getMaxTravelSpeed();
    irr::f32 getBaseThrustValue();
    irr::f32 getModdedThrustValue();
    irr::f32 getRealThrustValue();   //used in movement
    irr::f32 getRealBreakValue();
    irr::f32 getCurrentEnergy();
    irr::f32 getCurrentHp();
    irr::f32 getMaxEnergy();
    irr::f32 getMaxHp();
    void setMaxTurnSpeed(irr::f32 sp = 1);
    void setMaxTravelSpeed(irr::f32 sp = 200);
    bool isThrusting();
    bool isBreaking();
    bool isTurningACW();
    bool isTurningCW();
    void thrust(Direction dir);
    void turn(Direction dir);
    void moveBy(irr::core::vector3df speedvector);
    void control(const irr::f32 frameTime, const irr::u32 time);
};

#endif
