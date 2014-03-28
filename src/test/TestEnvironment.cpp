// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#include <cstdio>

namespace CE3D {
namespace Testing {

std::uint8_t TestEnvironment::s_TestID = 0;

TestEnvironment::TestEnvironment()
{
    m_TestID = ++s_TestID;
    printf("[START:%3u]", m_TestID);
}

TestEnvironment::~TestEnvironment()
{
    printf(" Finish (%u)", m_TestID);
}

} /* namespace Testing */
} /* namespace CE3D */
