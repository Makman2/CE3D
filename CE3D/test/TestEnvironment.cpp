// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#include <iostream>
#include <iomanip>

namespace CE3D {
namespace Testing {

std::uint8_t TestEnvironment::s_TestID = 0;

TestEnvironment::TestEnvironment()
{
    m_TestID = ++s_TestID;
    std::cout << "[START:" << std::setw(3)
              << static_cast<unsigned int>(m_TestID) << "]" << std::flush;
    m_Timer.restart();
}

TestEnvironment::~TestEnvironment()
{
    double Elapsed = m_Timer.elapsed();
    std::cout << " FINISHED ("
              << static_cast<unsigned int>(m_TestID)
              << ", " << std::setw(6) << Elapsed*1000000 <<"us)" << std::endl;
}

} /* namespace Testing */
} /* namespace CE3D */
