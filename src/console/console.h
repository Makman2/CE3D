// This file is part of CE3D. License: GPL3

#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <curses.h>
#include <string>

#include "util/stdmacro.h"

namespace CE3D
{

typedef uint8_t ConsoleIdxType;

typedef enum
{
    NORMAL
    //TODO list more colors here
} ConsoleColor;

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
    void SetColor(const ConsoleColor color);
    void SetPosition(const ConsoleIdxType x, const ConsoleIdxType y);
    void WriteChar(const char character);
    void WriteChar(const char character, const ConsoleColor color);
    void WriteChar(const char character, const ConsoleIdxType x,
                   const ConsoleIdxType y);
    void WriteChar(const char character, const ConsoleIdxType x,
                   const ConsoleIdxType y, const ConsoleColor color);
    void WriteString(const std::string str);
    void WriteString(const std::string str, const ConsoleColor color);
    void WriteString(const std::string str, const ConsoleIdxType x,
                     const ConsoleIdxType y);
    void WriteString(const std::string str, const ConsoleIdxType x,
                     const ConsoleIdxType y, const ConsoleColor color);

    void SetCallbackMode(const bool copy);
    void Clear() const;
    void Flush() const;
private:
    /**
     * This is a singleton.
     */
    Console();
    Console(const Console& rhs);
    ~Console();

    R_PROPERTY(private, bool, CallbackMode);

    static Console* s_Instance;

    R_PROPERTY(private, ConsoleIdxType, Height);
    R_PROPERTY(private, ConsoleIdxType, Width);
    PROPERTY(private, WINDOW*, Screen);
};

}

#endif /* _CONSOLE_H */
