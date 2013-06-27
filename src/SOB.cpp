#include "SOB.h"


void SOB::move(const f32 frameTime, const u32 time){
	scene_node->setRotation(scene_node->getRotation() + rot_speed * frameTime);
	scene_node->setPosition(scene_node->getPosition() + mov_speed * frameTime);
}

SOB::SOB()
{
	scene_node = 0;
	parent = 0;
	mass = 1;
	mov_speed = vector3df(0,0,0);
	rot_speed = vector3df(0,0,0);
}

SOB::SOB(IAnimatedMeshSceneNode* node)
{
	scene_node = node;
	parent = 0;
	mass = 1;
	mov_speed = vector3df(0,0,0);
	rot_speed = vector3df(0,0,0);
}

void SOB::setRelPosition(const vector3df pos, SOB* parent)
{
    vector3df newPos(0,0,0);
    if(parent)
    {
        newPos = parent->getPosition();
    }
    newPos += pos;
    setPosition(pos);
}

SpaceObjType SOB::strtoSOBT(stringc arg)
{
    if(arg.equals_ignore_case("star"))
        return SOB_SUN;
    if(arg.equals_ignore_case("spaceship") || arg.equals_ignore_case("ship"))
        return SOB_SPACESHIP;
    if(arg.equals_ignore_case("planet"))
        return SOB_PLANET;
    if(arg.equals_ignore_case("moon"))
        return SOB_MOON;
    if(arg.equals_ignore_case("asteroid"))
        return SOB_ASTEROID;
    return SOB_NONE;
}

void SOB::Turn(f32 radian)
{
    this->setRotation(this->getRotation() + vector3df(0,radian,0));
}
