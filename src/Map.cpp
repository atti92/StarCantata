#include "Map.h"
#include "Globals.h"

using namespace irr;
using namespace core;

Map::Map(irr::u16 id)
{
  objects_ = new array<SpaceObject*>();
}

Map::Map(Map other)
{
  objects_ = new array<SpaceObject*>(other.getObjectList);
}

Map::~Map()
{
  delete[] objects_;
}

void Map::saveMapToXml (io::path path)
{

}

void Map::loadMapFromXml (io::path path)
{

}

void Map::addToList ()
{
  sIGfx->getObjectMgr ()->addMap (this);
}

void Map::addObject (SpaceObject *object)
{
  objects_.insert (object);
}

void Map::removeObject (GUID guid)
{
  removeObject (getObject(guid));
}

void Map::removeObject (SpaceObject *object)
{
  objects_.erase (objects_.linear_search (object));
}

u16 Map::getId ()
{
  return id_;
}

void Map::setId (const u16 &id)
{
  id_ = id;
}

SpaceObject* Map::getObject (GUID guid)
{
  for (SpaceObject** it = objects_.pointer (); (*it) != objects_.getLast (); ++it) {
    if((*it)->getGUID () == guid)
      return (*it);
  }
  return 0;
}

void Map::updateAll ()
{
  for (SpaceObject** it = objects_.pointer (); (*it) != objects_.getLast (); ++it) {
    (*it)->control ();
  }
}

array<SpaceObject*> Map::getObjectList()
{
  return objects_;
}
