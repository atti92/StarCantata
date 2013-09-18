#ifndef Ship_H
#define Ship_H

#include "SpaceObject.h"		//inherited from Space object
#include "Display.h"

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
    f32 hitPoints_;
    f32 energy_;
    f32 maxhitPoints_;
    f32 maxenergy_;
    f32 maxTurnSpeed_;
    f32 maxTravelSpeed_;
    u8 movement;
public:
    SpaceShip(IAnimatedMeshSceneNode* inode = 0); //example: Ship testship = someIsceneNodepointerobject; or Ship testship = Ship(someiscenenodeobj);
    SpaceShip(const u32 type, Display& display, const vector3df pos = vector3df(0,0,0), const vector3df rot = vector3df(0,0,0));  //constructor for ship addition example: Ship testship = Ship(5, display); positions are defaulted to 0
    void init();
    f32 getMaxTurnSpeed();
    f32 getMaxTravelSpeed();
    f32 getBaseThrustValue();
    f32 getModdedThrustValue();
    f32 getRealThrustValue();   //used in movement
    f32 getRealBreakValue();
    f32 getCurrentEnergy();
    f32 getCurrentHp();
    f32 getMaxEnergy();
    f32 getMaxHp();
    void setMaxTurnSpeed(f32 sp = 1);
    void setMaxTravelSpeed(f32 sp = 200);
    bool isThrusting();
    bool isBreaking();
    bool isTurningACW();
    bool isTurningCW();
    void thrust(Direction dir);
    void turn(Direction dir);
    void moveBy(vector3df speedvector);
    void control(const f32 frameTime, const u32 time);
};

#endif
