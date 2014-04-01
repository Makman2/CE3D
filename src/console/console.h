// This file is part of CE3D. License: GPL3

#ifndef CE3D_CONSOLE_CONSOLE_H
#define CE3D_CONSOLE_CONSOLE_H

#include "util/stdinc.h"

#include <curses.h>
#include <string>

namespace CE3D
{

using ConsoleIdxType = uint8_t;

using ConsoleColorEnum = enum _ConsoleColor
{
    NORMAL
    //TODO list more colors here
};

class ConsoleColor
{ // TODO
};

/**
 * This is basically a curses wrapper for C++.
 */
class Console
{
private:
    /**
     * This is a singleton.
     */
    Console();

    Console(Console const& rhs);

    virtual
    ~Console();

    static Console* s_Instance;

    ConsoleIdxType m_Height;
    ConsoleIdxType m_Width;
    WINDOW* m_Screen;
public:
    /**
     * Returns an instance.
     *
     * If there is no instance yet it will be created, a curses session will
     * be started.
     */
    static Console*
    GetInstance();

    /**
     * Deletes the instance and returns to normal console mode.
     */
    static void
    DeleteInstance();

    /**
     * Sets the color.
     *
     * If you write characters without specifying a color, this color will be
     * taken.
     *
     * @param color The color.
     */
    void
    SetColor(ConsoleColor const color);

    void
    SetPosition(ConsoleIdxType const x, ConsoleIdxType const y);

    void
    WriteChar(char const character);

    void
    WriteChar(char const character, ConsoleColor const color);

    void
    WriteChar(char const character, ConsoleIdxType const x,
              ConsoleIdxType const y);

    void
    WriteChar(char const character, ConsoleIdxType const x,
              ConsoleIdxType const y, ConsoleColor const color);

    void
    WriteString(std::string const str);

    void
    WriteString(std::string const str, ConsoleColor const color);

    void
    WriteString(std::string const str, ConsoleIdxType const x,
                ConsoleIdxType const y);

    void
    WriteString(std::string const str, ConsoleIdxType const x,
                ConsoleIdxType const y, ConsoleColor const color);

    void
    Clear() const;

    void
    Flush() const;

    inline ConsoleIdxType const&
    GetHeight() const
    { return m_Height; }

    inline ConsoleIdxType const&
    GetWidth() const
    { return m_Width; }
};

}

#endif /* CE3D_CONSOLE_CONSOLE_H */
