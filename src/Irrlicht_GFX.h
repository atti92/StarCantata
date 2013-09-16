#ifndef IRRLICHT_GFX_H
#define IRRLICHT_GFX_H

#include "Irrlicht_Core.h"

class Irrlicht_GFX : public Irrlicht_Core
{
private:
    array<IAnimatedMeshSceneNode> objects;
    IAnimatedMeshSceneNode *cameraTarget;
public:
    int FuncDraw_All();
};

#endif // IRRLICHT_GFX_H
