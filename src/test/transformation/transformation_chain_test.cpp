// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TransformationChain
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "transformation/transformation_chain.h"

#include <vector>
#include "transformation/custom.h"
#include "test/transformation/transformation_test.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(TransformationChain, TestEnvironment)

/**
 * Tests the container functions of the transformation chain.
 */
BOOST_AUTO_TEST_CASE(TestContainerFunctions)
{
    // Generate random matrices.
    std::vector<CE3D::Matrix> matrices;
    matrices.push_back(RandomMatrix(4, 4, 92823));
    matrices.push_back(RandomMatrix(4, 4, 218983));
    matrices.push_back(RandomMatrix(4, 4, 85772));
    matrices.push_back(RandomMatrix(4, 4, 58));

    CE3D::Transformation::TransformationChain chain;
    // Test PushBack() and Back()
    for (auto elem : matrices)
        BOOST_REQUIRE_NO_THROW(chain.PushBack(CE3D::Transformation::Custom(elem)));
    
    RequireMatrixEquality(chain.Back().GetMatrix(), matrices[3]);

    // Test Size().
    BOOST_REQUIRE_EQUAL(chain.Size(), matrices.size());

    // Test iterators: Begin, Middle, End, RBegin, RMiddle, REnd
    CE3D::Transformation::TransformationChain::size_type i = 0;
    for (auto it = chain.Begin(); it != chain.End(); it++)
    {
        RequireMatrixEquality(it->GetMatrix(), matrices[i]);
        BOOST_REQUIRE_EQUAL(it == chain.Middle(i), true);
        i++;
    }

    i = 0;
    for (auto it = chain.RBegin(); it != chain.REnd(); it++)
    {
        RequireMatrixEquality(it->GetMatrix(), matrices[chain.Size() - 1 - i]);
        BOOST_REQUIRE_EQUAL(it == chain.RMiddle(i), true);
        i++;
    }
    
    BOOST_REQUIRE_THROW(chain.Middle(1111), std::out_of_range);
    BOOST_REQUIRE_THROW(chain.RMiddle(1111), std::out_of_range);

    // Test At() and []-operator
    RequireMatrixEquality(chain.At(0).GetMatrix(), matrices[0]);
    RequireMatrixEquality(chain.At(2).GetMatrix(), matrices[2]);
    RequireMatrixEquality(chain[1].GetMatrix(), matrices[1]);

    // Test Erase()
    //  The call to the index-version automatically invokes the iterator-version,
    //  So both overloaded functions are tested.
    chain.Erase(2);
    BOOST_REQUIRE_EQUAL(chain.Size(), 3);
    RequireMatrixEquality(chain.At(2).GetMatrix(), matrices[3]);

    // Test PushFront() and Front()
    chain.PushFront(CE3D::Transformation::Custom(matrices[1]));
    RequireMatrixEquality(chain.Front().GetMatrix(), matrices[1]);

    // Test Insert()
    //  Again the iterator-version is called when using index-version.
    chain.Insert(CE3D::Transformation::Custom(matrices[0]), 3);
    RequireMatrixEquality(chain[3].GetMatrix(), matrices[0]);

    // Test Replace()
    chain.Replace(CE3D::Transformation::Custom(matrices[3]), 1);
    RequireMatrixEquality(chain[1].GetMatrix(), matrices[3]);

    // Test Clear()
    chain.Clear();
    BOOST_REQUIRE_EQUAL(chain.Size(), 0);

    // Test Swap()
    CE3D::Transformation::TransformationChain newchain;
    for (auto elem : matrices)
        chain.PushBack(CE3D::Transformation::Custom(elem));

    chain.Swap(newchain);
    BOOST_REQUIRE_EQUAL(newchain.Size(), matrices.size());
    BOOST_REQUIRE_EQUAL(chain.Size(), 0);
}

/**
 * Tests the matrix multiplication.
 */
BOOST_AUTO_TEST_CASE(TestGetMatrix)
{
    CE3D::Transformation::TransformationChain chain;
    
    // Instantiate some defined matrices.
    Matrix mat1(3, 3);
    mat1(0, 0) = 2;
    mat1(0, 1) = 4;
    mat1(0, 2) = 3;
    mat1(1, 0) = 9;
    mat1(1, 1) = 4;
    mat1(1, 2) = 1;
    mat1(2, 0) = 8;
    mat1(2, 1) = 1;
    mat1(2, 2) = 8;
    Matrix mat2(3, 3);
    mat2(0, 0) = 4;
    mat2(0, 1) = 1;
    mat2(0, 2) = 1;
    mat2(1, 0) = 1;
    mat2(1, 1) = 1;
    mat2(1, 2) = 1;
    mat2(2, 0) = 1;
    mat2(2, 1) = 1;
    mat2(2, 2) = 1;
    Matrix mat3(3, 3);
    mat3(0, 0) = 0;
    mat3(0, 1) = 7;
    mat3(0, 2) = 2;
    mat3(1, 0) = 2;
    mat3(1, 1) = 1;
    mat3(1, 2) = 3;
    mat3(2, 0) = 0;
    mat3(2, 1) = 0;
    mat3(2, 2) = 3;

    chain.PushBack(CE3D::Transformation::Custom(mat1));
    chain.PushBack(CE3D::Transformation::Custom(mat2));
    chain.PushBack(CE3D::Transformation::Custom(mat3));

    Matrix result(3, 3);
    result(0, 0) = 18;
    result(0, 1) = 114;
    result(0, 2) = 84;
    result(1, 0) = 28;
    result(1, 1) = 301;
    result(1, 2) = 166;
    result(2, 0) = 34;
    result(2, 1) = 304;
    result(2, 2) = 184;

    RequireMatrixEquality(chain.GetMatrix(), result);

    // Test reset
    Matrix mat4(2, 2);
    mat4(0, 0) = 1;
    mat4(0, 1) = 0;
    mat4(1, 0) = 0;
    mat4(1, 1) = 1;

    chain.Clear();
    chain.PushBack(CE3D::Transformation::Custom(mat4));
    
    RequireMatrixEquality(chain.GetMatrix(), mat4);

    // Testing for variable sized matrices.
    Matrix mat5(3, 4);
    mat5(0, 0) = 2;
    mat5(0, 1) = 4;
    mat5(0, 2) = 3;
    mat5(0, 3) = 3;
    mat5(1, 0) = 9;
    mat5(1, 1) = 4;
    mat5(1, 2) = 1;
    mat5(1, 3) = 3;
    mat5(2, 0) = 8;
    mat5(2, 1) = 1;
    mat5(2, 2) = 8;
    mat5(2, 3) = 3;
    Matrix mat6(4, 5);
    mat6(0, 0) = 4;
    mat6(0, 1) = 1;
    mat6(0, 2) = 1;
    mat6(0, 3) = 1;
    mat6(0, 4) = 1;
    mat6(1, 0) = 1;
    mat6(1, 1) = 1;
    mat6(1, 2) = 1;
    mat6(1, 3) = 1;
    mat6(1, 4) = 1;
    mat6(2, 0) = 1;
    mat6(2, 1) = 1;
    mat6(2, 2) = 1;
    mat6(2, 3) = 1;
    mat6(2, 4) = 1;
    mat6(3, 0) = 1;
    mat6(3, 1) = 1;
    mat6(3, 2) = 1;
    mat6(3, 3) = 1;
    mat6(3, 4) = 1;
    Matrix mat7(5, 3);
    mat7(0, 0) = 0;
    mat7(0, 1) = 7;
    mat7(0, 2) = 2;
    mat7(1, 0) = 2;
    mat7(1, 1) = 1;
    mat7(1, 2) = 3;
    mat7(2, 0) = 0;
    mat7(2, 1) = 0;
    mat7(2, 2) = 3;
    mat7(3, 0) = 3;
    mat7(3, 1) = 1;
    mat7(3, 2) = 5;
    mat7(4, 0) = 2;
    mat7(4, 1) = 1;
    mat7(4, 2) = 5;

    chain.Clear();
    chain.PushBack(CE3D::Transformation::Custom(mat5));
    chain.PushBack(CE3D::Transformation::Custom(mat6));
    chain.PushBack(CE3D::Transformation::Custom(mat7));

    Matrix result2(3, 3);
    result2(0, 0) = 84;
    result2(0, 1) = 162;
    result2(0, 2) = 228;
    result2(1, 0) = 119;
    result2(1, 1) = 359;
    result2(1, 2) = 360;
    result2(2, 0) = 140;
    result2(2, 1) = 368;
    result2(2, 2) = 408;

    RequireMatrixEquality(chain.GetMatrix(), result2);    
}


BOOST_AUTO_TEST_SUITE_END()

}
}
