#include "Map.h"
#include "Globals.h"

using namespace irr;
using namespace core;

Map::Map(irr::u16 id)
{
  id_ = id;
}

Map::Map(const Map &other)
{
  objects_ = other.getObjectList();
}

Map::~Map()
{
  objects_.empty ();
}

void Map::saveMapToXml (const io::path &path)
{

}

void Map::loadMapFromXml (const io::path &path)
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

void Map::removeObject (const GUID &guid)
{
  removeObject (getObject(guid));
}

void Map::removeObject (SpaceObject *object)
{
  objects_.erase (objects_.linear_search (object));
}

const u16& Map::getId () const
{
  return id_;
}

void Map::setId (const u16 &id)
{
  id_ = id;
}

SpaceObject* Map::getObject (const GUID &guid)
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

const array<SpaceObject*>& Map::getObjectList() const
{
  return objects_;
}
