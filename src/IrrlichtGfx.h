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
  Camera* camera_;
  Gui* gui_;
  ObjectMgr* objectMgr_;
  irr::u32 frameTime_, lastUpdatedTime_;
public:
  IrrlichtGfx();
  virtual void initIrrlicht();
  irr::u32 drawAll(Map* map);
  Camera* getCamera();
  Gui* getGui();
  ObjectMgr* getObjectMgr();
  irr::u32 getFrameTime();
  void updateTimer();
  ~IrrlichtGfx();
};

#endif // IRRLICHTGFX_H
