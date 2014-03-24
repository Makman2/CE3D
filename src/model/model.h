// This file is part of CE3D. License: GPL3

#ifndef _MODEL_H
#define _MODEL_H

#include <string>
#include <boost/container/vector.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "util/stdmacro.h"

namespace CE3D
{

/**
 * TODO
 */
class Model
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
    boost::container::vector<boost::numeric::ublas::vector<model_data_t>> Vectors();

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
    void Transform(const boost::numeric::ublas::matrix<model_data_t> matrix);
    /**
     * Translates all vertices in the model.
     *
     * @param translation: The vector that describes the translation.
     */
    void Translate(const boost::numeric::ublas::vector<model_data_t> translation);
    /**
     * Scales all vertices in the model.
     *
     * @param factor: The factor to scale with.
     */
    void Scale(const model_data_t factor);
    /**
     * Scales all vertices in the model.
     *
     * @param scale: The vector that describes the scale.
     */
    void Scale(const boost::numeric::ublas::vector<model_data_t> scale);
    /**
     * Rotates all vertices in the model.
     *
     * @param planar1: The first vector of the rotation plane.
     * @param planar2: The second vector of the rotation plane.
     * @param offset: The offset of the rotation axis.
     * @param angle: The rotation angle.
     */
    void Rotate(const boost::numeric::ublas::vector<model_data_t> planar1,
        const boost::numeric::ublas::vector<model_data_t> planar2,
        const boost::numeric::ublas::vector<model_data_t> offset, const float angle);



    /**
     * Creates a translation matrix.
     *
     * @param translation: The translation vector."
     * @return A matrix that describes a translation.
     */
    static boost::numeric::ublas::matrix<model_data_t> CreateTranslation(
        boost::numeric::ublas::vector<model_data_t> translation);

    /**
     * Creates a scale matrix.
     *
     * @param scale: The vector that describes the desired scale.
     * @return A matrix that describes a scale.
     */
    static boost::numeric::ublas::matrix<model_data_t> CreateScale(
        const boost::numeric::ublas::vector<model_data_t> scale);

    /**
     * Creates a scale matrix.
     *
     * @param factor: The factor to scale with.
     * @param dimension: The dimension of the matrix.
     * @return A matrix that describes a scale.
     */
    static boost::numeric::ublas::matrix<model_data_t> CreateScale(
        const model_data_t factor,
        const boost::numeric::ublas::vector<model_data_t>::size_type dimension);
    
    /**
     * Creates a rotation matrix.
     *
     * @param planar1: The first vector of the rotation plane.
     * @param planar2: The second vector of the rotation plane.
     * @param ofset: The rotation offset.
     * @param angle: The rotation angle.
     */
    static boost::numeric::ublas::matrix<model_data_t> CreateRotation(
        const boost::numeric::ublas::vector<model_data_t> planar1,
        const boost::numeric::ublas::vector<model_data_t> planar2,
        const boost::numeric::ublas::vector<model_data_t> offset, const float angle);

protected:
    
    
private:
    boost::container::vector<boost::numeric::ublas::vector<model_data_t>> m_Vectors;
    bool m_IsVisible;
    std::string m_Name;
};



}



#endif /* _MODEL_H */
