#include "Commands.h"
#include "Celestial.h"
#include "SpaceShip.h"
#include "Globals.h"

using namespace irr;
using namespace irr::core;

bool Command::run(const CommandName &com, const irr::core::array<stringc> &args)
{
  switch(com)
    {
    case COMMAND_HELP:
      help(args);
      break;
    case COMMAND_SPAWN:
      spawn(args);
      break;
    default:
      break;
    }
  return true;
}
void Command::help(const irr::core::array<stringc> &args)
{
  if(args[0].empty())
    {
      //TODO:
      //listing
    }
}

void Command::spawn(const irr::core::array<stringc> &args)
{
  f32 param2 = 0;
  if(args.size() > 1)
    param2 = strtof10(args[1].c_str());
  SpaceObject *spawnedObj = 0;
  vector3df pos = sUser->getSpaceShip ()->getPosition ();
  vector3df orientation = sUser->getSpaceShip ()->getOrientation ();

  switch (SpaceObject::strToSpaceObject (args[0])) {
    case SOB_SUN:
      spawnedObj = new Sun(0, (param2<0.1)?(Sun::getDefaultScale()):param2,
                           pos, orientation);
      break;
    case SOB_PLANET:
      spawnedObj = new Planet(0, (param2<0.1)?(Planet::getDefaultScale()):param2,
                              pos, orientation);
      break;
    case SOB_MOON:
      spawnedObj = new Moon(0, (param2<0.1)?(Moon::getDefaultScale()):param2,
                            pos, orientation);
      break;
    case SOB_ASTEROID:
      spawnedObj = new Asteroid(0, (param2<0.1)?(Asteroid::getDefaultScale()):param2,
                                pos, orientation);
      break;
    case SOB_SPACESHIP:
      spawnedObj = new SpaceShip(0, pos, orientation);
      break;
    default:
      break;
    }
  if(spawnedObj != 0)
    sIGfx->getObjectMgr ()->addObject (spawnedObj);
}
