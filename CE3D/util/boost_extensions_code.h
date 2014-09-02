// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_BOOST_EXTENSIONS_CODE_H
#define CE3D_UTIL_BOOST_EXTENSIONS_CODE_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <utility>

namespace boost
{
namespace numeric
{
namespace ublas
{

template<typename T>
bool
invert(matrix<T> const& input, matrix<T>& inverse)
{
    // create a working copy of the input
    matrix<T> A(input);

    // create a permutation matrix for the LU-factorization
    permutation_matrix<std::size_t> pm(A.size1());

    // perform LU-factorization
    int res = lu_factorize(A, pm);
    if (res != 0)
        return false;

    // create identity matrix of "inverse"
    inverse.assign(identity_matrix<T> (A.size1()));

    // backsubstitute to get the inverse
    lu_substitute(A, pm, inverse);

    return true;
}

template<typename T>
matrix<T>
concat_vectors(vector<T> const * const vectors, size_t count)
{
    if (count == 0)
        return matrix<T>();

    // Check bounds.
    for (size_t i = 1; i < count; i++)
    {
        if (vectors[i - 1].size() != vectors[i].size())
            throw std::invalid_argument
                ("Vectors doesn't have the same length.");
    }

    matrix<T> M((*vectors).size(), count);
    for (typename matrix<T>::size_type column = 0; column < M.size2();
         column++)
    {
        for (typename matrix<T>::size_type row = 0; row < M.size1(); row++)
        {
            M(row, column) = vectors[column](row);
        }
    }

    return M;
}

template<typename T>
matrix<T>
concat_vectors(std::vector<vector<T>> const& vectors)
{
    if (vectors.size() == 0)
        return matrix<T>();

    // Check bounds.
    for (typename std::vector<T>::size_type i = 1; i < vectors.size(); i++)
    {
        if (vectors.at(i - 1).size() != vectors.at(i).size())
            throw std::invalid_argument
                ("Vectors doesn't have the same length.");
    }

    matrix<T> M(vectors.at(0).size(), vectors.size());
    for (typename matrix<T>::size_type column = 0; column < M.size2();
         column++)
    {
        for (typename matrix<T>::size_type row = 0; row < M.size1(); row++)
        {
            M(row, column) = vectors.at(column)(row);
        }
    }

    return M;
}

template<typename V>
typename std::enable_if<std::is_base_of<vector<typename V::value_type,
    typename V::array_type>, V>::value,
    void>::type
normalize(V& vec, typename V::value_type precision =
                  std::numeric_limits<typename V::value_type>::epsilon())
{
    auto n2 = norm_2(vec);
    if (!is_zero<decltype(n2)>(n2, precision))
        vec /= n2;
    else
        vec = zero_vector<typename V::value_type>(vec.size());
}

template<typename ListType>
typename std::enable_if<std::is_base_of<
    vector<typename ListType::value_type::value_type>,
    typename ListType::value_type>::value,
    ListType>::type
orthogonalize(ListType const& input)
{
    // Constant expressions.
    auto constexpr supports_push_back =
        help_traits::has_push_back<ListType,
        void(typename ListType::value_type const&)>::value;
    auto constexpr supports_reserve =
        help_traits::has_reserve<ListType, void(typename ListType::size_type)>
        ::value;
    auto constexpr supports_array_accessor =
        help_traits::has_array_accessor<ListType, typename ListType::reference
        (typename ListType::size_type)>::value;

    // Static asserts.
    static_assert(supports_push_back || supports_array_accessor,
                  "push_back() and operator[] not supported by "
                  "ListType. Use a ListType that defines one of "
                  "these functions. Template instantation "
                  "failed.");


    // Contains the orthogonalized vectors.
    ListType orthogonalized;
    // The with-calculated squared-orthonormal vectors. With this extra list a
    // permament recalculation of the scalar and vector multiplication is not
    // needed anymore. This overheads in double memory consumption but the
    // boost is much greater.
    std::vector<typename ListType::value_type> orthonormalized_sqr;
    orthonormalized_sqr.reserve(input.size());

    // If iteratable list supports reserve (like std::vector), we can save
    // memory reserves when calling push_back.
    help_traits::call_reserve_if<supports_reserve>
        (orthogonalized, input.size());

    typename ListType::value_type currentvec;

    // Define loop variable for input vectors.
    // Optimized out if push_back is supported by ListType.
    typename ListType::size_type inputcounter = 0;

    typename ListType::size_type counter;
    for (auto const& vec : input)
    {
        currentvec = vec;

        // Define loop variable for loop break, because no push-back-able
        // can't change it's size here. Will be optimized out if the ListType
        // supports push_back.
        if (!supports_push_back && supports_array_accessor)
            counter = 0;

        auto onb_it = orthonormalized_sqr.begin();
        for (auto const& ortho : orthogonalized)
        {
            if (!supports_push_back && supports_array_accessor)
                // Abort if no orthogonalized vectors are in array.
                if (counter >= inputcounter)
                    break;

            auto ip = inner_prod(currentvec, ortho);
            if (ip != 0)
                currentvec -= ip * (*onb_it);

            onb_it++;

            if (!supports_push_back && supports_array_accessor)
                // Increase abort counter.
                counter++;
        }

        if (supports_push_back)
        {
            // If supports push_back use that instead.
            help_traits::call_push_back_if<supports_push_back>
                (orthogonalized, currentvec);
        }
        else if (supports_array_accessor)
        {
            // Array version.
            help_traits::call_array_accessor_and_set_if
                <supports_array_accessor>
                (orthogonalized, currentvec, inputcounter);
        }

        orthonormalized_sqr.push_back(
            currentvec / inner_prod(currentvec, currentvec));

        inputcounter++;
    }

    return orthogonalized;
}

template<typename ListType>
typename std::enable_if<std::is_base_of<
    vector<typename ListType::value_type::value_type>,
    typename ListType::value_type>::value,
    ListType>::type
orthonormalize(ListType const& input)
{
    // Constant expressions.
    auto constexpr supports_push_back =
        help_traits::has_push_back<ListType,
        void(typename ListType::value_type const&)>::value;
    auto constexpr supports_reserve =
        help_traits::has_reserve<ListType, void(typename ListType::size_type)>
        ::value;
    auto constexpr supports_array_accessor =
        help_traits::has_array_accessor<ListType, typename ListType::reference
        (typename ListType::size_type)>::value;

    // Static asserts.
    static_assert(supports_push_back || supports_array_accessor,
                  "push_back() and operator[] not supported by "
                  "ListType. Use a ListType that defines one of "
                  "these functions. Template instantation "
                  "failed.");


    // Contains the orthonormalized vectors.
    ListType orthonormalized;

    // If iteratable list supports reserve (like std::vector), we can save
    // memory reserves when calling push_back.
    help_traits::call_reserve_if<supports_reserve>
        (orthonormalized, input.size());

    typename ListType::value_type currentvec;

    // The initial precision to use for additive error calculation.
    auto constexpr prec = std::numeric_limits
        <typename ListType::value_type::value_type>::epsilon();

    typename ListType::size_type i = 1;
    typename ListType::size_type orthocount;

    for (auto const& vec : input)
    {
        currentvec = vec;

        if (!supports_push_back && supports_array_accessor)
            orthocount = 1;

        for (auto const& ortho : orthonormalized)
        {
            if (!supports_push_back && supports_array_accessor)
                // Abort if no orthonormalized vectors are in array.
                if (orthocount >= i)
                    break;

            currentvec -= inner_prod(currentvec, ortho) * ortho;

            if (!supports_push_back && supports_array_accessor)
                orthocount++;
        }

        normalize(currentvec, i * prec);

        if (supports_push_back)
        {
            // If supports push_back(), don't push back zero vectors.
            if (!is_zero(currentvec))
                help_traits::call_push_back_if<supports_push_back>
                    (orthonormalized, currentvec);
        }
        else if (supports_array_accessor)
            // Array version.
            help_traits::call_array_accessor_and_set_if
                <supports_array_accessor>
                (orthonormalized, currentvec, i - 1);

        i++;
    }

    return orthonormalized;
}


template<typename T>
bool
is_zero(typename std::conditional<std::is_integral<T>::value, T, T const&>
::type t, T precision = std::numeric_limits<T>::epsilon())
{
    return fabs(t) < precision;
}

template<typename V>
typename std::enable_if<std::is_base_of<vector<typename V::value_type>,
    V>::value,
    bool>::type
is_zero(V vec, typename V::value_type precision =
               std::numeric_limits<typename V::value_type>::epsilon())
{
    for (auto elem : vec)
    {
        if (!is_zero<decltype(elem)>(elem, precision))
            return false;
    }

    return true;
}

}
}
}

#endif /* CE3D_UTIL_BOOST_EXTENSIONS_CODE_H */
