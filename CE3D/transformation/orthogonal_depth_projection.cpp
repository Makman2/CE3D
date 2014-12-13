// This file is part of CE3D. License: GPL3

#include "CE3D/transformation/orthogonal_depth_projection.h"
#include "CE3D/util/boost_extensions.h"

namespace CE3D
{
namespace Transformation
{

OrthogonalDepthProjection::OrthogonalDepthProjection()
{}

OrthogonalDepthProjection::OrthogonalDepthProjection(Vector const& lookat)
: OrthogonalProjection(lookat)
{}

OrthogonalDepthProjection::OrthogonalDepthProjection(
    std::vector<Vector> const& projection_vectors)
    : OrthogonalProjection(projection_vectors)
{}

OrthogonalDepthProjection::~OrthogonalDepthProjection()
{}

void OrthogonalDepthProjection::UpdateMatrix() const
{
    // For the math behind this function, see:
    // doc/Orthogonal Projection.pdf

    // Update the projection matrix for orthogonal projection. The computed
    // matrix is stored in m_Matrix.
    OrthogonalProjection::UpdateMatrix();

    // Constructing unit vectors for rest orthonormalization.
    auto vecs = GetProjectionVectors();
    std::vector<CE3D::Vector>::size_type inputvec_count = vecs.size();

    CE3D::Vector::size_type dimension = vecs[0].size();
    for (CE3D::Vector::size_type i = 0; i < dimension; i++)
        vecs.push_back(UnitVector(dimension, i));

    // Orthonormalize the vectors with filtered out zero vectors. Need to
    // filter out only the first input vectors.
    auto orthonormalized = boost::numeric::ublas::orthonormalize(vecs);


    // Construct and append the depth calculation matrix row.
    // T = Sum(n) * M = Sum(n) * (E - P) = Sum(n) * (E - A(A^T A)^-1 A^T

    // First premultiply the base matrix with A, so we don't get the
    // coefficients.

    Matrix A = boost::numeric::ublas::concat_vectors(GetProjectionVectors());
    Matrix P(A.size1(), m_Matrix.size2());
    boost::numeric::ublas::axpy_prod(A, m_Matrix, P, true);

    // Use P for further calculation.
    P = IdentityMatrix(P.size1()) - P; // P equals M in the equation.

    // Sum up the normal vectors.
    Vector nsum = ZeroVector(orthonormalized[0].size());
    for (auto it = orthonormalized.begin() + inputvec_count;
         it != orthonormalized.end(); it++)
        nsum += *it;

    // At least calculate the last row (that now is transpoed into a vector
    // because of not matching function signatures if not doing so).
    Vector lastrow(nsum.size());
    boost::numeric::ublas::axpy_prod(
        boost::numeric::ublas::trans(P), nsum, lastrow, true);

    // Resize and preserve the calculated array from our base and append our
    // new row (/transposed column vector).
    m_Matrix.resize(m_Matrix.size1() + 1, m_Matrix.size2(), true);
    boost::numeric::ublas::matrix_row<Matrix> subslice(
        m_Matrix, m_Matrix.size1() - 1);

    subslice = lastrow;
}


}
}
