// This file is part of CE3D. License: GPL3

#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <curses.h>
#include <string>

#include "util/stdmacro.h"

namespace CE3D
{

using ConsoleIdxType = uint8_t;

using ConsoleColor = enum ConsoleColorEnum
{
    NORMAL
    //TODO list more colors here
};

/**
 * TODO
 */
class Console
{
public:
    /**
     * Returns an instance.
     */
    static Console* GetInstance();

    // TODO write API comments
    void SetColor(ConsoleColor const color);
    void SetPosition(ConsoleIdxType const x, ConsoleIdxType const y);
    void WriteChar(char const character);
    void WriteChar(char const character, ConsoleColor const color);
    void WriteChar(char const character, ConsoleIdxType const x,
                   ConsoleIdxType const y);
    void WriteChar(char const character, ConsoleIdxType const x,
                   ConsoleIdxType const y, ConsoleColor const color);
    void WriteString(std::string const str);
    void WriteString(std::string const str, ConsoleColor const color);
    void WriteString(std::string const str, ConsoleIdxType const x,
                     ConsoleIdxType const y);
    void WriteString(std::string const str, ConsoleIdxType const x,
                     ConsoleIdxType const y, ConsoleColor const color);

    void Clear() const;
    void Flush() const;
private:
    /**
     * This is a singleton.
     */
    Console();
    Console(Console const& rhs);
    ~Console();

    static Console* s_Instance;

    // TODO getter
    ConsoleIdxType m_Height;
    // TODO setter
    ConsoleIdxType m_Width;
    WINDOW* m_Screen;
};

}

#endif /* _CONSOLE_H */
