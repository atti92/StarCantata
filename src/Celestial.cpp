#include "Celestial.h"

Celestial::Celestial():SOB()
{
	orbiting = false;
    obj_path = PATH_BASE_OBJECT;
    obj_path += PATH_CELESTIAL_OBJECT;
    default_obj = DEFAULT_CELESTIAL_OBJECT;
    default_obj += _OBJ;
}
Celestial::Celestial(IAnimatedMeshSceneNode* inode):SOB(inode)
{
	orbiting = false;
    obj_path = PATH_BASE_OBJECT;
    obj_path += PATH_CELESTIAL_OBJECT;
    default_obj = DEFAULT_CELESTIAL_OBJECT;
    default_obj += _OBJ;
}
Celestial::Celestial(Display& display, const f32 scale, const vector3df pos, const vector3df rot, bool lighting):SOB()
{
	orbiting = false;
    obj_path = PATH_BASE_OBJECT;
    obj_path += PATH_CELESTIAL_OBJECT;
    default_obj = DEFAULT_CELESTIAL_OBJECT;
    default_obj += _OBJ;
    scene_node = display.smgr->addAnimatedMeshSceneNode(display.smgr->getMesh(obj_path+default_obj), 0, -1, pos, rot, vector3df(1,1,1) * scale);
	scene_node->setMaterialFlag(video::EMF_LIGHTING, lighting);  //other than sun, light should collide with it
	scene_node->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true); //scaled object
	scene_node->getMaterial(0).AmbientColor.set(255,255,255,255);
	scene_node->getMaterial(0).DiffuseColor.set(255,0,0,255);
	scene_node->getMaterial(0).Shininess = 100.0f;
	scene_node->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER , true);
}


void Celestial::setOrbit(SOB *parent, const f32 s_major_a, const f32 foci_dist, const f32 initial_rot)
{
	orbiting = true;
	this->initial_rot = initial_rot;
	this->parent = parent;
	this->foci_dist = foci_dist;
	this->s_major_a = s_major_a;
	eccentricity = foci_dist/s_major_a;
    mean_anomaly = 2 * parent->getMass()/1000 * PI / sqrt(s_major_a*s_major_a*s_major_a);   // Speed is dependant on the gravity and the size of the orbit (a*a*a) (Kepler's law)
}

const f32 Celestial::eccentricAnomaly(const f32 Mean_time)  //returns the true angle from the circle angle
{
	f32 e0, e1;
	u32 cyc = 0;
	f32 prec = 0;

	e0 = Mean_time;
	//else
	//	e0 = PI;
	e1 = e0 - eccentricity * sin(Mean_time) - Mean_time;

	while (abs(e0 - e1) > 0.01 && (cyc < 6)) {   // 0.01 is the precision between the cycles, 6 is the max cycles
		e1 = e0;
		e0 -= (e0 - eccentricity * sin(e0) - Mean_time) / (1 - eccentricity * cos(e0));
		cyc++;
	}
	prec = abs(e0 - e1);
	return e0;
}

void Celestial::refresh(const f32 frameTime, const u32 time)
{
	if(orbiting)
		move(frameTime, time);
	else
		SOB::move(frameTime, time);
}

void Celestial::move(const f32 frameTime, const u32 time)
{
	f32 E = eccentricAnomaly(mean_anomaly * time + initial_rot);
	f32 X = s_major_a * (cos(E) - eccentricity);
	f32 Y = s_major_a * sqrt(1 - eccentricity*eccentricity) * sin(E);
	scene_node->setRotation(scene_node->getRotation() + rot_speed * frameTime);
	scene_node->setPosition(parent->getPosition() + vector3df(X,0,Y));
}

Planet::Planet():Celestial(){}
Planet::Planet(IAnimatedMeshSceneNode* inode):Celestial(inode){}

Planet::Planet(const u32 type, Display& display, const f32 scale, const vector3df pos, const vector3df rot):Celestial(display, scale, pos, rot)
{
    texture_path = PATH_BASE_TEXTURE;
    texture_path += PATH_PLANET_TEXTURE;
    io::path Obj_name = FILE_PLANET_TEXTURE;
	Obj_name += type;
    scene_node->setMaterialTexture( 0, display.driver->getTexture(texture_path+Obj_name+_JPG) );

}

Moon::Moon():Celestial(){}
Moon::Moon(IAnimatedMeshSceneNode* inode):Celestial(inode){}

Moon::Moon(const u32 type, Display& display, const f32 scale, const vector3df pos, const vector3df rot):Celestial(display, scale, pos, rot)
{
    texture_path = PATH_BASE_TEXTURE;
    texture_path += PATH_MOON_TEXTURE;
    io::path Obj_name = FILE_MOON_TEXTURE;
	Obj_name += type;
    scene_node->setMaterialTexture( 0, display.driver->getTexture(texture_path+Obj_name+_JPG) );
}

Asteroid::Asteroid():Celestial(){}
Asteroid::Asteroid(IAnimatedMeshSceneNode* inode):Celestial(inode){}
Asteroid::Asteroid(const u32 type, Display& display, const f32 scale, const vector3df pos, const vector3df rot):Celestial()
{
    texture_path = PATH_BASE_TEXTURE;
    texture_path += PATH_ASTEROID_TEXTURE;
    obj_path = PATH_BASE_OBJECT;
    obj_path += PATH_ASTEROID_OBJECT;
    io::path Obj_name = FILE_ASTEROID_TEXTURE;
	Obj_name += type;

    scene_node = display.smgr->addAnimatedMeshSceneNode(display.smgr->getMesh(obj_path+Obj_name+_OBJ), 0, -1, pos, rot, vector3df(1,1,1) * scale);
	scene_node->setMaterialFlag(video::EMF_LIGHTING, true);

    //scene_node->setMaterialTexture( 0, display.driver->getTexture(texture_path+Obj_name+_JPG) ); NO TEXTURES YET
}

Sun::Sun():Celestial()
{
	lightrange = 0;
	lightcolor = SColorf(0, 0, 0);
    texture_path = PATH_BASE_TEXTURE;
    texture_path += PATH_STAR_TEXTURE;
}
Sun::Sun(IAnimatedMeshSceneNode* inode):Celestial(inode)
{
	lightrange = 0;
	lightcolor = SColorf(0, 0, 0);
    texture_path = PATH_BASE_TEXTURE;
    texture_path += PATH_STAR_TEXTURE;
}
Sun::Sun(u32 type, Display& display, f32 scale, vector3df pos, vector3df rot, SColorf lightcolor, f32 lightrange):Celestial(display, scale, pos, rot, false)
{
	this->lightcolor = lightcolor;
	this->lightrange = lightrange;
    texture_path = PATH_BASE_TEXTURE;
    texture_path += PATH_STAR_TEXTURE;
    io::path Obj_name = FILE_STAR_TEXTURE;
	Obj_name += type;
    scene_node->setMaterialTexture( 0, display.driver->getTexture(texture_path+Obj_name+_JPG) );
	scene_node->setMaterialFlag(video::EMF_LIGHTING, false);  //light will go through it
	scene_node->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true); //scaled object
	video::SLight light_data;
	light_data.DiffuseColor = video::SColorf(1.0f, 1.0f, 1.0f);
	light_data.SpecularColor = video::SColorf(0.8f, 0.8f, 0.6f);
	light_data.CastShadows = true;
	light_data.Type = video::ELT_POINT;
	light_data.Attenuation = vector3df(0.0f, 1.f/(lightrange*lightrange), 1.f/(lightrange*lightrange));

	ILightSceneNode* il = display.smgr->addLightSceneNode(0, pos + vector3df(0, 1.f * scale, 0), lightcolor, lightrange);
	il->setLightData(light_data);
}
