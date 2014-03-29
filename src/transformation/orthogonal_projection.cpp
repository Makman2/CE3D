// This file is part of CE3D. License: GPL3


#include "transformation/orthogonal_projection.h"
#include "util/boost_extensions.h"

namespace CE3D
{
namespace Transformation
{

template<std::size_t N>
void OrthogonalProjection::UpdateMatrix()
{
    // Concatenate vectors together.
    m_Matrix.resize(m_ProjectionVectors[0].size(), m_ProjectionVectors.size());
    for (Matrix::size_type column = 0; column < m_Matrix.size2(); column++)
    {
        for (Matrix::size_type row = 0; row < m_Matrix.size1(); row++)
        {
            m_Matrix(row, column) = m_ProjectionVectors[row];
        }
    }

    Matrix inverted;
    if (boost::numeric::ublas::invert(
        boost::numeric::ublas::trans(m_Matrix) * m_Matrix, inverted
                                     ) == false)
    {
        // Reset on fail.
        m_ProjectionVectors = std::array<Vector, 0>;
        throw std::invalid_argument(
            "The projection vectors are linearly dependent.");
    }

    // On success assign the special matrix product.
    m_Matrix = (m_Matrix * inverted) * boost::numeric::ublas::trans(m_Matrix);

}

template<std::size_t N>
void OrthogonalProjection::SetProjectionVectors(std::array<Vector, N> const& vectors)
{
    // Check range equality of vectors.
    for (std::size_t i = 1; i < m_ProjectionVectors.size(); i++)
    {
        if (m_ProjectionVectors[i - 1].size() != m_ProjectionVectors[i])
            throw std::invalid_argument(
            "The size of the projection vectors vary.");
    }
    
    m_ProjectionVectors = vectors;
    UpdateMatrix();
}

template<std::size_t N>
void OrthogonalProjection::SetProjectionVectors(Vector const& direction)
{
    // Constructing orthogonalized vectors.
    
    Vector orthovecs[] = new Vector[direction.size()];
    // Fill with the standard bases of the R^(n-1).
    for (std::size_t i = 0; i < orthovecs.size(); i++)
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
    m_ProjectionVectors = std::array<Vector, orthovecs.size() - 1>();
    std::size_t remain = 0;

    // Orthogonalize them.
    for (std::size_t i = 0; i < orthovecs.size(); i++)
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