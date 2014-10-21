// This file is part of CE3D. License: GPL3

#ifndef CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_CODE_H
#define CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_CODE_H

#include "CE3D/console/console_string_attributes.h"

namespace CE3D
{

std::uint8_t constexpr
ConsoleStringAttributes::ColorPairIndex(ConsoleColor const Foreground,
                                        ConsoleColor const Background)
{
    return 1 + (Background * ConsoleColor::LAST) + Foreground;
}

}

#endif /* CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_CODE_H */
