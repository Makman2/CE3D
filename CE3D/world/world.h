// This file is part of CE3D. License: GPL3

#ifndef CE3D_WORLD_WORLD_H
#define CE3D_WORLD_WORLD_H

#include "CE3D/util/stdinc.h"

#include "CE3D/transformation/itransformable.h"
#include "CE3D/model/model.h"
#include "CE3D/util/CE3D_matrix.h"

namespace CE3D
{

/**
 * TODO
 */
template <typename t_Material>
class World : public Transformation::ITransformable
{
public:
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
     *
     * @return the list (constant)
     */
    virtual std::vector<std::shared_ptr<Model<t_Material> > > const&
    GetModels() const
    { return m_Models; }

    /**
     * Adds a model to the list.
     *
     * @param Model a shared_ptr to the Model to add.
     */
    virtual void
    AddModel(std::shared_ptr<Model<t_Material> > Model)
    { m_Models.push_back(Model); }
private:
    /**
     * Every model in this world.
     */
    std::vector<std::shared_ptr<Model<t_Material> > > m_Models;
};

}

#include "CE3D/world/world_code.h"

#endif /* CE3D_WORLD_WORLD_H */
