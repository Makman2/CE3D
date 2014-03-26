// This file is part of CE3D. License: GPL3

#ifndef _MODEL_H
#define _MODEL_H

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
    boost::container::vector<
        boost::numeric::ublas::vector<ModelDataType>
        > m_Vectors;
    bool m_Visible;
    std::string m_Name;


public:
    /**
     * Gets the visibility of the model.
     *
     * @return The visibility state. true if visible, false if not.
     */
    bool IsVisible() const;
    /**
     * Sets the visibility of the model.
     *
     * @param value: The visibility state. true if visible, false if not.
     */
    void SetVisibility(bool const value);
    /**
     * Gets the name of the model.
     *
     * @return The name.
     */
    std::string GetName() const;
    /**
     * Sets the name of the model.
     *
     * @param value: The name to set.
     */
    void SetName(std::string const value);
    /**
     * Transforms all vertices in the model.
     *
     * @param matrix: The transformation to transform with.
     */
    virtual void Transform(Transformation::Transformation const& matrix) override;
    /**
     * Translates all vertices in the model.
     *
     * @param translation: The translate transformation to apply.
     */
    virtual void Translate(Transformation::Translation const& translation) override;
    /**
     * Scales all vertices in the model.
     *
     * @param factor: The factor to scale with.
     */
    virtual void Scale(const ModelDataType factor) override;
    /**
     * Scales all vertices in the model.
     *
     * @param scale: The transformation that describes the scale.
     */
    virtual void Scale(Transformation::Scale const& scale) override;
    /**
     * Rotates all vertices in the model.
     *
     * @param rotation: The rotation transformation to apply.
     */
    virtual void Rotate(Transformation::Rotation const& rotation) override;

    inline boost::container::vector<
        boost::numeric::ublas::vector<ModelDataType>
        > GetVectors() const
    { return m_Vectors; }

};

}

#endif /* _MODEL_H */
