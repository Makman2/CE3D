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
 *
 * It aims to be easy to use and thread safe.
 *
 * Every instance may set its own attributes while the position is global.
 */
class Console
{
private:
    /**
     * Holds the color which is used for drawing without explicit color
     * argument.
     *
     * Every instance may hold its own attributes.
     */
    ConsoleStringAttributes m_CurrentAttributes;
    static std::uint16_t s_InstanceCount;
    /**
     * Holds the height of the console.
     */
    static ConsoleIdxType s_Height;
    /**
     * Holds the width of the console.
     */
    static ConsoleIdxType s_Width;
    /**
     * Holds the curses "object".
     */
    static WINDOW *s_Screen;
    /**
     * The thread object.
     */
    static boost::thread *s_KeyboardThread;

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
     * This mutex is to ensure that not more than one instance is created out
     * of multiple threads.
     *
     * @attention When locking draw mutex and creation mutex, the creation
     * mutex must be locked first in every case to avoid infinite waiting.
     */
    static boost::signals2::mutex s_CreationMutex;
    /**
     * Ensure that only one instance writes at a time since curses is not
     * necessarily threadsafe.
     *
     * @attention When locking draw mutex and creation mutex, the creation
     * mutex must be locked first in every case to avoid infinite waiting.
     */
    static boost::signals2::mutex s_DrawMutex;
    /**
     * Ensure that only one thread at a time sets the callback since write may
     * be non-atmoic.
     */
    static boost::signals2::mutex s_ThreadSetMutex;
    /**
     * If this is set to true, it's a signal to the keyboard thread to
     * terminate peacefully.
     */
    static bool s_ThreadTerminator;
    /**
     * True if terminal supports colors.
     */
    static bool s_HasColors;
    /**
     * Initializes all
     */
    static void InitColorPairs();
public:
    Console();

    virtual
    ~Console();

    void SetCallback(std::shared_ptr<Functor<>> const Callback)
    { s_Callback = Callback; }//TODO mutex

    /**
     * Sets the current attributes.
     *
     * If you write characters without specifying a color, this color will be
     * taken.
     *
     * @param attr The attributes.
     */
    void
    SetAttributes(ConsoleStringAttributes const attr);

    /**
     * Determines if the console supports colorized output.
     *
     * @return true if console supports colorized output.
     */
    inline bool
    HasColors() const
    { return s_HasColors; }

    /**
     * Sets the current position.
     *
     * If you write characters without specifying a position, this position
     * will be taken and incremented.
     */
    void
    SetPosition(ConsoleIdxType const x, ConsoleIdxType const y);

    /**
     * Writes a character to the console.
     *
     * @param character The character.
     */
    void
    WriteChar(char const character);

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
    void
    WriteChar(ConsoleIdxType const x, ConsoleIdxType const y,
              char const character);

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
    void
    WriteString(std::string const str, Types... Args);

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
    void
    WriteString(ConsoleIdxType const x, ConsoleIdxType const y,
                std::string const str, Types... Args);

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
    inline ConsoleIdxType
    GetHeight() const
    { return s_Height; }

    /**
     * Gets the width of the console.
     *
     * @return The width.
     */
    inline ConsoleIdxType
    GetWidth() const
    { return s_Width; }
};

}

#include "console/console_code.h"

#endif /* CE3D_CONSOLE_CONSOLE_H */
