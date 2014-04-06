// This file is part of CE3D. License: GPL3

#ifndef CE3D_TEST_TESTENVIRONMENT_H
#define CE3D_TEST_TESTENVIRONMENT_H

#include "util/stdinc.h"

namespace CE3D {
namespace Testing {

/**
 * Provides tearUp and tearDown mechanism for boost unit tests.
 */
class TestEnvironment
{
private:
    /**
     * The ID of this test.
     */
    std::uint8_t m_TestID;
    /**
     * The ID of the last constructed test.
     */
    static std::uint8_t s_TestID;
public:
    TestEnvironment();
    virtual ~TestEnvironment();
};

} /* namespace Testing */
} /* namespace CE3D */

#endif /* CE3D_TEST_TESTENVIRONMENT_H */
