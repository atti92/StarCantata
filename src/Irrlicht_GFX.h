#ifndef IRRLICHT_GFX_H
#define IRRLICHT_GFX_H

#include "Irrlicht_Core.h"
#include "SOB.h"

class Irrlicht_GFX : public Irrlicht_Core
{
private:
    array<SOB> objects;
    IAnimatedMeshSceneNode *cameraTarget;
    irr::f32 cameraDistance;
    irr::f32 cameraRotation;
    irr::f32 cameraYRotation;
public:
    int Draw_All();
};

#endif // IRRLICHT_GFX_H
