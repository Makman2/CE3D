// This file is part of CE3D. License: GPL3

#ifndef CE3D_WORLD_WORLD_H
#define CE3D_WORLD_WORLD_H

#include "util/stdinc.h"

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
    virtual inline std::vector<std::shared_ptr<Model> > const&
    GetModels() const
    { return m_Models; }

    virtual inline std::vector<std::shared_ptr<
                                   Transformation::Transformation> > const&
    GetTransformations() const
    { return m_Transformations; }

    virtual inline void
    AddModel(std::shared_ptr<Model> Model)
    { m_Models.push_back(Model); }
private:
    std::vector<std::shared_ptr<Model> > m_Models;
    std::vector<std::shared_ptr<Transformation::Transformation> >
        m_Transformations;
};

}

#endif /* CE3D_WORLD_WORLD_H */
