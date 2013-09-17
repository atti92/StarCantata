#ifndef Celestial_H
#define Celestial_H

#include "SpaceObject.h"
#include "Display.h"
using namespace video;
//I had separate headers for each class but I think its alright this way ^^

//define constants for the object loading system
#define     _JPG    ".jpg"
#define     _OBJ    ".obj"

#define     PATH_BASE_OBJECT        "./objects"
#define     PATH_BASE_TEXTURE       "./textures"
#define     PATH_CELESTIAL_OBJECT   "/celestial/"
#define     PATH_CELESTIAL_TEXTURE  "/celestial/"
#define     PATH_STAR_OBJECT        "/star/"
#define     PATH_STAR_TEXTURE       "/star/"
#define     PATH_PLANET_OBJECT      "/planet/"
#define     PATH_PLANET_TEXTURE     "/planet/"
#define     PATH_MOON_OBJECT        "/moon/"
#define     PATH_MOON_TEXTURE       "/moon/"
#define     PATH_ASTEROID_OBJECT    "/asteroid/"
#define     PATH_ASTEROID_TEXTURE   "/asteroid/"

#define     FILE_STAR_TEXTURE       "star_"
#define     FILE_PLANET_TEXTURE     "planet_"
#define     FILE_MOON_TEXTURE       "moon_"
#define     FILE_ASTEROID_TEXTURE   "asteroid_"

#define     DEFAULT_CELESTIAL_OBJECT "sphere"

class Celestial : public SpaceObject
{
protected:
    f32 mean_anomaly;
    f32 s_major_a;
    f32 eccentricity;
    f32 foci_dist;
    io::path obj_path;
	io::path texture_path;
	io::path default_obj;
	f32 initial_rot;
	bool orbiting;
public:
	Celestial();
	Celestial(IAnimatedMeshSceneNode* inode);
	Celestial(Display& display, const f32 scale, const vector3df pos, const vector3df rot, bool lighting = true);
	void setOrbit(SOB *parent, const f32 s_major_a, const f32 foci_dist, const f32 initial_rot = 0);
	virtual void refresh(const f32 frameTime, const u32 time);
	const f32 eccentricAnomaly(const f32 Mean_time);  //returns the true angle from the circle angle
	virtual void move(const f32 frameTime, const u32 time);
};

class Planet : public Celestial
{
public:
	Planet();
	Planet(IAnimatedMeshSceneNode* inode);
	Planet(const u32 type, Display& display, const f32 scale = 2, const vector3df pos = vector3df(0, 0, 0), const vector3df rot = vector3df(0,0,0));
    static f32 getDefaultScale(){ return 15; }
};

class Moon : public Celestial
{
public:
	Moon();
	Moon(IAnimatedMeshSceneNode* inode);
	Moon(const u32 type, Display& display, const f32 scale = 1, const vector3df pos = vector3df(0, 0, 0), const vector3df rot = vector3df(0,0,0));
    static f32 getDefaultScale(){ return 5; }
};

class Asteroid : public Celestial
{
public:
	Asteroid();
	Asteroid(IAnimatedMeshSceneNode* inode);
	Asteroid(const u32 type, Display& display, const f32 scale = 0.3, const vector3df pos = vector3df(0, 0, 0), const vector3df rot = vector3df(0,0,0));
    static f32 getDefaultScale(){ return 1; }
};

class Sun : public Celestial
{
protected:
	double lightrange;
	SColorf lightcolor;
public:
	Sun();
	Sun(IAnimatedMeshSceneNode* inode);
	Sun(u32 type, Display& display, f32 scale = 20, vector3df pos = vector3df(0, 0, 0), vector3df rot = vector3df(0,0,0), SColorf lightcolor = SColorf(1.f,0.f,0.f), f32 lightrange = 1000);
    static f32 getDefaultScale(){ return 30; }
};
#endif
