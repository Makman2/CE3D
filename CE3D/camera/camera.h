// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_CAMERA_H
#define CE3D_CAMERA_CAMERA_H

#include "CE3D/world/world.h"

namespace CE3D
{

/**
 * A camera is defined through position, direction and the world it's looking
 * at.
 */
template <typename MaterialType>
class Camera
{
protected:
    /**
     * Holds the world where the camera lives.
     */
    std::shared_ptr<World<MaterialType> const> m_World;
public:
    /**
     * Paints the world onto a surface world.
     *
     * The camera projects any model to a plane. The resulting vectors are to
     * be three-dimensional where the last component shall hold the distance to
     * the plane. This information is only used by the renderer to determine
     * what line is above another. There will be no transformations applied
     * after a world is transformed by the camera. The transformations applied
     * by a camera may be arbitrary.
     *
     * @return The projection-transformed world.
     */
    virtual std::unique_ptr<World<MaterialType> >
    Paint() const = 0;

    virtual
    ~Camera();

    /**
     * Gets the world where this camera lives.
     *
     * @return A shared ptr to the world.
     */
    std::shared_ptr<World<MaterialType> const>
    GetWorld() const;

    /**
     * Places the camera in this world.
     *
     * @param copy The world.
     */
    void
    SetWorld(std::shared_ptr<World<MaterialType> const> const copy);
};

}

#include "camera_code.h"

#endif /* CE3D_CAMERA_CAMERA_H */
