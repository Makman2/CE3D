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
        // TODO: Doxygen comments for all members and functions
        bool IsVisible();
        bool SetVisibility();
        boost::container::vector<boost::numeric::ublas::vector<model_data_t>> Vectors();

        void Transform(boost::numeric::ublas::matrix<model_data_t> matrix);
        void Translate(boost::numeric::ublas::vector<model_data_t> translation);
        void Scale(model_data_t factor);
        void Scale(boost::numeric::ublas::vector<model_data_t> scale);
        void Rotate(boost::numeric::ublas::vector<model_data_t> axis, boost::numeric::ublas::vector<model_data_t> offset, float angle);
        void RotateX(float angle);
        void RotateY(float angle);
        void RotateZ(float angle);
protected:
        boost::container::vector<boost::numeric::ublas::vector<model_data_t>> m_Vectors;
private:
        bool m_IsVisible;
        RW_PROPERTY(private, std::string, Name);
};

}

#endif /* _MODEL_H */
