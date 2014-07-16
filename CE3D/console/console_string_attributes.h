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

/**
 * Attributes for specifying how a string/character is drawn to the console.
 */
class ConsoleStringAttributes {
private:
    /**
     * The ID of the color pair.
     *
     * It is responsibility of Console to use the ID appropriately.
     */
    std::uint16_t m_ColorPairId;

    /**
     * The other attributes.
     *
     * This may be bold, underlined and so on. Stored curses compatible.
     */
    std::uint32_t m_Attributes;
public:
    
    ConsoleStringAttributes()
    : m_ColorPairId(0)
    , m_Attributes(0)
    {};
    virtual
    ~ConsoleStringAttributes() {};

    /**
     * Returns a representation that is recognized by curses' attron/off.
     *
     * @return curses representation for the attributes hold by this object
     */
    std::uint32_t GetCursesRepresentation() const
    { return m_Attributes | COLOR_PAIR(m_ColorPairId); }

    /**
     * Sets the color.
     *
     * @param Foreground foreground color
     * @param Background background color
     */
    void
    SetColor(ConsoleColor const Foreground, ConsoleColor const Background)
    { m_ColorPairId = ColorPairIndex(Foreground, Background); }

    /**
     * Sets the color.
     *
     * @param ColorPairId a color pair id (retrievable by ColorPairIndex)
     */
    void
    SetColor(std::uint8_t const ColorPairId)
    { m_ColorPairId = ColorPairId; }

    /**
     * Retrieves the ID of the color code combination.
     *
     * @param Foreground foreground color
     * @param Background background color
     * @return the id
     */
    static std::uint8_t constexpr
    ColorPairIndex(ConsoleColor const Foreground,
                   ConsoleColor const Background)
    { return 1 + (Background * ConsoleColor::LAST) + Foreground; }
};

} /* namespace CE3D */

#endif /* CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_H */
