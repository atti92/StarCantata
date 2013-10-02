#ifndef OBJECTMGR_H
#define OBJECTMGR_H

#include "irrlicht.h"
#include "SpaceObject.h"
#include "Map.h"

class ObjectMgr{
private:
  irr::core::array<Map*> mapList_;
  irr::u16 nextId_;
public:
  ObjectMgr();
  ObjectMgr(const ObjectMgr& other);
  const irr::core::array<Map*>& getMapList() const;
  ~ObjectMgr();
  void updateAll();
  void addMap(Map* map);
  void removeMap(Map* map);
  void clearMaps();
  void addObject(SpaceObject* object, const irr::u16& mapId = 0);
  void removeObject(SpaceObject* object);
  void removeObject(const GUID& guid);
  const GUID& getGUID(const SpaceObject* object) const;
  SpaceObject* getObject(const GUID& guid);
  Map* getMap(const irr::u16& id);
};

#endif // OBJECTMGR_H
