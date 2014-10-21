// This file is part of CE3D. License: GPL3

#ifndef CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_H
#define CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_H

#include <curses.h>

#include "CE3D/util/stdinc.h"

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

    ConsoleStringAttributes();

    virtual
    ~ConsoleStringAttributes();

    /**
     * Returns a representation that is recognized by curses' attron/off.
     *
     * @return curses representation for the attributes hold by this object
     */
    std::uint32_t
    GetCursesRepresentation() const;

    /**
     * Sets the color.
     *
     * @param Foreground foreground color
     * @param Background background color
     */
    void
    SetColor(ConsoleColor const Foreground, ConsoleColor const Background);

    /**
     * Sets the color.
     *
     * @param ColorPairId a color pair id (retrievable by ColorPairIndex)
     */
    void
    SetColor(std::uint8_t const ColorPairId);

    /**
     * Retrieves the ID of the color code combination.
     *
     * @param Foreground foreground color
     * @param Background background color
     * @return the id
     */
    static std::uint8_t constexpr
    ColorPairIndex(ConsoleColor const Foreground,
                   ConsoleColor const Background);
};

} /* namespace CE3D */

#include "console_string_attributes_code.h"

#endif /* CE3D_CONSOLE_CONSOLE_STRING_ATTRIBUTES_H */
