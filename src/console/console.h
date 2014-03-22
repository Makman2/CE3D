// This file is part of CE3D. License: GPL3

#ifndef _CONSOLE_H
#define _CONSOLE_H

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

    void Flush() const;

    ConsoleIdxType GetHeight() const;
    ConsoleIdxType GetWidth() const;
private:
    /**
     * This is a singleton.
     */
    Console();
    Console(const Console& rhs);
    ~Console();

    static Console* s_instance;
};

}

#endif /* _CONSOLE_H */
