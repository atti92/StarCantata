#ifndef USER_H
#define USER_H

#include "SpaceShip.h"
#include "MyEventReceiver.h"  // For the movement control
#include "Gui.h"
#include <string>

class User
{
protected:
  SpaceShip* spaceShip_;
public:
  User();		//Constructor
  void addSpaceShip(Map* map);
  void assignShip(SpaceShip* spaceShip);
  SpaceShip* getSpaceShip();		//getter for the player's ship reference
  bool isKeyPressed(irr::EKEY_CODE key);
  void manageControls();

  //calculate delta time conversion: translates the ship's rotation to the facing direction vector
};

#endif
