// This file is part of CE3D. License: GPL3

#ifndef _HEADERNAME_H
#define _HEADERNAME_H

// This file has to be included in every header first
#include <stdmacro.h>

// only include libraries needed for the header!
#include <stdlib1>
//...
#include <stdlibn>

#include <anything/that/lies/in/src/util>

#include "user1"
//...
#include "usern"

namespace CE3D
{
// all C++ symbols are named in CamelCase

// when using integers, only the use of (u)intXX_t is allowed!
typedef AnExistingType SomeIdxType;

class CamelCaseName : BaseClass
{
// definitions within the header are not allowed.
public:
    /**
     * Brief description.
     *
     * Long description. Leave out trivial descriptions espeacially for getters
     * and setters.
     *
     * @param name and a description
     * @return description
     */
    nontrivial_namespace::type NameOfFunction(const another_c_type name) const;
protected:
    // all members have to be private or protected
private:
    // without trailing semicolon!
    // you can access it in the class via m_Name
    /**
     * Property description.
     * 
     * The third parameter is the access modifier where the variable is (this
     * has to match the one which the macro is in!)
     */
    RW_PROPERTY(type, Name, private)
}

} /* namespace CE3D */

// if you use template classes and/or inline functions
#include "headername_code.h"

#endif /* _HEADERNAME_H */
// trailing newline at the end of file!
