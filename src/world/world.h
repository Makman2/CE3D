// This file is part of CE3D. License: GPL3

#ifndef CE3D_WORLD_WORLD_H
#define CE3D_WORLD_WORLD_H

#include "util/stdinc.h"

#include <boost/ptr_container/ptr_list.hpp>

#include "transformation/itransformable.h"
#include "model/model.h"
#include "util/CE3D_matrix.h"

namespace CE3D
{

/**
 * TODO
 */
class World : public Transformation::ITransformable
{
public:
    /**
     * The transformations that are applied on render.
     *
     * @return The list of transformation-matrices.
     */
    boost::container::vector<Matrix>
    Transformations();

    // Inherited documentation comment
    virtual void
    Transform(Transformation::Transformation const& matrix);

    // Inherited documentation comment
    virtual void
    Translate(Transformation::Translation const& translation);

    // Inherited documentation comment
    virtual void
    Scale(ModelDataType const factor);

    // Inherited documentation comment
    virtual void
    Scale(Transformation::Scale const& scale);

    // Inherited documentation comment
    virtual void
    Rotate(Transformation::Rotation const& rotation);

    /**
     * Returns a list of all models in the world.
     */
    virtual inline boost::ptr_list<Model> const&
    GetModels() const
    { return m_Models; }

    virtual inline boost::ptr_list<Transformation::Transformation*> const&
    GetTransformations() const
    { return m_Transformations; }

    virtual inline void
    AddModel(Model* const model)
    { m_Models.push_front(model); }
private:
    boost::ptr_list<Model> m_Models;
    boost::ptr_list<Transformation::Transformation*> m_Transformations;
};

}

#endif /* CE3D_WORLD_WORLD_H */
