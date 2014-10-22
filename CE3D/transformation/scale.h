// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_SCALE_H
#define CE3D_TRANSFORMATION_SCALE_H

#include "CE3D/util/stdinc.h"

#include "CE3D/util/CE3D_vector.h"
#include "CE3D/transformation/transformation.h"

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
     * @param scale: The scaling vector containing the scale factor for the
     * n-th dimension in the n-th row.
     */
    Scale(Vector const& scale);

    virtual
    ~Scale();

    /**
     * Sets the scale-vector.
     *
     * @param scale: The scaling vector containing the scale factor for the
     * n-th dimension in the n-th row.
     */
    void
    SetScale(Vector const& scale);

    /**
     * Returns the scale vector.
     *
     * @return The scaling vector containing the scale factor for the
     * n-th dimension in the n-th row.
     */
    Vector const&
    GetScale() const;
};

}
}

#endif /* CE3D_TRANSFORMATION_SCALE_H */
