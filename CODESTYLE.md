Codestyle for CE3D
==================

This project uses the C++11 standard (aka C++0x).
The rules for code writing in this document are mandantory.
Exceptions are possible if you explain them in a comment and therefore have a
reason.

If you have any suggestions write an e-mail to us. You find the addresses in the
[AUTHORS](AUTHORS) file. Or you can send us a message via GitHub!

Table of Contents
-----------------

* General code style
* Classes
* Functions
* Member variables
* Code sequences
* Templates
* Tests

General code style
------------------

* Every code file starts with this line:

  ```cpp
  // This file is part of CE3D. License: GPL3
  ```

* Space-Indentation with 4 spaces (TAB's are forbidden).

* Every line contains maximum 80 chars (+ line break).

* No right-trailing spaces.

* Every file ends with '\n'.

* ___CamelCase naming___: No '_' and each new word starts with an upper-case
  letter.

  ```cpp
  <typename TemplateType>
  class ThisIsAClass
  {
  public:
      int
      FooBarFunction();
  }
  ```

  Required for

  * all classes and structs.
  * template types.
  * function-names.
  * `typedef`'s and `using`'s.

  ___C-style naming___: Every letter is lower case and words are separated with
  '_' (numbers do not need an underline separator):

  ```cpp
  int
  FooBarFunction(int foo_param, int foo_param2, FooType bar2foo);
  ```

  This naming-convention applies to

  * all function parameters.
  * all non-member variables.

  Exceptions from the above naming rules are

  * member variables (they have modified CamelCase naming).
  * boost extensions.

* Every compilable code lays inside _.cpp_-files (even empty constructors or
  destructors), declarations only lay in _.h_-files and template-code in
  _\_code.h_-files.

* Headers: Use include guards, no `#pragma once`. The name of the include
  guards macro is the path to the source.
  For example: File _mycode.h_ lays in _CE3D/mycode/_. The include guard shall
  look like:

  ```cpp
  #ifndef CE3D_MYCODE_MYCODE_H
  #define CE3D_MYCODE_MYCODE_H

  // Your code...

  #endif /* CE3D_MYCODE_MYCODE_H */
  ```

* No `typedef`'s allowed, only `using`.

  This rule doesn't apply for the C-wrapper (`using`'s doesn't exist in C).

* The root namespace is `CE3D`. No code lays in another namespace.
  Exceptions for this rule are:
  - boost extensions (inside namespace `boost::numeric::ublas`)

* Code inside namespaces is not indented.

  ```cpp
  namespace CE3D
  {
  // your code, unindented
  }
  ```

  The same if you box namespaces:

  ```cpp
  namespace CE3D
  {
  namespace Transformation
  {
  // your code, unindented
  }
  }
  ```

* The braces of scope blocks ({ and }) have it's own lines.

  ```cpp
  int
  Bar()
  { // bracket in separate line
      // ...
  } // and again own line
  ```

  This doesn't apply to empty scope blocks (for example empty function bodies).

  ```cpp
  int
  EmptyBar()
  {}
  ```

* Use `const` when it applies semantically. This includes especially:
  * Idempotent operations
  * Accessor methods

* Use `mutable` and casts if necessary to make your function semantically
  `const`.

* `const` identifier comes __after__ the meant type (so the expression can
  naturally be read from right to left):

  ```cpp
  int const* var; // A pointer to a const int.
  int* const var2; // A const pointer to a non-const int.
  ```

  __Not allowed__ (the common form):

  ```cpp
  const int* var3; // A pointer to a const int.
  ```

* Use `override` keyword when overriding virtual functions to prevent errors.

* Use `final` whenever wise.

* `NULL` macro not allowed anymore, use the builtin keyword `nullptr` instead.

  Again this doesn't apply for the C-wrapper.

* Use `static_assert()` function available since C++11 for compile time
  assertions.

* The includes are ordered in following way:
  ```cpp
  // System includes
  #include <iostream>
  ...

  // CE3D includes (everytime relative to CE3D directory!)
  #include "CE3D/core.h"
  ...

  // Other dependencies.
  ```

* Don't use pointers - use smart pointers instead!
  (See header `<memory>`)

* Non documentation comments: Write `//` and __1__ space. First letter is
  upper-case (like beginning of a sentence) and if you exceed the maximum number
  of chars per line, write the comment into the next line.

  ```cpp
  a.complicated()->piece_of().code = 5; // A single line comment.

  // A very helpful and long description
  // wrapping to the next line.
  a.complicated()->piece_of().code2 = 3;
  ```

* Decimal numbers: Short form is forbidden!

  ```cpp
  auto x = 1.0; // That's okay.
  auto y = 1.; // That's not okay.

  // This rule even applies to zero's and postfixes:
  auto z = 0.f; // Not really right.
  auto w = 0.0f; // That's what's good!
  ```

Classes
-------

* Class declarations reside in header files (_.h_).

* Because this is a library every destructor must be declared as virtual.
  This doesn't apply to classes that are declared as `final`.

* `final` classes do not contain any virtual members.

* Constructors can be leaved out if there are no members to be initialized.

* Classes are documented as follows:

  ```cpp
    /**
     * Brief description.
     *
     * If needed, long description.
     *
     * @tparam T        Type parameter descriptions (if any)...
     *                  Bigger description wraps to next line and is aligned to
     *                  all other params.
     * @tparam AnotherT Another Type description.
     */
    class Foo
    {
        // ...
    }
  ```

* No declaration stands outside an access modifier.
  The order of the access modifiers is:
  1. `public`
  2. `protected`
  3. `private`

  For example:

  ```cpp
  class Foo
  {
  private:
      // private fields.
      // private functions.

  protected:
      // protected functions.

  public:
      // public functions.
  }
  ```

Functions
---------

* Function return type is a line above the name.

  ```cpp
  FooBarType
  bar();
  ```

* Between two function declarations or definitions is at least one new line.
  See example below.

* Between the function name and the parameter braces aren't any spaces.

  ```cpp
  FooBarType
  bar1(); // Very well.

  FooBarType
  bar2 (); // Not very well.

  FooBarType
  bar3  (); // Even worse...
  ```

* Every function declaration shall be documented with following style:

  ```cpp
    /**
     * Brief one-line summary.
     *
     * Detailed documentation.
     *
     * @tparam T   Template parameter.
     *             Align bigger comments like class comments.
     * @tparam ... ...
     * @param P    Function parameters.
     * @param ...  ...
     */
  ```

  If functions returns value, add into the comment body:

  ```cpp
    /**
     * @returns Return value.
     */
  ```

  Inherited documentations can be marked with

  ```cpp
  // Inherited documentation.
  ```

  so you don't need to copy it if the functionality stays the same.
  We encourage to do this to avoid documentation duplication which diminishes
  maintainability.

  __Definitions shall not be documented!__

* If argument list of declarations are too long to fit in one line, they are
  table aligned like this:

  ```cpp
  FooBarType FooBarFunction(FooBarType const& foo_bar1,
                            FooBarType const& foo_bar2,
                            FooBarType        foo,
                            Foo               foo2,
                            FooBar&           foo3);
  ```

Member variables
----------------

* Documented with following way:

  ```cpp
    /**
     * Short description of the member variable.
     *
     * Optional long description.
     */
  ```

* Member variable names are preceeded with ___m____ and the following name is
  named CamelCase.
  For example:

  ```cpp
  int m_ANumber;
  ```

* Member variables are never `protected` nor `public`! To expose them to public
  you must write getters and setters.

  > __Note:__
  >
  > This is not well implemented now, but will be in future.

* Every member variable of a class must be explicitly initialized in an
  initializer list. This looks like following:

  ```cpp
  Foo::Foo()
  : m_Variable1()
  , m_Variable2()
  , m_Variable3()
  {
      // ...
  }
  ```

  Call to base class constructors are allowed and encouraged if needed!

Code sequences
--------------

* Multilinie sequences that doesn't fit into one line are splitted up into
  several lines, where following lines are space-indented. Points (`.`),
  dereference operators (`->`) and other special characters shall wrap to the
  next line:

  ```cpp
  double superlongvar = foo.bar().superlongfunc()
      .continues_here().and_does_something_else()
      ->and_so_on();
  ```

  > __Note:__
  >
  > This is also not really implemented, now it's like "Umm... Yeah I think
  > this looks good...". We will rewrite code to meet this standard.

* Control statements (`for`, `if`, `while` etc): If braces content doesn't fit
  into one line, align the content to the first opening brace of the statement
  \+ one level of space indentation.
  Rules for line wrapping except the indentation are equal to item multiline
  sequences.
  For example:

  ```cpp
  for (int i = 0; i < foo.bar().superlongfunc()
           .continues_now_here(); i++)
  {
      // ...
  }
  ```

  Especially for `if`'s this rule makes code well readable:

  ```cpp
  if (super.ultra.big.members.stacked.together
          .and.it.goes.on.in.next.line() == true)
      if (another.super.super.super.super.super.
              .big.big.big.expression())
          // Your code.
  ```

  For `for`-statements you can also indent like the following example if content
  doesn't fit into one line but each sub-part does.
  The previous example could also be written like this:

  ```cpp
  for (int i = 0;
       i < foo.bar().superlongfunc().continues_now_here();
       i++)
  {
      // ...
  }
  ```

  This style is advised for `for`-loops since it doesn't break the middle of the
  statement and such is better readable.

* Control statements have everytime scope blocks (`{` and `}`), even if there's
  only a single statement in there.

  > __Note:__
  >
  > This rule is new and until now not respected, because there was no need for
  > it earlier. But we ran into cases with ambigous statements, so you were
  > enforced to use scope blocks to tell the compiler to which control statement
  > the code belongs.

* Place __1__ space between control sequences and it's braces.

  ```cpp
  for (...)
  if (...)

  // This is wrong:
  for(...)
  while  (...)
  ```

* Variable names (not member variables) are named C-style.

  > __Note:__
  >
  > This rule is not really realized either. Will be fixed when we make a big
  > code cleanup.

* Unary operators (for example `&`, `*`, `->` and `++`) don't have spaces
  between their associated expressions:

  ```cpp
  int& var; // OK.
  int & var2; // Not OK.
  int const& var3; // OK again.
  int & const var4; // Redundant and not OK.

  int* pointer;
  var = * pointer; // Not OK.
  var2 = *pointer; // OK.
  var3 = &(*pointer); // Also OK.

  Foo x;
  x->func(); // OK.
  x -> func(); // Not OK.

  int i;
  i++; // OK.
  i ++; // Not OK.
  ```

Templates
---------

* Reside a line above declaration/definition.

  For classes:

  ```cpp
  template <typename T>
  class Foo
  {
      // ...
  }
  ```

  The same for functions:

  ```cpp
  template <typename T>
  void
  bar(T t);
  ```

* Add space between `template` and `<`.
  ```cpp
  template<typename T> // Here isn't a space. WRONG!
  template <typename X> // OK, here is one.
  ```

* Double closing template argument braces: Add space between them.

  ```cpp
  template <template <typename T>> // Bad.
  template <template <typename T> > // Good.
  ```

* Try to use `typename` instead of `class` inside template arguments, because
  `class` means that the template argument must be a class! This is most time
  not intended.

* For template-meta-programming there are no rules to align everything
  good-looking, because such declarations/definitions are just too complicated
  to sort them readably. Do what you think looks good.

  > __Note:__
  >
  > Hopefully we find a way to make meta-programming looking better and
  > cleaner, but not now :)

Tests
-----

Every class must be tested. The used testing framework is _Boost_. A component
test looks like this:

```cpp
// This file is part of CE3D. License: GPL3

// Required macros and includes.
#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
// Replace 'YourTest' with the name of your test (as the name suggests).
#define BOOST_TEST_MODULE YourTest
#include <boost/test/unit_test.hpp>

// System includes
#include <vector>

// CE3D includes
#include "CE3D/test/testutilities.h"

// Required namespaces.
namespace CE3D
{
namespace Testing
{

// Required, creates a new fixture test suite.
// Put here the same name for 'YourTest' as you did before.
// TestEnvironment stays TestEnvironment, don't change it.
BOOST_FIXTURE_TEST_SUITE(YourTest, TestEnvironment)

// Here the test body begins.
// Here you can add your tests you need. Don't forget to document.

// Replace 'TestSomething' with the name of the test. The names must begin
// with 'Test'.
// If you use classes inside CE3D namespace, precede them with the CE3D
// namespace, to make clear that this is a component you want to test
// or is not builtin.
/**
 * Tests something.
 */
BOOST_AUTO_TEST_CASE(TestSomething)
{
    CE3D::YourComponent test;
    const int the_value_that_should_be_equal = 3;
    BOOST_REQUIRE_NO_THROW(test.HopefullyNotThrowing());
    BOOST_CHECK_EQUAL(test.HopefullyEqual(), the_value_that_should_be_equal);

    // And so on...
}

// Use as much tests as you want (the more the better).

// And we end the test suite.
BOOST_AUTO_TEST_SUITE_END()

}
}

```

* __Naming__

  The naming of component test cases is CamelCase and is composite of "Test",
  following the class/component-name to test and the tested member function or
  member variable. For example:

  ```cpp
  BOOST_AUTO_TEST_CASE(TestTranslationGetMatrix)
  {
      // ...
  }
  ```

  This tests the `GetMatrix()` function. If you want to test overloads on
  separate test cases, use the argument types to identify the specific overload:

  ```cpp
  BOOST_AUTO_TEST_CASE(TestTranslationGetMatrix_Matrix_int)
  {
      // ...
  }
  ```

  Tests the specific function `GetMatrix(Matrix, int)`.

  * Operators

    Operators are transcribed to words:

    * `+`: Plus
    * `-`: Minus
    * `*`: Multiply (for binary multiplication), Dereference (for unary
      dereference).
    * `/`: Divide
    * `%`: Modulo
    * `++`: PostIncrement, PreIncrement (for postfix and prefix operator).
    * `--`: PostDecrement, PreDecrement (for postfix and prefix operator).
    * `=`: Assign
    * `==`: Equal
    * `!=`: NotEqual
    * `<=`: LessEqual
    * `>=`: GreaterEqual
    * `<`: Less
    * `>`: Greater
    * `&&`: And
    * `||`: Or
    * `!`: Not
    * `&`: BitwiseAnd (for the binary AND), AddressOf (for the unary address-of
      operator).
    * `|`: BitwiseOr
    * `^`: BitwiseXor
    * `~`: BitwiseNot
    * `<<`: LeftShift
    * `>>`: RightShift
    * `.`: Dot
    * `->`: MemberDereference
    * `::`: Qualifier
    * `.*`: DotDereference
    * `->*`: DotMemberDereference
    * `()`: Call
    * `,`: Comma
    * `[]`: Index

    And then named like this:

    ```cpp
    BOOST_AUTO_TEST_CASE(TestTranslationOperatorPlus)
    {
        // ....
    }
    ```

    This tests the function signature `Translation::OperatorPlus(...)`. If you
    want to test overloads, the same naming convention as before applies.

    If a method name is equal to an operator test name, append `_MF` (what
    stands for member function).

  * Component construction

    The construction and destruction of an object must be tested everytime. That
    applies to all constructors. This haappens in the test case
    `Test...Construction`.

    This construction tests use `BOOST_REQUIRE` macros to abort the test
    if construction and destruction were not successful.
    For all other tests use `BOOST_CHECK` or `BOOST_WARN` macros.

If you need help for the [_Boost_ testing framework]
(http://www.boost.org/doc/libs/1_56_0/libs/test/doc/html/index.html), refer to
their sites, it's not as bad documented as the rest.
For examples look into the [CE3D/test](CE3D/test) directory.
