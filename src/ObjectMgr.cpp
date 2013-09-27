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
    map->setId(nextId_++);
  }
  mapList_.insert (map);
}

void ObjectMgr::removeMap (Map *map)
{
  mapList_.erase (mapList_.linear_search (map));
}

void ObjectMgr::addObject (SpaceObject *object, const u16& mapId)
{
  getMap(mapId)->addObject (object);
}

void ObjectMgr::removeObject (SpaceObject *object)
{
  object->getMap ()->removeObject (object);
}

void ObjectMgr::removeObject (const GUID& guid)
{
  removeObject(getObject (guid));
}

const GUID& ObjectMgr::getGUID (const SpaceObject *object) const
{
  return object->getGUID ();
}

Map* ObjectMgr::getMap (const u16& id)
{
  for( Map** it = mapList_.pointer (); *it != mapList_.getLast (); ++it)
  {
    if((*it)->getId() == id)
      return (*it);
  }
  return 0;
}

SpaceObject* ObjectMgr::getObject (const GUID& guid)
{
  for( Map** it = mapList_.pointer (); *it != mapList_.getLast (); ++it)
  {
    SpaceObject* temp = (*it)->getObject (guid);
    if( temp != 0)
      return temp;
  }
  return 0;
}

void ObjectMgr::updateAll ()
{
  for( Map** it = mapList_.pointer (); *it != mapList_.getLast (); ++it)
  {
    (*it)->updateAll();
  }
}
