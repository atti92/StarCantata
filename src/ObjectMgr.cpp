#include "ObjectMgr.h"

using namespace irr;
using namespace core;

ObjectMgr::ObjectMgr()
{
  mapList_ = new array<Map*>();
}

ObjectMgr::ObjectMgr(ObjectMgr other)
{
  mapList_ = new array<Map*>(other.getMapList ());
}

ObjectMgr::~ObjectMgr ()
{
  delete[] mapList_;
}

array<Map*> ObjectMgr::getMapList ()
{
  return mapList_;
}

void ObjectMgr::addMap (Map *map)
{
  mapList_.insert (map);
}

void ObjectMgr::addObject (SpaceObject *object, u16 mapId)
{
  getMap(mapId)->addObject (object);
}

void ObjectMgr::removeObject (SpaceObject *object)
{
  object->getMap ()->removeObject (object);
}

void ObjectMgr::removeObject (GUID guid)
{
  removeObject(getObject (guid));
}

GUID ObjectMgr::getGUID (SpaceObject *object)
{
  return object->getGUID ();
}

Map* ObjectMgr::getMap (u16 id)
{
  for( Map** it = mapList_.pointer (); *it != mapList_.getLast (); ++it)
  {
    if((*it)->getId() == id)
      return (*it);
  }
}

SpaceObject* ObjectMgr::getObject (GUID guid)
{
  for( Map** it = mapList_.pointer (); *it != mapList_.getLast (); ++it)
  {
    SpaceObject* temp = (*it)->getObject (guid);
    if( temp != 0)
      return temp;
  }
}

void ObjectMgr::updateAll ()
{
  for( Map** it = mapList_.pointer (); *it != mapList_.getLast (); ++it)
  {
    (*it)->updateAll();
  }
}
