// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_CUSTOM_H
#define CE3D_TRANSFORMATION_CUSTOM_H

#include "util/stdinc.h"

#include "transformation/transformation.h"
#include "util/CE3D_matrix.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A custom transformation.
 */
class Custom : public Transformation
{
public:

    /**
     * Sets the transformation matrix.
     *
     * @param value: The new matrix.
     */
    inline void
    SetMatrix(Matrix const& value)
    { m_Matrix = value; }
};

}
}

#endif /* CE3D_TRANSFORMATION_CUSTOM_H */
