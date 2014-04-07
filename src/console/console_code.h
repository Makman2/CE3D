// This file is part of CE3D. License: GPL3

#ifndef CE3D_CONSOLE_CONSOLE_CODE_H
#define CE3D_CONSOLE_CONSOLE_CODE_H

#include "console/console.h"

namespace CE3D
{

template<typename... Types>
void Console::WriteString(ConsoleStringAttributes const attr,
                          std::string const str, Types... Args)
{
    attroff(m_CurrentAttributes.GetCursesRepresentation());
    attron(attr.GetCursesRepresentation());

    printw(str, Args...);

    attroff(attr.GetCursesRepresentation());
    attron(m_CurrentAttributes.GetCursesRepresentation());
}

template<typename... Types>
void Console::WriteString(ConsoleIdxType const x, ConsoleIdxType const y,
                 ConsoleStringAttributes const attr, std::string const str,
                 Types... Args)
{
    attroff(m_CurrentAttributes.GetCursesRepresentation());
    attron(attr.GetCursesRepresentation());

    mvrintw(y, x, str, Args...);

    attroff(attr.GetCursesRepresentation());
    attron(m_CurrentAttributes.GetCursesRepresentation());
}

}

#endif /* CE3D_CONSOLE_CONSOLE_CODE_H */
