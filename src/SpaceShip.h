#ifndef Ship_H
#define Ship_H

#include "SOB.h"		//inherited from Space object
#include "Display.h"

enum Direction {
    DIR_NONE = 0,
    DIR_FORWARD,
    DIR_BACKWARD,
    DIR_CLOCKWISE,
    DIR_ANTI_CLOCKWISE
};

class SpaceShip : public SOB
{
protected:
    f32 hitPoints;
    f32 energy;
    f32 maxhitPoints;
    f32 maxenergy;
    f32 maxturnspeed;
    f32 maxtravelspeed;
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
    f32 getCurrentEnergy(){return energy;}
    f32 getCurrentHp(){return hitPoints;}
    f32 getMaxEnergy(){return energy;}
    f32 getMaxHp(){return hitPoints;}
    void setMaxTurnSpeed(f32 sp = 1){maxturnspeed = sp;}
    void setMaxTravelSpeed(f32 sp = 100){maxtravelspeed = sp;}
    bool isThrusting(){return (movement & 0x01) > 0;}
    bool isBreaking(){return (movement & 0x02) > 0;}
    bool isTurningACW(){return (movement & 0x04) > 0;}
    bool isTurningCW(){return (movement & 0x08) > 0;}
    void Thrust(Direction dir);
    void Turn(Direction dir);
    void MoveBy(vector3df speedvector);
    void refresh(const f32 frameTime, const u32 time);
};

#endif
