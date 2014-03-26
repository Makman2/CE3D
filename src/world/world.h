// This file is part of CE3D. License: GPL3

#ifndef _WORLD_H
#define _WORLD_H

#include <boost/ptr_container/ptr_list.hpp>
#include <boost/container/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/itransformable.h"
#include "model/model.h"

namespace CE3D
{

/**
 * TODO
 */
class World : public Transformation::ITransformable
{
public:
    /**
     * The models the world contains.
     *
     * @return The list of models.
     */
    boost::ptr_list<Model> Models();

    /**
     * The transformations that are applied on render.
     *
     * @return The list of transformation-matrices.
     */
    boost::container::vector<boost::numeric::ublas::matrix<ModelDataType>>
        Transformations();

    /**
     * Transforms all models in the world.
     *
     * @param matrix: The matrix to transform with.
     */
    virtual void Transform(Transformation::Transformation const& matrix);
    /**
     * Translates all models in the world.
     *
     * @param translation: The vector that describes the translation.
     */
    virtual void Translate(Transformation::Translation const& translation);
    /**
     * Scales all models in the world.
     *
     * @param factor: The factor to scale with.
     */
    virtual void Scale(ModelDataType const factor);
    /**
     * Scales all models in the world.
     *
     * @param scale: The vector that describes the scale.
     */
    virtual void Scale(Transformation::Scale const& scale);
    /**
     * Rotates all models in the world.
     *
     * @param planar1: The first vector of the rotation plane.
     * @param planar2: The second vector of the rotation plane.
     * @param offset: The offset of the rotation axis.
     * @param angle: The rotation angle.
     */
    virtual void Rotate(Transformation::Rotation const& rotation);

private:
    boost::ptr_list<Model> m_Models;
    boost::container::vector<boost::numeric::ublas::matrix<ModelDataType>>
        m_Transformations;
};

}

#endif /* _WORLD_H */
