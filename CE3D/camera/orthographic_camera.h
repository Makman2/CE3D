// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_H
#define CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_H

#include "CE3D/util/stdinc.h"

#include "CE3D/camera/linear_camera.h"
#include "CE3D/transformation/orthogonal_projection.h"

namespace CE3D
{

/**
 * A camera is defined through position, direction and the world it's looking
 * at.
 */
template <typename MaterialType>
class OrthographicCamera : public LinearCamera<MaterialType>
{
private:
    Vector m_RealPosition;
    Vector m_LookAt;

public:
    OrthographicCamera();
    /**
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
