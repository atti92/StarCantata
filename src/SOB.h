#ifndef SOB_H
#define SOB_H
#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;

enum SpaceObjType
{
    SOB_NONE = 0,
    SOB_SPACESHIP,
    SOB_SUN,
    SOB_PLANET,
    SOB_MOON,
    SOB_ASTEROID
};

class SOB
{
protected:
	vector3df mov_speed, rot_speed;
	f32 mass;
	SOB *parent;
public:
	IAnimatedMeshSceneNode* scene_node;
public:
	SOB();
	SOB(IAnimatedMeshSceneNode* node);
	void setScene(IAnimatedMeshSceneNode* node){scene_node = node;}

	IAnimatedMeshSceneNode* getScene() {return scene_node; }
	const IAnimatedMeshSceneNode* getScene() const{return scene_node; } //const SOB gives a const scene node

	const vector3df getPosition() const{ return scene_node->getPosition(); }
	const vector3df getRotation() const{ return scene_node->getRotation(); }
	const vector3df getMovSpeed() const{ return mov_speed; }
	const vector3df getRotationSpeed() const{ return rot_speed; }
	const f32 getMovSpeedValue() const{ return mov_speed.getLength(); }
	const f32 getRotSpeedValue() const{ return rot_speed.getLength(); }
    const f32 getMass() const{return mass;}
    void Turn(f32 radian);
	void setPosition(const vector3df pos){ scene_node->setPosition(pos); }
    void setRelPosition(const vector3df pos, SOB* parent);
	void setRotation(const vector3df dir){ scene_node->setRotation(dir); }
	void setMovSpeed(const vector3df dir){ mov_speed = dir; }
	void setRotationSpeed(const vector3df dir){ rot_speed = dir; }
	void setMovSpeedValue(const f32 speed_val){ mov_speed = mov_speed.normalize() * speed_val; }
	void setRotationSpeedValue(const f32 speed_val){ rot_speed = rot_speed.normalize() * speed_val; }
	void setMass(const f32 m){mass = m;}

	virtual void move(const f32 frameTime, const u32 time);
	virtual void refresh(const f32 frameTime, const u32 time)
	{
		move(frameTime, time);
	}
    virtual void setOrbit(SOB *parent = 0, const f32 s_major_a = 0, const f32 foci_dist = 0, const f32 initial_rot = 0){}
    static const vector3df rotToMovVector(const vector3df rotation)
    {
        return vector3df(sin(rotation.Y*PI/180), 0, cos(rotation.Y*PI/180));
    }
    static SpaceObjType strtoSOBT(stringc arg);
};

#endif
