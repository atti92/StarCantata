#ifndef CAMERA_H
#define CAMERA_H

#include "irrlicht.h"

enum CameraConsts
{
    MIN_CAMERA_DIST = 100,
    MAX_CAMERA_DIST = 2000
};

class Camera{
    irr::f32 cameraDistance;
    irr::f32 cameraRotation;
    irr::f32 cameraYRotation;
public:
    Camera();
    irr::f32 getCameraDistance() const;
    void setCameraDistance(const irr::f32 &value);
    irr::f32 getCameraRotation() const;
    void setCameraRotation(const irr::f32 &value);
    irr::f32 getCameraYRotation() const;
    void setCameraYRotation(const irr::f32 &value);
    static irr::f32 getMinCameraDistance();
    static irr::f32 getMaxCameraDistance();
    void moveCameraZ(const irr::f32 d = 0);
    void rotCameraY(const irr::f32 d = 0);
    void rotCameraZ(const irr::f32 d = 0);
};

#endif // CAMERA_H
