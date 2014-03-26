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
public:
    
    /**
     * Determines whether the model should be rendered or not.
     *
     * @return true if visible, false if not.
     */
    bool IsVisible();
    /**
     * Sets whether the model should be rendered or not.
     *
     * @param value: The visibility state. true for visible, false for hidden.
     */
    void SetVisibility(bool value);
    /**
     * Gets the list of vectors the model contains.
     * 
     * @return The list of vectors.
     */
    boost::container::vector<boost::numeric::ublas::vector<ModelDataType>> Vectors();

    /**
     * Gets the name or ID of the model.
     * 
     * @return The name.
     */
    std::string GetName();
    /**
     * Sets the name or ID of the model.
     * 
     * @param value: The new name.
     */
    void SetName(std::string value);


    /**
     * Transforms all vertices in the model.
     *
     * @param matrix: The matrix to transform with.
     */
    virtual void Transform(Transformation::Transformation const& matrix);
    /**
     * Translates all vertices in the model.
     *
     * @param translation: The vector that describes the translation.
     */
    virtual void Translate(Transformation::Translation const& translation);
    /**
     * Scales all vertices in the model.
     *
     * @param factor: The factor to scale with.
     */
    virtual void Scale(const ModelDataType factor);
    /**
     * Scales all vertices in the model.
     *
     * @param scale: The vector that describes the scale.
     */
    virtual void Scale(Transformation::Scale const& scale);
    /**
     * Rotates all vertices in the model.
     *
     * @param planar1: The first vector of the rotation plane.
     * @param planar2: The second vector of the rotation plane.
     * @param offset: The offset of the rotation axis.
     * @param angle: The rotation angle.
     */
    virtual void Rotate(Transformation::Rotation const& rotation);



    


private:
    boost::container::vector<boost::numeric::ublas::vector<ModelDataType>> m_Vectors;
    bool m_IsVisible;
    std::string m_Name;

};

}

#endif /* _MODEL_H */
