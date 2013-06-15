#include "Camera.h"

irr::f32 Camera::getCameraYRotation() const
{
    return cameraYRotation;
}

void Camera::setCameraYRotation(const irr::f32 &value)
{
    cameraYRotation = value;
}

irr::f32 Camera::getMinCameraDistance()
{
    return (irr::f32)MIN_CAMERA_DIST;
}

irr::f32 Camera::getMaxCameraDistance()
{
    return (irr::f32)MAX_CAMERA_DIST;
}

void Camera::moveCameraZ(const irr::f32 d)
{
    if(cameraDistance + d < MAX_CAMERA_DIST && cameraDistance + d > MIN_CAMERA_DIST)
        cameraDistance += d;
}

void Camera::rotCameraY(const irr::f32 d)
{
    if(cameraYRotation + d > -(irr::core::PI/2) && cameraYRotation + d < (irr::core::PI/2))
        cameraYRotation += d;
}

void Camera::rotCameraZ(const irr::f32 d)
{
    if(cameraRotation + d > -(irr::core::PI/2) && cameraRotation + d < 0)
        cameraRotation += d;
}

irr::f32 Camera::getCameraRotation() const
{
    return cameraRotation;
}

void Camera::setCameraRotation(const irr::f32 &value)
{
    cameraRotation = value;
}
Camera::Camera()
{
    cameraDistance = 1000;
    cameraRotation = -(irr::core::PI/10);
    cameraYRotation = 0;
}

irr::f32 Camera::getCameraDistance() const
{
    return cameraDistance;
}

void Camera::setCameraDistance(const irr::f32 &value)
{
    cameraDistance = value;
}

