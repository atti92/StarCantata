#ifndef Ship_H
#define Ship_H

#include "SpaceObject.h"		//inherited from Space object

#define SPACESHIP_MESH_PATH "objects/spaceship/"
#define SPACESHIP_TEXTURE_PATH "texture/spaceship/"

enum Direction {
  DIR_NONE = 0,
  DIR_FORWARD = 1,
  DIR_BACKWARD = 2,
  DIR_ANTI_CLOCKWISE = 4,
  DIR_CLOCKWISE = 8
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
  irr::u8 movement_;
public:
  SpaceShip(irr::scene::IAnimatedMeshSceneNode* inode = 0); //example: Ship testship = someIsceneNodepointerobject; or Ship testship = Ship(someiscenenodeobj);
  SpaceShip(irr::u32 type, irr::core::vector3df pos = irr::core::vector3df(0,0,0), irr::core::vector3df rot = irr::core::vector3df(0,0,0));  //constructor for ship addition example: Ship testship = Ship(5, display); positions are defaulted to 0
  void init();
  const irr::f32& getMaxTurnSpeed() const;
  const irr::f32& getMaxTravelSpeed() const;
  irr::f32 getBaseThrustValue() const;
  irr::f32 getModdedThrustValue() const;
  irr::f32 getRealThrustValue() const;   //used in movement
  irr::f32 getRealBreakValue() const;
  const irr::f32& getCurrentEnergy() const;
  const irr::f32& getCurrentHp() const;
  const irr::f32& getMaxEnergy() const;
  const irr::f32& getMaxHp() const;
  void setMaxTurnSpeed(const irr::f32& sp = 1);
  void setMaxTravelSpeed(const irr::f32& sp = 200);
  bool isThrusting() const;
  bool isBreaking() const;
  bool isTurningACW() const;
  bool isTurningCW() const;
  void thrust(Direction dir);
  void turn(Direction dir);
  void moveBy(const irr::core::vector3df& speedvector);
  void control();
};

#endif
