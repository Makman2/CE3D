// This file is part of CE3D. License: GPL3

#include <boost/numeric/ublas/operation.hpp>

#include "CE3D/transformation/orthogonal_projection.h"
#include "CE3D/util/boost_extensions.h"

namespace CE3D
{
namespace Transformation
{

OrthogonalProjection::OrthogonalProjection()
: m_ProjectionVectors()
{}

OrthogonalProjection::OrthogonalProjection(
    std::vector<Vector> const& projection_vectors)
: m_ProjectionVectors(projection_vectors)
{}

OrthogonalProjection::OrthogonalProjection(Vector const& direction)
: m_ProjectionVectors()
{
    SetProjectionVectors(direction);
}

void OrthogonalProjection::UpdateMatrix() const
{
    // For the math behind this function,
    // see: doc/Orthogonal Projection Matrix.pdf
    // P = (A^T A)^-1 A^T

    // Concatenate vectors together.
    m_Matrix = boost::numeric::ublas::concat_vectors(m_ProjectionVectors);

    Matrix transposed(boost::numeric::ublas::trans(m_Matrix));
    Matrix matxprod(transposed.size1(), m_Matrix.size2());
    Matrix inverted(transposed.size1(), m_Matrix.size2());

    boost::numeric::ublas::axpy_prod(transposed, m_Matrix, matxprod);

    if (boost::numeric::ublas::invert(matxprod, inverted) == false)
    {
        throw std::invalid_argument(
            "The projection vectors are linearly dependent.");
    }


    // On success assign the special matrix product.
    m_Matrix.resize(inverted.size1(), transposed.size2() ,false);
    boost::numeric::ublas::axpy_prod(inverted, transposed, m_Matrix);
}

void OrthogonalProjection::SetProjectionVectors
(std::vector<Vector> const& vectors)
{
    // Check size equality of vectors.
    for (std::size_t i = 1; i < m_ProjectionVectors.size(); i++)
    {
        if (m_ProjectionVectors[i - 1].size() != m_ProjectionVectors[i].size())
            throw std::invalid_argument(
            "The size of the projection vectors vary.");
    }

    m_ProjectionVectors = vectors;

    m_NeedUpdate = true;
}

void OrthogonalProjection::SetProjectionVectors(Vector const& direction)
{
    // Construct orthonormalized vectors.
    std::vector<Vector> vectors;
    vectors.push_back(direction);

    // Push back unit vectors for orthonormalization.
    for (Vector::size_type i = 0; i < direction.size(); i++)
    {
        vectors.push_back(UnitVector(direction.size(), i));
    }

    m_ProjectionVectors = boost::numeric::ublas::orthonormalize(vectors);

    // Delete the first vector because we don't project onto the direction
    // vector (but only if we have projection vectors left).
    if (m_ProjectionVectors.size() > 0)
        m_ProjectionVectors.erase(m_ProjectionVectors.begin());

    // Filtering out the zero vector is not needed because this function call
    // automatically filters zero-vectors.

    m_NeedUpdate = true;
}

}
}
