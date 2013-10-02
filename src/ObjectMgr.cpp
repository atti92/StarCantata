#include "ObjectMgr.h"

using namespace irr;
using namespace core;

ObjectMgr::ObjectMgr()
{
  this->nextId_ = 0;
}

ObjectMgr::ObjectMgr(const ObjectMgr &other)
{
  mapList_ = other.getMapList ();
}

ObjectMgr::~ObjectMgr ()
{
  mapList_.clear ();
}

const array<Map*>& ObjectMgr::getMapList () const
{
  return mapList_;
}

void ObjectMgr::addMap (Map *map)
{
  if(map->getId () == 0)
  {
    map->setId(nextId_);
    nextId_++;
  }
  mapList_.insert (map);
}

void ObjectMgr::removeMap (Map *map)
{
  mapList_.erase (mapList_.linear_search (map));
}

void ObjectMgr::clearMaps ()
{
  mapList_.clear ();
  nextId_ = 0;
}

void ObjectMgr::addObject (SpaceObject *object, const u16& mapId)
{
  Map* m = getMap(mapId);
  if(m != 0)
    m->addObject (object);
}

void ObjectMgr::removeObject (SpaceObject *object)
{
  Map* m = object->getMap ();
  if(m != 0)
    m->removeObject (object);
}

void ObjectMgr::removeObject (const GUID& guid)
{
  SpaceObject* o = getObject (guid);
  if(o != 0)
    removeObject(o);
}

const GUID& ObjectMgr::getGUID (const SpaceObject *object) const
{
  return object->getGUID ();
}

Map* ObjectMgr::getMap (const u16& id)
{
  if(mapList_.size () < 1)
    return 0;

  for( Map** it = mapList_.pointer (); it <= &mapList_.getLast (); ++it)
  {
    if((*it)->getId() == id)
      return (*it);
  }
  return 0;
}

SpaceObject* ObjectMgr::getObject (const GUID& guid)
{
  for( Map** it = mapList_.pointer (); it <= &mapList_.getLast (); ++it)
  {
    SpaceObject* temp = (*it)->getObject (guid);
    if( temp != 0)
      return temp;
  }
  return 0;
}

void ObjectMgr::updateAll ()
{
  for( Map** it = mapList_.pointer (); it <= &mapList_.getLast (); ++it)
  {
    (*it)->updateAll();
  }
}
