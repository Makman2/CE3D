// This file is part of CE3D. License: GPL3

#include "util/stdinc.h"

#include "test/transformation/transformation_test.h"
#include "transformation/transformation.h"
#include <boost/test/unit_test.hpp>

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

void RequireVectorEquality(CE3D::Vector const a, CE3D::Vector const b)
{
    BOOST_REQUIRE_EQUAL(a.size(), b.size());
    for(CE3D::ModelIdxType i = 0; i < a.size(); ++i)
    {
        BOOST_REQUIRE_EQUAL(a[i], b[i]);
    }
}
