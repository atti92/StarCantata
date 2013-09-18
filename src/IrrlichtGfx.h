#ifndef IRRLICHTGFX_H
#define IRRLICHTGFX_H

#include "IrrlichtCore.h"
#include "Map.h"
#include "Camera.h"
#include "Gui.h"
#include "ObjectMgr.h"

class IrrlichtGfx : public IrrlichtCore
{
private:
    //Camera Stuff:
    Camera* camera_;
    Gui* gui_;
    ObjectMgr* objectMgr_;
public:
    IrrlichtGfx();
    int drawAll(Map* map);
    int drawAll(irr::u16 mapId);
    Camera* getCamera();
    Gui* getGui();
    ObjectMgr* getObjectMgr();
    irr::u32 getFrameTime();
    void updateTimer();
    ~IrrlichtGfx();
};

#endif // IRRLICHTGFX_H
