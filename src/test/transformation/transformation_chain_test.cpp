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


BOOST_AUTO_TEST_SUITE_END()

}
}
