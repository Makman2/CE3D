// This file is part of CE3D. License: GPL3

#ifndef CE3D_CONSOLE_CONSOLE_H
#define CE3D_CONSOLE_CONSOLE_H

#include "util/stdinc.h"

#include <curses.h>
#include <string>
#include <boost/thread.hpp>
#include <boost/signals2/mutex.hpp>

#include "util/functor.h"

namespace CE3D
{

using ConsoleIdxType = uint8_t;

using ConsoleColor = enum ConsoleColorEnum
{
    NORMAL
    //TODO list more colors here
};

class ConsoleStringAttributes
{ // TODO
private:
    ConsoleColor m_Color;
    /**
     * The other attributes.
     *
     * This may be bold, underlined and so on. Stored curses compatible.
     */
    char m_Attributes;
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

    /**
     * Holds the height of the console.
     */
    ConsoleIdxType m_Height;
    /**
     * Holds the width of the console.
     */
    ConsoleIdxType m_Width;
    /**
     * Holds the curses "object".
     */
    WINDOW* m_Screen;
    /**
     * Holds the color which is used for drawing without explicit color
     * argument.
     */
    ConsoleStringAttributes m_CurrentAttributes;

    /**
     * The thread object.
     */
    boost::thread *m_KeyboardThread;

    /**
     * The keyboard thread function that translates the blocking getch of
     * curses to callback events.
     *
     * This function has to be static to be executed as a thread.
     */
    static void KeyboardThread();

    /**
     * The callback function which is called if a keyboard event occurs.
     */
    static Functor<>* s_Callback;

    /**
     * If the thread holds the lock of this mutex, it's doing something
     * important; if not we can kill it.
     *
     * We have to kill it since getch is a blocking invocation.
     */
    static boost::signals2::mutex s_KbThreadMutex;

    /**
     * If this is set to true, it's a signal to the keyboard thread to
     * terminate peacefully.
     */
    static bool s_ThreadTerminator;
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
     * Sets the current color.
     *
     * If you write characters without specifying a color, this color will be
     * taken.
     *
     * @param color The color.
     */
    inline void
    SetColor(ConsoleStringAttributes const attr)
    { m_CurrentAttributes = attr; }

    /**
     * Sets the current position.
     *
     * If you write characters without specifying a position, this position
     * will be taken and incremented.
     */
    inline void
    SetPosition(ConsoleIdxType const x, ConsoleIdxType const y)
    { move(y, x); }

    inline void
    WriteChar(char const character)
    { addch(character); }

    void
    WriteChar(ConsoleStringAttributes const attr, char const character);

    inline void
    WriteChar(ConsoleIdxType const x, ConsoleIdxType const y,
              char const character)
    { mvaddch(y, x, character); }

    void
    WriteChar(ConsoleIdxType const x, ConsoleIdxType const y,
              ConsoleStringAttributes const attr, char const character);

    /**
     * Writes a string to the current position with the current attributes.
     *
     * You can use it printf-like via the variadic template.
     *
     * @param str the format string
     * @param Args the arguments for the format string
     */
    template<typename... Types>
    inline void
    WriteString(std::string const str, Types... Args)
    { printw(str.c_str(), Args...); }

    /**
     * Writes a string to the current position with the given attributes.
     *
     * You can use it printf-like via the variadic template.
     *
     * @param attr the attributes
     * @param str the format string
     * @param Args the arguments for the format string
     */
    template<typename... Types>
    void
    WriteString(ConsoleStringAttributes const attr, std::string const str,
                Types... Args);

    template<typename... Types>
    inline void
    WriteString(ConsoleIdxType const x, ConsoleIdxType const y,
                std::string const str, Types... Args)
    { mvprintw(y, x, str.c_str(), Args...); }

    template<typename... Types>
    void
    WriteString(ConsoleIdxType const x, ConsoleIdxType const y,
                ConsoleStringAttributes const attr, std::string const str,
                Types... Args);

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
