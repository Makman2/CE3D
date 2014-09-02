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
 * ListType must derive from boost::numeric::ublas::vector, so
 * ListType::value_type and the first template argument of vector must equal.
 * @param input The input vectors that should be orthogonalized.
 * @returns A ListType with orthogonalized vectors.
 */
template<typename ListType>
typename std::enable_if<std::is_base_of<
    vector<typename ListType::value_type::value_type>,
    typename ListType::value_type>::value,
    ListType>::type
orthogonalize(ListType const& input);

/**
 * Performs the orthogonalization method of Gram-Schmidt.
 *
 * @tparam V The vector type used. Must derive from
 * boost::numeric::ublas::vector.
 * @tparam count The number of vectors in the array.
 * @param input The input vectors that should be orthogonalized stored in
 * std::array.
 * @returns An std::array with the same size as input filled with the
 * orthogonalized vectors.
 */
template<typename V, size_t count>
typename std::enable_if<std::is_base_of<vector<typename V::value_type>,
    V>::value,
    std::array<V, count>>::type
orthogonalize(std::array<V, count> const& input);

/**
 * Performs the orthonormalization method of Gram-Schmidt. Automatically kicks
 * out zero vectors.
 *
 * @tparam ListType The list type the vectors are stored in. The vectors in
 * ListType must derive from boost::numeric::ublas::vector, so
 * ListType::value_type and the first template argument of vector must equal.
 * @param input The input vectors that should be orthonormalized.
 * @returns A ListType with orthonormalized vectors.
 */
template<typename ListType>
typename std::enable_if<std::is_base_of<
    vector<typename ListType::value_type::value_type>,
    typename ListType::value_type>::value,
    ListType>::type
orthonormalize(ListType const& input);

/**
 * Performs the orthonormalization method of Gram-Schmidt.
 *
 * @tparam V The vector type used. Must derive from
 * boost::numeric::ublas::vector.
 * @tparam count The number of vectors in the array.
 * @param input The input vectors that should be orthonormalized stored in
 * std::array.
 * @returns An std::array with the same size as input filled with the
 * orthonormalized vectors.
 */
template<typename V, size_t count>
typename std::enable_if<std::is_base_of<vector<typename V::value_type>,
    V>::value,
    std::array<V, count>>::type
orthonormalize(std::array<V, count> const& input);


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
