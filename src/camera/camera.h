// This file is part of CE3D. License: GPL3

#ifndef _CAMERA_H
#define _CAMERA_H

#include <string>
#include <boost/container/vector.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "util/stdmacro.h"

#include "world/world.h"

namespace CE3D
{

/**
 * TODO
 */
class Camera
{
public:
    /**
     * Returns the world the camera looks at.
     *
     * @return The world.
     */
    World GetWorld();
    /**
     * Sets the world the camera should look at.
     *
     * @param value: The world to look at.
     */
    void SetWorld(World value);
    
    // FIXME Maybe replace the description with a better one.
    /**
     * Paints the world onto a surface world.
     *
     * The paint() function transforms all models with a projection matrix and stores
     * the transformed vertices into a new world needed for render.
     *
     * @return The projection-transformed world.
     */
    virtual World Paint() = 0;

protected:
    
    
private:
    World m_World;

};

}

#endif /* _CAMERA_H */
