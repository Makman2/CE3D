// This file is part of CE3D. License: GPL3

#include "CE3D/test/transformation/transformation_test.h"

#include <boost/test/unit_test.hpp>
#include <stdlib.h>

void RequireMatrixEquality(CE3D::Matrix const a, CE3D::Matrix const b)
{
    BOOST_REQUIRE_EQUAL(a.size1(), b.size1()); 
    BOOST_REQUIRE_EQUAL(a.size2(), b.size2());
    for (CE3D::ModelIdxType i = 0; i < a.size1(); ++i)
    {
        for (CE3D::ModelIdxType j = 0; j < a.size2(); ++j)
        {
            BOOST_REQUIRE_EQUAL(a(i,j), b(i,j));
        }
    }
}

void RequireMatrixEquality(CE3D::Matrix const a, CE3D::Matrix const b,
                           CE3D::ModelDataType const tolerance)
{
    BOOST_REQUIRE_EQUAL(a.size1(), b.size1());
    BOOST_REQUIRE_EQUAL(a.size2(), b.size2());
    for (CE3D::ModelIdxType i = 0; i < a.size1(); ++i)
    {
        for (CE3D::ModelIdxType j = 0; j < a.size2(); ++j)
        {
            BOOST_REQUIRE_SMALL(std::abs(a(i,j) - b(i,j)), tolerance);
        }
    }
}

void RequireVectorEquality(CE3D::Vector const a, CE3D::Vector const b)
{
    BOOST_REQUIRE_EQUAL(a.size(), b.size());
    for(CE3D::ModelIdxType i = 0; i < a.size(); ++i)
    {
        BOOST_REQUIRE_EQUAL(a[i], b[i]);
    }
}

void RequireVectorEquality(CE3D::Vector const a, CE3D::Vector const b,
                           CE3D::ModelDataType const tolerance)
{
    BOOST_REQUIRE_EQUAL(a.size(), b.size());
    for(CE3D::ModelIdxType i = 0; i < a.size(); ++i)
    {
        BOOST_REQUIRE_SMALL(std::abs(a[i] - b[i]), tolerance);
    }
}

CE3D::Matrix RandomMatrix
    (CE3D::Matrix::size_type m, CE3D::Matrix::size_type n, unsigned int seed)
{
    CE3D::Matrix mat(m, n);
    srand(seed);

    for (CE3D::Matrix::size_type x = 0; x < mat.size1(); x++)
        for (CE3D::Matrix::size_type y = 0; y < mat.size2(); y++)
            mat(x, y) = rand();
        
    return mat;
}
