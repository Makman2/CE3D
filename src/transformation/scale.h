// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_SCALE_H
#define CE3D_TRANSFORMATION_SCALE_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a scale.
 */
class Scale : public Transformation
{
private:
    boost::numeric::ublas::vector<ModelDataType> m_Scale;
    boost::numeric::ublas::matrix<ModelDataType> m_Matrix;

    void UpdateMatrix();

public:
    inline virtual boost::numeric::ublas::matrix<ModelDataType> const&
    GetMatrix() const
    { return m_Matrix; }


    /**
     * Sets the scale-vector.
     *
     * @param value: The scale-vector to set.
     */
    void SetScale(boost::numeric::ublas::vector<ModelDataType> const& scale);

    /**
     * Returns the scale vector.
     *
     * @return The scale-vector.
     */
    inline boost::numeric::ublas::vector<ModelDataType> const& GetScale() const
    { return m_Scale; }
};

}
}

#endif /* CE3D_TRANSFORMATION_SCALE_H */
