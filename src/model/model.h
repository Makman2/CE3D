// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_MODEL_H
#define CE3D_MODEL_MODEL_H

#include <string>
#include <boost/container/vector.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "util/stdmacro.h"

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
 
    /**
     * Transforms all vertices in the model.
     *
     * @param matrix: The transformation to transform with.
     */
    virtual void
    Transform(Transformation::Transformation const& matrix) override;
   
    /**
     * Translates all vertices in the model.
     *
     * @param translation: The translate transformation to apply.
     */
    virtual void
    Translate(Transformation::Translation const& translation) override;

    /**
     * Scales all vertices in the model.
     *
     * @param factor: The factor to scale with.
     */
    virtual void
    Scale(const ModelDataType factor) override;

    /**
     * Scales all vertices in the model.
     *
     * @param scale: The transformation that describes the scale.
     */
    virtual void
    Scale(Transformation::Scale const& scale) override;

    /**
     * Rotates all vertices in the model.
     *
     * @param rotation: The rotation transformation to apply.
     */
    virtual void
    Rotate(Transformation::Rotation const& rotation) override;

    inline boost::container::vector<Vector> const&
    GetVectors() const
    { return m_Vectors; }

};

}

#endif /* CE3D_MODEL_MODEL_H */
