// This file is part of CE3D. License: GPL3

#include <boost/numeric/ublas/operation.hpp>

#include "transformation/orthogonal_projection.h"
#include "util/boost_extensions.h"

namespace CE3D
{
namespace Transformation
{

void OrthogonalProjection::UpdateMatrix()
{
    // For the math behind this function, see: doc/Orthogonal Projection Matrix.pdf
    // P = (A^T A)^-1 A^T

    // Concatenate vectors together.
    m_Matrix = boost::numeric::ublas::concat_vectors(m_ProjectionVectors);
        
    Matrix transposed = boost::numeric::ublas::trans(m_Matrix);
    Matrix matxprod(transposed.size1(), m_Matrix.size2());
    Matrix inverted(transposed.size1(), m_Matrix.size2());

    boost::numeric::ublas::axpy_prod(transposed, m_Matrix, matxprod);

    if (boost::numeric::ublas::invert(matxprod, inverted) == false)
    {
        // Reset on fail.
        m_ProjectionVectors.clear();
        throw std::invalid_argument(
            "The projection vectors are linearly dependent.");
    }


    // On success assign the special matrix product.
    m_Matrix.resize(inverted.size1(), transposed.size2() ,false);   
    boost::numeric::ublas::axpy_prod(inverted, transposed, m_Matrix);
}

void OrthogonalProjection::SetProjectionVectors(std::vector<Vector> const& vectors)
{
    // Check range equality of vectors.
    for (std::size_t i = 1; i < m_ProjectionVectors.size(); i++)
    {
        if (m_ProjectionVectors[i - 1].size() != m_ProjectionVectors[i].size())
            throw std::invalid_argument(
            "The size of the projection vectors vary.");
    }
    
    m_ProjectionVectors = vectors;
    UpdateMatrix();
}

void OrthogonalProjection::SetProjectionVectors(Vector const& direction)
{
    // Constructing orthogonalized vectors.
    
    Vector* orthovecs = new Vector[direction.size()];
    // Fill with the standard bases of the R^(n-1).
    for (std::size_t i = 0; i < direction.size(); i++)
    {
        for (Vector::size_type n = 0; n < direction.size(); n++)
        {
            if (i == n)
                orthovecs[i](n) = 1.0f;
            else
                orthovecs[i](n) = 0.0f;
        }
    }

    // Setup the new array.
    m_ProjectionVectors = std::vector<Vector>(direction.size() - 1);
    std::size_t remain = 0;

    // Orthogonalize them.
    for (std::size_t i = 0; i < direction.size(); i++)
    {
        m_ProjectionVectors[i - remain] = orthovecs[i];

        Vector projvec = 
            (boost::numeric::ublas::inner_prod(direction, m_ProjectionVectors[i]) /
            (boost::numeric::ublas::inner_prod(direction, direction))) * direction;
        
        m_ProjectionVectors[i]  -= projvec;
        

        for (std::size_t n = 0; n < i - remain; n++)
        {
            ModelDataType inprod;
            inprod = boost::numeric::ublas::inner_prod(
                m_ProjectionVectors[n], m_ProjectionVectors[n]);
            if (inprod == 0)
            {
                remain++;
                continue;
            }
                
            projvec =
                (boost::numeric::ublas::inner_prod(m_ProjectionVectors[n],
                m_ProjectionVectors[i]) / inprod) * m_ProjectionVectors[n];
            
            m_ProjectionVectors[i] -= projvec;
        }
    }

    UpdateMatrix();
}

}
}
