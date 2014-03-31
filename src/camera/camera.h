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
    World m_World;
public:
    // FIXME Maybe replace the description with a better one.
    /**
     * Paints the world onto a surface world.
     *
     * The paint() function transforms all models with a projection matrix and stores
     * the transformed vertices into a new world needed for render.
     *
     * @return The projection-transformed world.
     */
    virtual World
    Paint() = 0;

    virtual
    ~Camera();

    inline World const&
    GetWorld() const
    { return m_World; }

    inline void
    SetWorld(World const& copy)
    { m_World = copy; }
};

}

#endif /* CE3D_CAMERA_CAMERA_H */
