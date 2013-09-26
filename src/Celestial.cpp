#include "Celestial.h"
#include "Globals.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

CelestialObject::CelestialObject():SpaceObject()
{
  isOrbiting_ = false;
  meshPath_ = PATH_BASE_OBJECT;
  meshPath_ += PATH_CELESTIAL_OBJECT;
  defaultMesh_ = DEFAULT_CELESTIAL_OBJECT;
  defaultMesh_ += _OBJ;
}
CelestialObject::CelestialObject(IAnimatedMeshSceneNode* inode):SpaceObject(inode)
{
  isOrbiting_ = false;
  meshPath_ = PATH_BASE_OBJECT;
  meshPath_ += PATH_CELESTIAL_OBJECT;
  defaultMesh_ = DEFAULT_CELESTIAL_OBJECT;
  defaultMesh_ += _OBJ;
}
CelestialObject::CelestialObject(const f32 scale, const vector3df pos, const vector3df rot, bool lighting):SpaceObject()
{
  isOrbiting_ = false;
  meshPath_ = PATH_BASE_OBJECT;
  meshPath_ += PATH_CELESTIAL_OBJECT;
  defaultMesh_ = DEFAULT_CELESTIAL_OBJECT;
  defaultMesh_ += _OBJ;
  sceneNode_ = sIGfx->getSceneManager ()->addAnimatedMeshSceneNode(
        sIGfx->getSceneManager ()->getMesh(meshPath_+defaultMesh_),
        0, -1, pos, rot, vector3df(1,1,1) * scale);
  sceneNode_->setMaterialFlag(video::EMF_LIGHTING, lighting);  //other than sun, light should collide with it
  sceneNode_->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true); //scaled object
  sceneNode_->getMaterial(0).AmbientColor.set(255,255,255,255);
  sceneNode_->getMaterial(0).DiffuseColor.set(255,0,0,255);
  sceneNode_->getMaterial(0).Shininess = 100.0f;
  sceneNode_->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER , true);
}


void CelestialObject::setOrbit(SpaceObject *parent, const f32 s_major_a, const f32 foci_dist, const f32 initial_rot)
{
  isOrbiting_ = true;
  initialOrientation_ = initial_rot;
  parent_ = parent;
  fociDistance_ = foci_dist;
  semiMajorAxis_ = s_major_a;
  eccentricity_ = foci_dist/s_major_a;
  meanAnomaly_ = 2 * parent->getMass()/1000 * PI / sqrt(s_major_a*s_major_a*s_major_a);   // Speed is dependant on the gravity and the size of the orbit (a*a*a) (Kepler's law)
}

const f32 CelestialObject::eccentricAnomaly(const f32 Mean_time)  //returns the true angle from the circle angle
{
  f32 e0, e1;
  u32 cyc = 0;

  e0 = Mean_time;
  e1 = e0 - eccentricity_ * sin(Mean_time) - Mean_time;

  while (abs(e0 - e1) > 0.01 && (cyc < 6)) {   // 0.01 is the precision between the cycles, 6 is the max cycles
      e1 = e0;
      e0 -= (e0 - eccentricity_ * sin(e0) - Mean_time) / (1 - eccentricity_ * cos(e0));
      cyc++;
    }
  return e0;
}

void CelestialObject::control()
{
  if(isOrbiting_)
  {
    f32 E = eccentricAnomaly(meanAnomaly_ * sIGfx->getTime () + initialOrientation_);
    f32 X = semiMajorAxis_ * (cos(E) - eccentricity_);
    f32 Y = semiMajorAxis_ * sqrt(1 - eccentricity_ * eccentricity_) * sin(E);
    sceneNode_->setRotation(sceneNode_->getRotation() + rotationSpeed_ * sIGfx->getFrameTime ());
    sceneNode_->setPosition(parent_->getPosition() + vector3df(X,0,Y));
  }
  else
    SpaceObject::control();
}


Planet::Planet():CelestialObject(){}
Planet::Planet(IAnimatedMeshSceneNode* inode):CelestialObject(inode){}

Planet::Planet(const u32 type, const f32 scale, const vector3df pos, const vector3df rot):CelestialObject(scale, pos, rot)
{
  texturePath_ = PATH_BASE_TEXTURE;
  texturePath_ += PATH_PLANET_TEXTURE;
  io::path Obj_name = FILE_PLANET_TEXTURE;
  Obj_name += type;
  sceneNode_->setMaterialTexture( 0, sIGfx->getDriver()->getTexture(texturePath_+Obj_name+_JPG) );
}

Moon::Moon():CelestialObject(){}
Moon::Moon(IAnimatedMeshSceneNode* inode):CelestialObject(inode){}

Moon::Moon(const u32 type, const f32 scale, const vector3df pos, const vector3df rot):CelestialObject(scale, pos, rot)
{
  texturePath_ = PATH_BASE_TEXTURE;
  texturePath_ += PATH_MOON_TEXTURE;
  io::path Obj_name = FILE_MOON_TEXTURE;
  Obj_name += type;
  sceneNode_->setMaterialTexture( 0, sIGfx->getDriver()->getTexture(texturePath_+Obj_name+_JPG) );
}

Asteroid::Asteroid():CelestialObject(){}
Asteroid::Asteroid(IAnimatedMeshSceneNode* inode):CelestialObject(inode){}
Asteroid::Asteroid(const u32 type, const f32 scale, const vector3df pos, const vector3df rot):CelestialObject()
{
  texturePath_ = PATH_BASE_TEXTURE;
  texturePath_ += PATH_ASTEROID_TEXTURE;
  meshPath_ = PATH_BASE_OBJECT;
  meshPath_ += PATH_ASTEROID_OBJECT;
  io::path Obj_name = FILE_ASTEROID_TEXTURE;
  Obj_name += type;

  sceneNode_ = sIGfx->getSceneManager ()->addAnimatedMeshSceneNode(
        sIGfx->getSceneManager ()->getMesh(meshPath_+Obj_name+_OBJ),
        0, -1, pos, rot, vector3df(1,1,1) * scale);
  sceneNode_->setMaterialFlag(video::EMF_LIGHTING, true);

  //scene_node->setMaterialTexture( 0, display.driver->getTexture(texture_path+Obj_name+_JPG) ); NO TEXTURES YET
}

Sun::Sun():CelestialObject()
{
  lightRange_ = 0;
  lightColor_ = SColorf(0, 0, 0);
  texturePath_ = PATH_BASE_TEXTURE;
  texturePath_ += PATH_STAR_TEXTURE;
}

Sun::Sun(IAnimatedMeshSceneNode* inode):CelestialObject(inode)
{
  lightRange_ = 0;
  lightColor_ = SColorf(0, 0, 0);
  texturePath_ = PATH_BASE_TEXTURE;
  texturePath_ += PATH_STAR_TEXTURE;
}

Sun::Sun(u32 type, f32 scale, vector3df pos, vector3df rot, SColorf lightcolor, f32 lightrange):CelestialObject(scale, pos, rot, false)
{
  lightColor_ = lightcolor;
  lightRange_ = lightrange;
  texturePath_ = PATH_BASE_TEXTURE;
  texturePath_ += PATH_STAR_TEXTURE;
  io::path Obj_name = FILE_STAR_TEXTURE;
  Obj_name += type;

  sceneNode_->setMaterialTexture( 0, sIGfx->getDriver()->getTexture(texturePath_+Obj_name+_JPG) );
  sceneNode_->setMaterialFlag(video::EMF_LIGHTING, false);  //light will go through it
  sceneNode_->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true); //scaled object

  video::SLight light_data;
  light_data.DiffuseColor = video::SColorf(1.0f, 1.0f, 1.0f);
  light_data.SpecularColor = video::SColorf(0.8f, 0.8f, 0.6f);
  light_data.CastShadows = true;
  light_data.Type = video::ELT_POINT;
  light_data.Attenuation = vector3df(
        0.0f, 1.f/(lightrange*lightrange), 1.f/(lightrange*lightrange));

  ILightSceneNode* il = sIGfx->getSceneManager ()->addLightSceneNode(
        0, pos + vector3df(0, 1.f * scale, 0), lightcolor, lightrange);
  il->setLightData(light_data);
}
