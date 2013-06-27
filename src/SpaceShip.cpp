#include "SpaceShip.h"



SpaceShip::SpaceShip(IAnimatedMeshSceneNode* inode)
{
    scene_node = inode;
    this->init();
}

SpaceShip::SpaceShip(const u32 type, Display& display, const vector3df pos, const vector3df rot)
{
    this->init();
    const io::path ship_obj_path = "objects/spaceship/";
    const io::path textures = "textures/spaceship/";
	io::path shipType[20];  // A list could be loaded from a file
	shipType[0] = "RPG_Scythe_1.obj";   
	//NEED TO CHANGE END

    scene_node = display.smgr->addAnimatedMeshSceneNode(display.smgr->getMesh(ship_obj_path+shipType[type]), 0, -1, pos, rot);  //create ship scene
	scene_node->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true); //scaled object
	scene_node->getMaterial(0).AmbientColor.set(255,255,255,255); 
	scene_node->getMaterial(0).EmissiveColor.set(0,0,0,0);
	scene_node->getMaterial(0).DiffuseColor.set(255,0,0,255);
	scene_node->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER , true);
    this->setPosition(pos);
    this->setRotation(rot);
}

void SpaceShip::init()
{
    maxenergy = 100;
    maxhitPoints = 100;
    maxtravelspeed = 100;
    maxturnspeed = 100;
    movement = 0;
    mov_speed = vector3df(0,0,0);
    rot_speed = vector3df(0,0,0);
    mass = 1;
}

void SpaceShip::refresh(const f32 frameTime, const u32 time)
{
    if(this->isThrusting())
    {
        mov_speed += SOB::rotToMovVector(this->getRotation())* frameTime * this->getRealThrustValue();
        if(this->getMaxTravelSpeed() < mov_speed.getLength())
        {
            this->setMovSpeedValue(this->getMaxTravelSpeed());
        }
    }
    if(this->isBreaking())
    {
        if(this->getMovSpeedValue() > 0)
            this->setMovSpeedValue(this->getMovSpeedValue() - frameTime * this->getRealBreakValue());
        if(this->getMovSpeedValue() < 0)
             this->setMovSpeedValue(0);
    }
    if(this->isTurningACW() || this->isTurningCW())
    {
        this->setRotation(this->getRotation() + vector3df(0, (this->isTurningACW()?-1:1)*frameTime * this->getMaxTurnSpeed(),0) );
    }
    move(frameTime, time);
    movement = 0;   //not sticky
}
void SpaceShip::Thrust(Direction dir)
{
    switch (dir) {
    case DIR_FORWARD:
        movement = (movement & 0xFC) + 1;
        break;
    case DIR_BACKWARD:
        movement = (movement & 0xFC) + 2;
        break;
    default:
        movement = movement & 0xFC;
        break;
    }
}

void SpaceShip::Turn(Direction dir)
{
    switch (dir) {
    case DIR_ANTI_CLOCKWISE:
        movement = (movement & 0xF3) + 4;
        break;
    case DIR_CLOCKWISE:
        movement = (movement & 0xF3) + 8;
        break;
    default:
        movement = movement & 0xF3;
        break;
    }
}



f32 SpaceShip::getMaxTurnSpeed()
{
    return this->maxturnspeed;
}

f32 SpaceShip::getMaxTravelSpeed()
{
    return this->maxtravelspeed;
}

f32 SpaceShip::getBaseThrustValue()
{
    return 100;     //will be the engine's value
}

f32 SpaceShip::getModdedThrustValue()
{
    return this->getBaseThrustValue();
}

f32 SpaceShip::getRealThrustValue()
{
    return this->getBaseThrustValue()/(1 + this->getMass());
}
f32 SpaceShip::getRealBreakValue()
{
    return this->getBaseThrustValue()/(1 + 2 * this->getMass());
}
