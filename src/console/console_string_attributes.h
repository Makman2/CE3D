// This file is part of CE3D. License: GPL3

#ifndef CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_H
#define CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_H

#include "util/stdinc.h"

#include <curses.h>

namespace CE3D {

/**
 * Maps the CURSES colors to our namespace.
 */
enum ConsoleColor
{
    BLACK,
    BLUE,
    CYAN,
    GREEN,
    MAGENTA,
    RED,
    WHITE,
    YELLOW,
    LAST
};

class ConsoleStringAttributes {
private:
    /**
     * The ID of the color pair.
     *
     * It is responsibility of Console to use the ID appropriately.
     */
    std::uint8_t m_ColorPairId;

    /**
     * The other attributes.
     *
     * This may be bold, underlined and so on. Stored curses compatible.
     */
    char m_Attributes;
public:
    ConsoleStringAttributes();
    virtual ~ConsoleStringAttributes();

    /**
     * Sets the color.
     *
     * @param Foreground foreground color
     * @param Background background color
     */
    inline void
    SetColor(ConsoleColor const Foreground, ConsoleColor const Background)
    { m_ColorPairId = ColorPairIndex(Foreground, Background); }

    inline void
    SetColor(std::uint8_t const ColorPairId)
    { m_ColorPairId = ColorPairId; }

    /**
     * Retrieves the ID of the color code combination.
     *
     * @param Foreground foreground color
     * @param Background background color
     * @return the id
     */
    static inline std::uint8_t constexpr
    ColorPairIndex(ConsoleColor const Foreground,
                   ConsoleColor const Background)
    { return 1 + (Background * ConsoleColor::LAST) + Foreground; }
};

} /* namespace CE3D */

#endif /* CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_H */
