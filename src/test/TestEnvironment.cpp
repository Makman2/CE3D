// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#include <iostream>
#include <iomanip>

namespace CE3D {
namespace Testing {

std::uint8_t TestEnvironment::s_TestID = 0;

TestEnvironment::TestEnvironment()
{
    m_TestID = ++s_TestID;
    std::cout << "[START:" << std::setw(3) << m_TestID << "]" << std::flush;
}

TestEnvironment::~TestEnvironment()
{
    std::cout << " FINISHED (" << m_TestID << ")" << std::endl;
}

} /* namespace Testing */
} /* namespace CE3D */
