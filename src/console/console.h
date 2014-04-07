// This file is part of CE3D. License: GPL3

#ifndef CE3D_CONSOLE_CONSOLE_H
#define CE3D_CONSOLE_CONSOLE_H

#include "util/stdinc.h"

#include <curses.h>
#include <string>
#include <boost/thread.hpp>
#include <boost/signals2/mutex.hpp>

#include "util/functor.h"
#include "console/console_string_attributes.h"

namespace CE3D
{

using ConsoleIdxType = std::uint8_t;

/**
 * This is basically a curses wrapper for C++.
 */
class Console
{
private:
    Console();
    Console(Console const& rhs);

    virtual
    ~Console();

    /**
     * The one and only instance of Console.
     */
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
    static std::shared_ptr<Functor<>> s_Callback;

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

    /**
     * True if terminal supports colors.
     */
    bool m_HasColors;

    /**
     * Initializes all
     */
    void InitColorPairs();
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

    void SetCallback(std::shared_ptr<Functor<>> const Callback)
    { s_Callback = Callback; }

    /**
     * Sets the current attributes.
     *
     * If you write characters without specifying a color, this color will be
     * taken.
     *
     * @param attr The attributes.
     */
    inline void
    SetAttributes(ConsoleStringAttributes const attr)
    { m_CurrentAttributes = attr; }

    /**
     * Determines if the console supports colorized output.
     *
     * @return true if console supports colorized output.
     */
    inline bool
    HasColors() const
    { return m_HasColors; }

    /**
     * Sets the current position.
     *
     * If you write characters without specifying a position, this position
     * will be taken and incremented.
     */
    inline void
    SetPosition(ConsoleIdxType const x, ConsoleIdxType const y)
    { move(y, x); }

    /**
     * Writes a character to the console.
     *
     * @param character The character.
     */
    inline void
    WriteChar(char const character)
    { addch(character); }

    /**
     * Writes a character to the console.
     *
     * @param attr The attributes
     * @param character The character
     */
    void
    WriteChar(ConsoleStringAttributes const attr, char const character);

    /**
     * Writes a character to the console.
     *
     * @param x The row
     * @param y The column
     * @param character The character
     */
    inline void
    WriteChar(ConsoleIdxType const x, ConsoleIdxType const y,
              char const character)
    { mvaddch(y, x, character); }

    /**
     * Writes a character to the console.
     *
     * @param x The row
     * @param y The column
     * @param attr The attributes
     * @param character The character
     */
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

    /**
     * Writes a string to the current position with the given attributes.
     *
     * You can use it printf-like via the variadic template.
     *
     * @param x the row
     * @param y the column
     * @param str the format string
     * @param Args the arguments for the format string
     */
    template<typename... Types>
    inline void
    WriteString(ConsoleIdxType const x, ConsoleIdxType const y,
                std::string const str, Types... Args)
    { mvprintw(y, x, str.c_str(), Args...); }

    /**
     * Writes a string to the current position with the given attributes.
     *
     * You can use it printf-like via the variadic template.
     *
     * @param x the row
     * @param y the column
     * @param attr the attributes
     * @param str the format string
     * @param Args the arguments for the format string
     */
    template<typename... Types>
    void
    WriteString(ConsoleIdxType const x, ConsoleIdxType const y,
                ConsoleStringAttributes const attr, std::string const str,
                Types... Args);

    /**
     * Clears the console.
     */
    void
    Clear() const;

    /**
     * Flushes every change to the console.
     */
    void
    Flush() const;

    /**
     * Gets the height of the console.
     * @return The height.
     */
    inline ConsoleIdxType const&
    GetHeight() const
    { return m_Height; }

    /**
     * Gets the width of the console.
     *
     * @return The width.
     */
    inline ConsoleIdxType const&
    GetWidth() const
    { return m_Width; }
};

}

#include "console/console_code.h"

#endif /* CE3D_CONSOLE_CONSOLE_H */
