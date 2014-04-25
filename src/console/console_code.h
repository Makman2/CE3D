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
    s_DrawMutex.lock();
    attroff(m_CurrentAttributes.GetCursesRepresentation());
    attron(attr.GetCursesRepresentation());

    printw(str.c_str(), Args...);

    attroff(attr.GetCursesRepresentation());
    attron(m_CurrentAttributes.GetCursesRepresentation());
    s_DrawMutex.unlock();
}

template<typename... Types>
void Console::WriteString(ConsoleIdxType const x, ConsoleIdxType const y,
                 ConsoleStringAttributes const attr, std::string const str,
                 Types... Args)
{
    s_DrawMutex.lock();
    attroff(m_CurrentAttributes.GetCursesRepresentation());
    attron(attr.GetCursesRepresentation());

    mvrintw(y, x, str.c_str(), Args...);

    attroff(attr.GetCursesRepresentation());
    attron(m_CurrentAttributes.GetCursesRepresentation());
    s_DrawMutex.unlock();
}

template<typename... Types>
void Console::WriteString(std::string const str, Types... Args)
{
    s_DrawMutex.lock();
    printw(str.c_str(), Args...);
    s_DrawMutex.unlock();
}

template<typename... Types>
void Console::WriteString(ConsoleIdxType const x, ConsoleIdxType const y,
                          std::string const str, Types... Args)
{
    s_DrawMutex.lock();
    mvprintw(y, x, str.c_str(), Args...);
    s_DrawMutex.unlock();
}

}

#endif /* CE3D_CONSOLE_CONSOLE_CODE_H */
