#ifndef Celestial_H
#define Celestial_H

#include "SpaceObject.h"

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

class CelestialObject : public SpaceObject
{
protected:
    irr::f32 meanAnomaly_;
    irr::f32 semiMajorAxis_;
    irr::f32 eccentricity_;
    irr::f32 fociDistance_;
    irr::io::path meshPath_;
    irr::io::path texturePath_;
    irr::io::path defaultMesh_;
    irr::f32 initialOrientation_;
    bool isOrbiting_;
public:
	Celestial();
    Celestial(irr::scene::IAnimatedMeshSceneNode* inode);
    Celestial(irr::f32 scale, const irr::core::vector3df pos, const irr::core::vector3df rot, bool lighting = true);
    void setOrbit(SpaceObject *parent, const irr::f32 semiMajorAxis, const irr::f32 fociDistance, const irr::f32 initialOrientation = 0);
    virtual void control(const irr::f32 frameTime, const irr::u32 time);
    const irr::f32 eccentricAnomaly(const irr::f32 meanTime);  //returns the true angle from the circle angle
};

class Planet : public CelestialObject
{
public:
	Planet();
    Planet(irr::scene::IAnimatedMeshSceneNode* inode);
    Planet(const irr::u32 type, irr::f32 scale = 2, const irr::core::vector3df pos = irr::core::vector3df(0, 0, 0), const irr::core::vector3df rot = irr::core::vector3df(0,0,0));
    static irr::f32 getDefaultScale(){ return 15; }
};

class Moon : public CelestialObject
{
public:
	Moon();
    Moon(irr::scene::IAnimatedMeshSceneNode* inode);
    Moon(const irr::u32 type, const irr::f32 scale = 1, const irr::core::vector3df pos = irr::core::vector3df(0, 0, 0), const irr::core::vector3df rot = irr::core::vector3df(0,0,0));
    static irr::f32 getDefaultScale(){ return 5; }
};

class Asteroid : public CelestialObject
{
public:
	Asteroid();
    Asteroid(irr::scene::IAnimatedMeshSceneNode* inode);
    Asteroid(const irr::u32 type, irr::f32 scale = 0.3, const irr::core::vector3df pos = irr::core::vector3df(0, 0, 0), const irr::core::vector3df rot = irr::core::vector3df(0,0,0));
    static irr::f32 getDefaultScale(){ return 1; }
};

class Sun : public CelestialObject
{
protected:
    double lightRange_;
    irr::video::SColorf lightColor_;
public:
	Sun();
    Sun(irr::scene::IAnimatedMeshSceneNode* inode);
    Sun(irr::u32 type, irr::f32 scale = 20, irr::core::vector3df pos = irr::core::vector3df(0, 0, 0), irr::core::vector3df rot = irr::core::vector3df(0,0,0), irr::video::SColorf lightColor = irr::video::SColorf(1.f,0.f,0.f), irr::f32 lightRange = 1000);
    static irr::f32 getDefaultScale(){ return 30; }
};
#endif
