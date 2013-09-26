#include "MapLoader.h"
#include "Globals.h"
#include "Celestial.h"

using namespace irr;
using namespace core;


void MapLoader::load (io::path path)
{
  Loader::load (path);
  map_ = new Map();
  pugi::xml_node solsys = doc_.child("solsys");
  addChild(0, solsys);
  sIGfx->getObjectMgr ()->addMap (map_);
}

void MapLoader::addChild(SpaceObject* parent, pugi::xml_node parentnode)
{
  for (pugi::xml_node node = parentnode.first_child(); node; node = node.next_sibling())
  {
    SpaceObject* newObj = 0;
    if(strcmp(node.name(),"sun") == 0)
    {
      newObj = new Sun(
            node.attribute("type").as_int(),
            node.attribute("scale").as_float(),
            vector3df(node.attribute("x").as_float(),
                      node.attribute("y").as_float(),
                      node.attribute("z").as_float()
             ),
            vector3df(node.attribute("rotx").as_float(),
                      node.attribute("roty").as_float(),
                      node.attribute("rotz").as_float()
             ),
            SColorf(node.attribute("colR").as_float(),
                    node.attribute("colG").as_float(),
                    node.attribute("colB").as_float()),
            node.attribute("lightrange").as_float());

    }
    else if(strcmp(node.name(),"planet") == 0)
    {
      newObj = new Planet(
            node.attribute("type").as_int(),
            node.attribute("scale").as_float(),
            vector3df(node.attribute("x").as_float(),
                      node.attribute("y").as_float(),
                      node.attribute("z").as_float()),
            vector3df(node.attribute("rotx").as_float(),
                      node.attribute("roty").as_float(),
                      node.attribute("rotz").as_float()));
    }
    else if(strcmp(node.name(),"moon") == 0)
    {
      newObj = new Moon(
            node.attribute("type").as_int(),
            node.attribute("scale").as_float(),
            vector3df(node.attribute("x").as_float(),
                      node.attribute("y").as_float(),
                      node.attribute("z").as_float()),
            vector3df(node.attribute("rotx").as_float(),
                      node.attribute("roty").as_float(),
                      node.attribute("rotz").as_float()));
    }
    else if(strcmp(node.name(),"asteroid") == 0)
    {
      newObj = new Asteroid(
            node.attribute("type").as_int(),
            node.attribute("scale").as_float(),
            vector3df(node.attribute("x").as_float(),
                      node.attribute("y").as_float(),
                      node.attribute("z").as_float()),
            vector3df(node.attribute("rotx").as_float(),
                      node.attribute("roty").as_float(),
                      node.attribute("rotz").as_float()));
    }
    if(newObj){
      if(node.attribute("orbit").as_bool() == true)
      {
        newObj->setOrbit(parent,
                         node.attribute("maja").as_float(),
                         node.attribute("foci").as_float(),
                         node.attribute("phase").as_float());
      }
      newObj->setRotationSpeed(
            vector3df(node.attribute("rotspx").as_float(),
                      node.attribute("rotspy").as_float(),
                      node.attribute("rotspz").as_float()));
      newObj->setMass(node.attribute("mass").as_float());
      map_->addObject (newObj);
    }
    addChild(newObj, node);
  }
}

Map* MapLoader::getMap () const
{
  return map_;
}

