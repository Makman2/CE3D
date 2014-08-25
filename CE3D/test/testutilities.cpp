// This file is part of CE3D. License: GPL3

#include "CE3D/test/testutilities.h"

#include <boost/test/unit_test.hpp>
#include <stdlib.h>

namespace CE3D
{
namespace Testing
{

bool IsMatrixEqual(CE3D::Matrix const& a, CE3D::Matrix const& b)
{
    if ((a.size1() != b.size1()) || (a.size2() != b.size2()))
        return false;

    for (CE3D::Matrix::size_type i = 0; i < a.size1(); i++)
        for (CE3D::Matrix::size_type j = 0; j < a.size2(); j++)
            if (a(i, j) != b(i, j))
                return false;

    return true;
}

bool IsMatrixEqual(CE3D::Matrix const&       a,
                   CE3D::Matrix const&       b,
                   CE3D::ModelDataType const tolerance)
{
    if ((a.size1() != b.size1()) || (a.size2() != b.size2()))
        return false;

    for (CE3D::Matrix::size_type i = 0; i < a.size1(); i++)
        for (CE3D::Matrix::size_type j = 0; j < a.size2(); j++)
        {
            if (b(i, j) == 0)
            {
                if (a(i, j) != 0)
                    return false;
                else
                    continue;
            }

            if (a(i, j) / b(i, j) < (1 - tolerance) ||
                    a(i, j) / b(i, j) > (1 + tolerance))
                return false;
        }

    return true;
}



bool IsVectorEqual(CE3D::Vector const& a, CE3D::Vector const& b)
{
    if (a.size() != b.size())
        return false;

    for (CE3D::Matrix::size_type i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;

    return true;
}

bool IsVectorEqual(CE3D::Vector const&       a,
                   CE3D::Vector const&       b,
                   CE3D::ModelDataType const tolerance)
{
    if (a.size() != b.size())
        return false;

    for (CE3D::Matrix::size_type i = 0; i < a.size(); i++)
    {
        if (b[i] == 0)
        {
            if (a[i] != 0)
                return false;
            else
                continue;
        }

        if (a[i] / b[i] < (1 - tolerance) || a[i] / b[i] > (1 + tolerance))
            return false;
    }
    
    return true;
}

CE3D::Matrix RandomMatrix(CE3D::Matrix::size_type m,
                          CE3D::Matrix::size_type n,
                          unsigned int            seed)
{
    CE3D::Matrix mat(m, n);
    srand(seed);

    for (CE3D::Matrix::size_type x = 0; x < mat.size1(); x++)
        for (CE3D::Matrix::size_type y = 0; y < mat.size2(); y++)
            mat(x, y) = rand();

    return mat;
}

}
}
