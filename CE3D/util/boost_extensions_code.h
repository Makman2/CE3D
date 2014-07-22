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
normalize(V& vec)
{
    auto n2 = norm_2(vec);
    if (n2 != 0)
        vec /= n2;
}

template<typename ListType>
typename std::enable_if<std::is_base_of<
    vector<typename ListType::value_type::value_type>,
    typename ListType::value_type>::value,
    ListType>::type
orthogonalize(ListType const& input)
{
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
    if (std::is_function<decltype(declval<ListType>().reserve(
        declval<typename ListType::size_type>()))
        (typename ListType::size_type)>::value)
        orthogonalized.reserve(input.size());

    typename ListType::value_type currentvec;
    
    for (auto vec : input)
    {
        currentvec = vec;

        auto onb_it = orthonormalized_sqr.begin();
        for (auto ortho : orthogonalized)
        {
            auto ip = inner_prod(currentvec, ortho);
            if (ip != 0)
                currentvec -= ip * (*onb_it);
            
            onb_it++;
        }

        orthogonalized.push_back(currentvec);
        orthonormalized_sqr.push_back(
            currentvec / inner_prod(currentvec, currentvec));
    }

    return orthogonalized;
}

template<typename V, size_t count>
typename std::enable_if<std::is_base_of<vector<typename V::value_type>,
    V>::value,
    std::array<V, count>>::type
orthogonalize(std::array<V, count> const& input)
{
    // Contains the orthogonalized vectors.
    std::array<V, count> orthogonalized;
    // The with-calculated squared-orthonormal vectors. With this extra list a
    // permament recalculation of the scalar and vector multiplication is not
    // needed anymore. This overheads in double memory consumption but the
    // boost is much greater.
    std::vector<V> orthonormalized_sqr;
    orthonormalized_sqr.reserve(count);

    V currentvec;

    for (size_t i = 0; i < count; i++)
    {
        currentvec = input[i];
        for (size_t n = 0; n < i; n++)
        {
            auto ip = inner_prod(currentvec, orthogonalized[n]);
            if (ip != 0)
                currentvec -= ip * orthonormalized_sqr[n];
        }

        orthogonalized[i] = currentvec;
        orthonormalized_sqr.push_back(
            currentvec / inner_prod(currentvec, currentvec));
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
    // Contains the orthonormalized vectors.
    ListType orthonormalized;

    // If iteratable list supports reserve (like std::vector), we can save
    // memory reserves when calling push_back.
    if (std::is_function<decltype(declval<ListType>().reserve(
        declval<typename ListType::size_type>()))
        (typename ListType::size_type)>::value)
        orthonormalized.reserve(input.size());

    typename ListType::value_type currentvec;
    
    for (auto vec : input)
    {
        currentvec = vec;

        for (auto ortho : orthonormalized)
        {
            currentvec -= inner_prod(currentvec, ortho) * ortho;
        }
        
        normalize(currentvec);
        orthonormalized.push_back(currentvec);
    }

    return orthonormalized;
}

template<typename V, size_t count>
typename std::enable_if<std::is_base_of<vector<typename V::value_type>,
    V>::value,
    std::array<V, count>>::type
orthonormalize(std::array<V, count> const& input)
{
    // Contains the orthogonalized vectors.
    std::array<V, count> orthonormalized;

    V currentvec;

    for (size_t i = 0; i < count; i++)
    {
        currentvec = input[i];
        for (size_t n = 0; n < i; n++)
        {
            currentvec -= inner_prod(currentvec, orthonormalized[n]) * 
                orthonormalized[n];
        }

        orthonormalized[i] = currentvec;
    }

    return orthonormalized;
}

}
}
}

#endif /* CE3D_UTIL_BOOST_EXTENSIONS_CODE_H */
