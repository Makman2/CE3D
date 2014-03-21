// This file is part of CE3D. License: GPL3

#ifndef _CONSOLE_H
#define _CONSOLE_H

namespace CE3D
{

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
private:
    /**
     * This is a singleton.
     */
    Console();
    Console(const Console& rhs);
    ~Console();

    static Console* s_instance;
}

}

#endif /* _CONSOLE_H */
