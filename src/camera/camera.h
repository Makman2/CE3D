// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_CAMERA_H
#define CE3D_CAMERA_CAMERA_H

#include "util/stdinc.h"

#include "world/world.h"

namespace CE3D
{

/**
 * A camera is defined through position, direction and the world it's looking
 * at.
 */
class Camera
{
private:
    /**
     * Holds the world where the camera lives.
     */
    std::weak_ptr<World const> m_World;
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
    virtual std::unique_ptr<World>
    Paint() const = 0;

    virtual
    ~Camera();

    inline std::weak_ptr<World const>
    GetWorld() const
    { return m_World; }

    /**
     * Places the camera in this world.
     *
     * @param copy The world.
     */
    inline void
    SetWorld(std::weak_ptr<World const> const copy)
    { m_World = copy; }
};

}

#endif /* CE3D_CAMERA_CAMERA_H */
