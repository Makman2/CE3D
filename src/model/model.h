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
        boost::container::vector<
            boost::numeric::ublas::vector<ModelDataType>
            > Vectors();

        void Transform(boost::numeric::ublas::matrix<ModelDataType> matrix);
        void Translate(boost::numeric::ublas::vector<ModelDataType>
                           translation);
        void Scale(ModelDataType factor);
        void Scale(boost::numeric::ublas::vector<ModelDataType> scale);
        void Rotate(boost::numeric::ublas::vector<ModelDataType> axis,
                    boost::numeric::ublas::vector<ModelDataType> offset,
                    float angle);
        void RotateX(float angle);
        void RotateY(float angle);
        void RotateZ(float angle);
protected:
        PROPERTY(protected,
            boost::container::vector<
                boost::numeric::ublas::vector<ModelDataType>
                >,
            Vectors);
private:
        PROPERTY(private, bool, IsVisible);
        RW_PROPERTY(private, std::string, Name);
};

}

#endif /* _MODEL_H */
