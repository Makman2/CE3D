// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_MODEL_H
#define CE3D_MODEL_MODEL_H

#include "util/stdinc.h"

#include <string>
#include <boost/container/vector.hpp>

#include "util/CE3D_vector.h"
#include "transformation/itransformable.h"

namespace CE3D
{

/**
 * TODO
 */
class Model : public Transformation::ITransformable
{
private:
    boost::container::vector<Vector> m_Vectors;
    bool m_Visible;
    std::string m_Name;


public:
    /**
     * Gets the visibility of the model.
     *
     * @return The visibility state. true if visible, false if not.
     */
    inline bool
    IsVisible() const
    { return m_Visible; }

    /**
     * Sets the visibility of the model.
     *
     * @param value: The visibility state. true if visible, false if not.
     */
    inline void
    SetVisibility(bool const value)
    { m_Visible = value; }

    /**
     * Gets the name of the model.
     *
     * @return The name.
     */
    inline std::string
    GetName() const
    { return m_Name; }

    /**
     * Sets the name of the model.
     *
     * @param value: The name to set.
     */
    inline void
    SetName(std::string const value)
    { m_Name = value; }

    // Inherited documentation comment
    virtual void
    Transform(Transformation::Transformation const& matrix) override;

    // Inherited documentation comment
    virtual void
    Translate(Transformation::Translation const& translation) override;

    // Inherited documentation comment
    virtual void
    Scale(const ModelDataType factor) override;

    // Inherited documentation comment
    virtual void
    Scale(Transformation::Scale const& scale) override;

    // Inherited documentation comment
    virtual void
    Rotate(Transformation::Rotation const& rotation) override;

    /**
     * Returns a list of all vectors of this model.
     */
    inline boost::container::vector<Vector> const&
    GetVectors() const
    { return m_Vectors; }

};

}

#endif /* CE3D_MODEL_MODEL_H */
