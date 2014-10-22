// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_ROTATION_H
#define CE3D_TRANSFORMATION_ROTATION_H

#include "CE3D/util/stdinc.h"

#include "CE3D/util/CE3D_vector.h"
#include "CE3D/transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a rotation.
 */
class Rotation : public Transformation
{
public:
    Rotation();
    /**
     * Instantiates a new object.
     *
     * @param planar1: The first rotation plane vector.
     * @param planar2: The second rotation plane vector.
     * @param angle: The rotation angle.
     */
    Rotation(Vector const& planar1, Vector const& planar2, float angle);

    virtual
    ~Rotation();

    /**
     * Returns the first vector that describes the rotation plane.
     *
     * @return The planar vector.
     */
    Vector const&
    GetPlanar1() const;

    /**
     * Returns the second vector that describes the rotation plane.
     *
     * @return The planar vector.
     */
    Vector const&
    GetPlanar2() const;

    /**
     * Returns the rotation angle.
     *
     * @return The angle.
     */
    float
    GetAngle() const;

    /**
     * Sets the first plane-vector.
     *
     * Sets the first planar vector, needed for the description of the
     * rotation plane.
     *
     * @param value: The plane-vector to set.
     */
    void
    SetPlanar1(Vector const& value);

    /**
     * Sets the second plane-vector.
     *
     * Sets the second planar vector, needed for the description of the
     * rotation plane.
     *
     * @param value: The plane-vector to set.
     */
    void
    SetPlanar2(Vector const& value);

    /**
     * Sets the rotation angle.
     *
     * @param value: The rotation angle.
     */
    void
    SetAngle(float value);

protected:
    // Inherited documentation comment
    virtual void
        UpdateMatrix() const override;

private:
    /**
     * One vector describing the rotation plane.
     */
    Vector m_Planar1;
    /**
     * Another vector describing the rotation plane.
     */
    Vector m_Planar2;
    /**
     * The rotation angle.
     */
    float m_Angle;

};

}
}

#endif /* CE3D_TRANSFORMATION_ROTATION_H */
