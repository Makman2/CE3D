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
public:
    /**
     * Constructs an OrthographicCamera from given position, look-at and
     * worlds-up vectors.
     *
     * @param position  The position of the camera.
     * @param look_at   The vector the camera looks at.
     * @param worlds_up The vector that defines the "up" direction.
     */
    OrthographicCamera(Vector const& position,
                       Vector const& look_at,
                       Vector const& worlds_up);

    /**
     * Constructs an OrthographicCamera.
     *
     * @param position   The position of the camera
     * @param projection The list of vectors that define the projection plane
     *                   of the camera.
     */
    OrthographicCamera(Vector const& position,
                       std::vector<Vector> const& projection);

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
     * @param value The new position.
     */
    void
    SetPosition(Vector const& value);

    /**
     * Returns the projection vectors that define the viewing projection plane.
     *
     * @return The list projection vectors.
     */
    std::vector<Vector> const&
    GetProjectionVectors() const;

    /**
     * Sets the projection vectors.
     *
     * @param vectors The projection vectors that define the viewing projection
     *                plane.
     */
    void
    SetProjectionVectors(std::vector<Vector> const& vectors);

    /**
     * Sets the projection vectors using a look-at vector and a worlds-up
     * vector.
     *
     * This method is intended to use for 3-dimensional vectors only. It
     * supports other dimensions as well but missing projection vectors will
     * be computed automatically from the unit-vectors when supplying these.
     *
     * @param look_at   The look-at vector the camera shall look at.
     * @param worlds_up The vector that defines the "up" direction.
     */
    void
    SetProjectionVectors(Vector const& look_at, Vector const& worlds_up);

private:
    /**
     * Constructs a the span list from a look-at and worlds-up vector passed to
     * the OrthogonalDepthProjection.
     *
     * @param look_at   The look-at vector.
     * @param worlds_up The worlds-up vector.
     * @return          The span list.
     */
    static std::vector<Vector>
    ConstructProjection(Vector const& look_at, Vector const& worlds_up);

    Vector m_RealPosition;
};

}

#include "orthographic_camera_code.h"

#endif /* CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_H */
