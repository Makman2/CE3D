// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_SCALE_H
#define CE3D_TRANSFORMATION_SCALE_H

#include "util/stdinc.h"

#include "util/CE3D_vector.h"
#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a scale.
 */
class Scale : public Transformation
{
private:
    /**
     * A vector describing the scale.
     *
     * It contains the scale factor for the n-th dimension in the n-th row.
     */
    Vector m_Scale;

protected:

    /**
     * Updates the matrix.
     */
    virtual void
    UpdateMatrix() const override;

public:
    Scale();
    /**
     * Instantiates a new object.
     *
     * @param scale: The scaling vector.
     */
    Scale(Vector const& scale);
    virtual
    ~Scale() {}

    /**
     * Sets the scale-vector.
     *
     * @param scale: The scale-vector to set.
     */
    void
    SetScale(Vector const& scale);

    /**
     * Returns the scale vector.
     *
     * @return The scale-vector.
     */
    Vector const&
    GetScale() const
    { return m_Scale; }
};

}
}

#endif /* CE3D_TRANSFORMATION_SCALE_H */
