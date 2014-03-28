// This file is part of CE3D. License: GPL3

#include "TestEnvironment.h"

#include <iostream>

namespace CE3D {
namespace Testing {

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
