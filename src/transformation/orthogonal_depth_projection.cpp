// This file is part of CE3D. License: GPL3

#include "transformation/orthogonal_depth_projection.h"
#include "util/boost_extensions.h"

namespace CE3D
{
namespace Transformation
{

void OrthogonalDepthProjection::UpdateMatrix() const
{
    OrthogonalProjection::UpdateMatrix();

    // Append matrix row for depth/distance calculation.
    
    // Constructing orthogonalized vectors.

    auto vecref = GetProjectionVectors();
    auto dimension = vecref.at(0).size();
    Vector* orthovecs = new Vector[dimension];
    // Fill with the standard bases of the R^(n-1).
    for (std::size_t i = 0; i < dimension; i++)
    {
        for (Vector::size_type n = 0; n < dimension; n++)
        {
            if (i == n)
                orthovecs[i](n) = 1.0f;
            else
                orthovecs[i](n) = 0.0f;
        }
    }

    // Setup the new array.
    std::vector<Vector> newbase = std::vector<Vector>(dimension - vecref.size());
    std::size_t remain = 0;

    // Orthogonalize them.
    for (std::size_t i = 0; i < dimension; i++)
    {
        newbase[i - remain] = orthovecs[i];

        for (std::size_t n = 0; n < i - remain; n++)
        {
            ModelDataType inprod;
            inprod = boost::numeric::ublas::inner_prod(
                vecref[n], vecref[n]);
            if (inprod == 0)
            {
                remain++;
                continue;
            }
                
            Vector projvec =
                (boost::numeric::ublas::inner_prod(vecref[n],
                vecref[i]) / inprod) * vecref[n];
            
            newbase[i - remain] -= projvec;
        }

        // Normalize.
        newbase[i - remain] /= boost::numeric::ublas::norm_2(newbase[i - remain]);
    }

    // Calculate matrix row. (Es * N^-1 * (E - A(A^T*A)^-1*A^T))
    Matrix A = boost::numeric::ublas::concat_vectors(vecref);
    Matrix matrixref = GetMatrix();
    Matrix B(A.size1(), matrixref.size2());
    boost::numeric::ublas::axpy_prod(A, matrixref, B);
    B = boost::numeric::ublas::identity_matrix<ModelDataType>(B.size1()) - B;
    
    Matrix C = boost::numeric::ublas::concat_vectors(newbase);
    A.resize(C.size1(), C.size2(), false);
    boost::numeric::ublas::invert(C, A);

    C.resize(A.size1(), B.size2());
    boost::numeric::ublas::axpy_prod(A, B, C);
    
    // Now compute Es * ... and assign directly.
    matrixref.resize(matrixref.size1() + 1, matrixref.size2(), true);
    auto lastrow = matrixref.size1() - 1;

    for (Matrix::size_type column = 0; column < matrixref.size2(); column++)
    {
        matrixref(lastrow, column) = 0;

        for (Matrix::size_type row = 0; row < matrixref.size1(); row++)
        {
            matrixref(lastrow, column) += C(row, column);
        }
    }
}


}
}
