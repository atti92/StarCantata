#ifndef IRRLICHTGFX_H
#define IRRLICHTGFX_H

#include "IrrlichtCore.h"
#include "Map.h"
#include "Camera.h"

class IrrlichtGfx : public IrrlichtCore
{
private:
    irr::core::array<Map*> mapList_;
    //Camera Stuff:
    Camera* camera_;
public:
    int drawAll(Map* map);
    int drawAll(irr::u16 mapId);
    void addObject(SpaceObject* object, irr::u16 mapId);
    void deleteObject(SpaceObject* object);
    void deleteObject(GUID guid);
    GUID getGUID(SpaceObject* object);
    SpaceObject* getObject(GUID guid);
    Map* getMap(irr::u16 id);
    //Camera Stuff:
    Camera* getCamera();
};

#endif // IRRLICHTGFX_H
