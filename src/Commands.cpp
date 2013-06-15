#include "Commands.h"
#include "Celestial.h"
#include "SpaceShip.h"

using namespace irr::core;

bool Commands::run(Command com, const array<stringc> args, User *user)
{
	switch(com)
	{
		case COMMAND_HELP:
			help(args);
			break;
        case COMMAND_SPAWN:
            spawn(args, user);
            break;
		default:
			break;
	}
	return true;
}
void Commands::help(const array<stringc> args)
{
	if(args[0].empty())
	{
		//TODO:
		//listing
	}
}

void Commands::spawn(const array<stringc> args, User *user)
{
    f32 param2 = 0;
    if(args.size() > 1)
        param2 = strtof10(args[1].c_str());
    SOB *spawnedObj = 0;
    switch (SOB::strtoSOBT(args[0])) {
    case SOB_SUN:
        spawnedObj = new Sun(0, user->display(), (param2<0.1)?(Sun::getDefaultScale()):param2, user->getMyShip().getPosition(), user->getMyShip().getRotation());
        break;
    case SOB_PLANET:
        spawnedObj = new Planet(0, user->display(), (param2<0.1)?(Planet::getDefaultScale()):param2, user->getMyShip().getPosition(), user->getMyShip().getRotation());
        break;
    case SOB_MOON:
        spawnedObj = new Moon(0, user->display(), (param2<0.1)?(Moon::getDefaultScale()):param2, user->getMyShip().getPosition(), user->getMyShip().getRotation());
        break;
    case SOB_ASTEROID:
        spawnedObj = new Asteroid(0, user->display(), (param2<0.1)?(Asteroid::getDefaultScale()):param2, user->getMyShip().getPosition(), user->getMyShip().getRotation());
        break;
    case SOB_SPACESHIP:
        spawnedObj = new SpaceShip(0, user->display(), user->getMyShip().getPosition(), user->getMyShip().getRotation());
        break;
    default:
        break;
    }
    if(spawnedObj)
        user->display().addObject(spawnedObj);
}
