// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_BOOST_EXTENSIONS_H
#define CE3D_UTIL_BOOST_EXTENSIONS_H

#include <type_traits>
#include <array>
#include <limits>

// This macro is except of the rest of the document under the
// Attribution-ShareAlike 3.0 Unported license
// (http://creativecommons.org/licenses/by-sa/3.0/). You're allowed to copy and
// redistribute the material in any medium format and modify as you wish when
// giving the appropriate credit and distribute as the same license.
// It builts upon the code in
// http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Member_Detector, last
// modified on 10. June 2014 at 21:18.
/**
 * Defines a structure to test whether a class contains a specific function.
 *
 * This macro creates a new structure with the ability to test the existence
 * of a function of your choice. Important: You have to put the structure
 * outside the function definition because C++11 doesn't support struct
 * defintions with template arguments inside a scope block.
 *
 * For example (test if the function 'void clear()' exists):
 * DEFINE_FUNCTION_DETECTOR_MANUALLY(clear, has_clear);
 * std::cout << has_clear<std::vector<float>, void()>::value << std::endl;
 * This snippet prints out '1'.
 * Some bigger example with parameters (test for function
 * 'int xyz(float, double)'):
 * DEFINE_FUNCTION_DETECTOR_MANUALLY(xyz, has_xyz);
 * struct XYW { void xyz(float, double); };
 * struct XYZ { int xyz(float, double); };
 * std::cout << has_xyz<XYW, int(float, double)>::value << std::endl;
 * std::cout << has_xyz<XYZ, int(float, double)>::value << std::endl;
 * This prints out '0' and '1'. The first function definition doesn't agree in
 * return type.
 *
 * @param func_name The function to test.
 * @param struct_id An ID to give the template structure a name. Typically
 * 'has_' + the function name.
 */
#define DEFINE_FUNCTION_DETECTOR_MANUALLY(func_name, struct_id)            \
    template<typename, typename T>                                         \
    struct struct_id                                                       \
    {                                                                      \
        static_assert(std::integral_constant<T, false>::value,             \
                      "Second template parameter needs to be of function " \
                      "type.");                                            \
    };                                                                     \
                                                                           \
    template<typename C, typename Returns, typename... Args>               \
    struct struct_id<C, Returns(Args...)>                                  \
    {                                                                      \
    private:                                                               \
        template<typename T>                                               \
        static constexpr auto check(T*)                                    \
        -> typename std::is_same<decltype(std::declval<T>()                \
               .func_name(std::declval<Args>()...)),                       \
           Returns>::type;                                                 \
                                                                           \
        template<typename>                                                 \
        static constexpr std::false_type check(...);                       \
                                                                           \
        using type = decltype(check<C>(0));                                \
                                                                           \
    public:                                                                \
        static constexpr bool value = type::value;                         \
    }

/**
 * Defines a meta-structure to test whether a class contains a specific
 * function.
 *
 * This macro expands to DEFINE_FUNCTION_DETECTOR_MANUALLY and passes as
 * struct_id 'has_[func_name]'.
 *
 * @param func_name The function name to check for existence.
 * @see             DEFINE_FUNCTION_DETECTOR_MANUALLY
 */
#define DEFINE_FUNCTION_DETECTOR(func_name) \
    DEFINE_FUNCTION_DETECTOR_MANUALLY(func_name, has_##func_name)

/**
 * Defines a meta-function that calls the given function when template
 * parameter is true. A template parameter of false evaluates to an empty
 * function. This macro is useful when calling a function from that you don't
 * know it can exist.
 * For example: Consider a template function with template parameter T. You
 * want this function to call T.AMethod(), but only if it exists. If not you
 * want to skip it. There comes this macro in place. You can just try to
 * invoke T.AMethod(), but the compilation will fail when T.AMethod() doesn't
 * exist. The macro creates two functions, that instantiates the function only
 * if needed, so compiler errors can be avoided. In this example you have to
 * apply the macro as following.
 * DEFINE_FUNCTION_DETECTOR(AMethod);
 * DEFINE_FUNCTION_JACKER_MANUALLY(AMethod, call_AMethod_if)
 * template <typename T>
 * void AFunc()
 * {
 *     CustomClass a;
 *     call_AMethod_if<has_AMethod<CustomClass, void()>::value>();
 *     // Do some other stuff with a...
 * }
 * So if CustomClass doesn't provide a signature for 'void AMethod()', the
 * call ends in an empty function and nothing happens.
 * If needed arguments are automatically deduced from calling parameters (and
 * passed to the function).
 *
 * Important: Do not write an ';' at the end of the macro!
 *
 * @param func    The function name attempting to call.
 * @param func_id The name of the function jacker.
 *
 */
#define DEFINE_FUNCTION_JACKER_MANUALLY(func, func_id) \
    template <bool B, typename T, typename... Args>    \
    typename std::enable_if<!B, void>::type            \
    func_id(T&, Args...)                               \
    {}                                                 \
                                                       \
    template <bool B, typename T, typename... Args>    \
    typename std::enable_if<B, void>::type             \
    func_id(T& obj, Args... args)                      \
    {                                                  \
        obj.func(args...);                             \
    }

/**
 * Defines a meta-function that calls the given function when template
 * parameter is true. A template parameter of false evaluates to an empty
 * function.
 *
 * This macro expands to DEFINE_FUNCTION_JACKER_MANUALLY and passes as
 * func_id 'call_[func]_if'.
 *
 * Important: Do not write an ';' at the end of the macro!
 *
 * @param func The function name attempting to call.
 * @see        DEFINE_FUNCTION_JACKER_MANUALLY
 */
#define DEFINE_FUNCTION_JACKER(func)              \
    DEFINE_FUNCTION_JACKER_MANUALLY(func,         \
    BOOST_PP_CAT(call_, BOOST_PP_CAT(func, _if)))


namespace boost
{
namespace numeric
{
namespace ublas
{
namespace help_traits
{

// Needed function detectors and code jackers for
// orthogonalize() and orthonormalize().
DEFINE_FUNCTION_DETECTOR(reserve);
DEFINE_FUNCTION_DETECTOR(push_back);
DEFINE_FUNCTION_DETECTOR_MANUALLY(operator[], has_array_accessor);

DEFINE_FUNCTION_JACKER(reserve)
DEFINE_FUNCTION_JACKER(push_back)

template <bool B, typename T, typename AssignType, typename... Args>
typename std::enable_if<!B, void>::type
call_array_accessor_and_set_if(T&, AssignType&, Args...)
{}

template <bool B, typename T, typename AssignType, typename... Args>
typename std::enable_if<B, void>::type
call_array_accessor_and_set_if(T& obj, AssignType& assign, Args... args)
{
    obj.operator[](args...) = assign;
}

}
}
}
}

namespace boost
{
namespace numeric
{
namespace ublas
{

/**
 * Inverts a given matrix.
 *
 * @param input: The matrix to invert.
 * @param inverse: A reference to a matrix where the result should be stored.
 * @return true on success, false on fail
 * (for example if the matrix is linearly dependent).
 */
template<typename T>
bool
invert(matrix<T> const& input, matrix<T>& inverse);


/**
 * Concats vectors together to a matrix.
 * If count is 0, an empty matrix is returned.
 *
 * @param vectors: An array that contains the vectors that should be
 * concatenated.
 * @param count: The number of elements in the array.
 * @return The concatenated matrix.
 */
template<typename T>
matrix<T>
concat_vectors(vector<T> const * const vectors, size_t count);

/**
 * Concats vectors together to a matrix.
 * If the number of vectors in parameter vectors is 0, an empty matrix is
 * returned.
 *
 * @param vectors: The std::vector list that contains the vectors to concat.
 * @return The concatenated matrix.
 */
template<typename T>
matrix<T>
concat_vectors(std::vector<vector<T>> const& vectors);

/**
 * Normalizes the given vector.
 * If the given vector is a zero-vector, the function does not modify the
 * vector, so it stays a zero-vector.
 *
 * @tparam V A vector type derived from boost::numeric::ublas::vector.
 * @param vec A reference to the vector to normalize.
 * @param precision The precision. Every absolute value that is smaller than
 * precision is assumed as zero. So if the given vector is zero, it is not
 * normalized. Defaults to the expression
 * std::numeric_limits<V::value_type>().precision().
 * @returns true if zero, false if not.
 */
template<typename V>
typename std::enable_if<std::is_base_of<vector<typename V::value_type,
    typename V::array_type>, V>::value,
    void>::type
normalize(V& vec, typename V::value_type precision =
                  std::numeric_limits<typename V::value_type>::epsilon());

/**
 * Performs the orthogonalization method of Gram-Schmidt.
 *
 * @tparam ListType The list type the vectors are stored in. The vectors in
 * ListType must derive from boost::numeric::ublas::vector.
 * If the list exposes push_back(), zero vectors are automatically filtered.
 * @param input The input vectors that should be orthogonalized.
 * @returns A ListType with orthogonalized vectors. Zero-Vectors are filtered
 * if ListType supports push_back(), if not zero vectors aren't filtered.
 */
template<typename ListType>
typename std::enable_if<std::is_base_of<
    vector<typename ListType::value_type::value_type>,
    typename ListType::value_type>::value,
    ListType>::type
orthogonalize(ListType const& input);

/**
 * Performs the orthonormalization method of Gram-Schmidt. Automatically kicks
 * out zero vectors if a size growing container is given.
 *
 * @tparam ListType The list type the vectors are stored in. The vectors in
 * ListType must derive from boost::numeric::ublas::vector.
 * If the list exposes push_back(), zero vectors are automatically filtered.
 * @param input The input vectors that should be orthonormalized.
 * @returns A ListType with orthonormalized vectors. Zero-Vectors are filtered
 * if ListType supports push_back(), if not zero vectors aren't filtered.
 */
template<typename ListType>
typename std::enable_if<std::is_base_of<
    vector<typename ListType::value_type::value_type>,
    typename ListType::value_type>::value,
    ListType>::type
orthonormalize(ListType const& input);

/**
 * Tests if the given expression is zero.
 *
 * @tparam Any type to test if zero. Must support <
 * @param t The expression to compare with zero.
 * @param precision The precision. Every absolute value that is smaller than
 * precision is assumed as zero. Defaults to the expression
 * std::numeric_limits<V::value_type>().precision().
 * @returns true if zero, false if not.
 */
template<typename T>
bool
is_zero(typename std::conditional<std::is_integral<T>::value, T, T const&>
::type t, T precision = std::numeric_limits<T>::epsilon());

/**
 * Tests if the given vector is zero.
 *
 * @tparam V The vector type to test if zero. Must derive from
 * boost::numeric::ublas::vector.
 * @param vec The vector to test if zero.
 * @param precision The precision. Every absolute value that is smaller than
 * precision is assumed as zero. Defaults to the expression
 * std::numeric_limits<V::value_type>().precision().
 * @returns true if zero, false if not.
 */
template<typename V>
typename std::enable_if<std::is_base_of<vector<typename V::value_type>,
    V>::value,
    bool>::type
is_zero(V vec, typename V::value_type precision =
               std::numeric_limits<typename V::value_type>::epsilon());

}
}
}

#include "CE3D/util/boost_extensions_code.h"

#endif /* CE3D_UTIL_BOOST_EXTENSIONS_H */
