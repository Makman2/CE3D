// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_H
#define CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_H

#include "CE3D/util/stdinc.h"

#include "CE3D/camera/linear_camera.h"

namespace CE3D
{

/**
 * A camera for orthographic view. Uses parallel projection for projecting
 * vectors onto it's sensor.
 */
template <typename MaterialType>
class OrthographicCamera : public LinearCamera<MaterialType>
{
private:
    Vector m_RealPosition;
    Vector m_LookAt;

public:
    /**
     * Constructs an OrthographicCamera from given position and
     * look-at vectors.
     *
     * @param lookAt: The vector the camera looks at.
     * @param position: The position of the camera.
     */
    OrthographicCamera(Vector const& lookAt, Vector const& position);

    /**
     * Returns the position of the camera.
     *
     * @return The position.
     */
    Vector const&
    GetPosition() const;

    /**
     * Sets the position of the camera.
     *
     * @param value: The new position.
     */
    void
    SetPosition(Vector const& value);

    /**
     * Returns the looking direction of the camera.
     */
    Vector const&
    GetLookAt() const;

    /**
     * Sets the looking direction of the camera.
     */
    void
    SetLookAt(Vector const& value);


};

}

#include "orthographic_camera_code.h"

#endif /* CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_H */
