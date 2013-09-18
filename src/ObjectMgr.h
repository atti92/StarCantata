#ifndef OBJECTMGR_H
#define OBJECTMGR_H

#include "irrlicht.h"
#include "SpaceObject.h"
#include "Map.h"

class ObjectMgr{
private:
    irr::core::array<Map*> mapList_;
public:
    void updateAll();
    void addObject(SpaceObject* object, irr::u16 mapId);
    void deleteObject(SpaceObject* object);
    void deleteObject(GUID guid);
    GUID getGUID(SpaceObject* object);
    SpaceObject* getObject(GUID guid);
    Map* getMap(irr::u16 id);
};

#endif // OBJECTMGR_H
