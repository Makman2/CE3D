// This file is part of CE3D. License: GPL3

#include "CE3D/test/testutilities.h"

#include <boost/test/unit_test.hpp>
#include <stdlib.h>
#include <boost/date_time.hpp>

namespace CE3D
{
namespace Testing
{

boost::date_time::time_duration
<boost::posix_time::time_duration, boost::posix_time::time_res_traits>::
sec_type
SecondsSinceEpoch()
{
    boost::posix_time::ptime today =
        boost::posix_time::second_clock::local_time();
    boost::posix_time::ptime epoch(boost::gregorian::date(1970, 1, 1));
    return (today - epoch).total_seconds();
}

boost::date_time::time_duration
<boost::posix_time::time_duration, boost::posix_time::time_res_traits>::
tick_type
NanosecondsSinceEpoch()
{
    boost::posix_time::ptime today =
        boost::posix_time::second_clock::local_time();
    boost::posix_time::ptime epoch(boost::gregorian::date(1970, 1, 1));
    return (today - epoch).total_nanoseconds();
}

bool
IsMatrixEqual(CE3D::Matrix const& a, CE3D::Matrix const& b)
{
    if ((a.size1() != b.size1()) || (a.size2() != b.size2()))
        return false;

    for (CE3D::Matrix::size_type i = 0; i < a.size1(); i++)
        for (CE3D::Matrix::size_type j = 0; j < a.size2(); j++)
            if (a(i, j) != b(i, j))
                return false;

    return true;
}

bool
IsMatrixEqual(CE3D::Matrix const&       a,
              CE3D::Matrix const&       b,
              CE3D::ModelDataType const tolerance)
{
    if ((a.size1() != b.size1()) || (a.size2() != b.size2()))
        return false;

    for (CE3D::Matrix::size_type i = 0; i < a.size1(); i++)
        for (CE3D::Matrix::size_type j = 0; j < a.size2(); j++)
        {
            if (b(i, j) == 0)
            {
                if (a(i, j) != 0)
                    return false;
                else
                    continue;
            }

            // Uses relative tolerance for checking. Better for matrices with
            // large numbers because of the floating point error that plays a
            // role when performing math with them.
            if (a(i, j) / b(i, j) < (1 - tolerance) ||
                    a(i, j) / b(i, j) > (1 + tolerance))
                return false;
        }

    return true;
}



bool
IsVectorEqual(CE3D::Vector const& a, CE3D::Vector const& b)
{
    if (a.size() != b.size())
        return false;

    for (CE3D::Matrix::size_type i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;

    return true;
}

bool
IsVectorEqual(CE3D::Vector const&       a,
              CE3D::Vector const&       b,
              CE3D::ModelDataType const tolerance)
{
    if (a.size() != b.size())
        return false;

    for (CE3D::Matrix::size_type i = 0; i < a.size(); i++)
    {
        if (b[i] == 0)
        {
            if (a[i] != 0)
                return false;
            else
                continue;
        }

        // Uses relative tolerance for checking. Better for vectors with
        // large numbers because of the floating point error that plays a
        // role when performing math with them.
        if (a[i] / b[i] < (1 - tolerance) || a[i] / b[i] > (1 + tolerance))
            return false;
    }

    return true;
}

CE3D::Matrix
RandomMatrix(CE3D::Matrix::size_type m,
             CE3D::Matrix::size_type n,
             unsigned int            seed)
{
    CE3D::Matrix mat(m, n);
    srand(seed);

    for (CE3D::Matrix::size_type x = 0; x < mat.size1(); x++)
        for (CE3D::Matrix::size_type y = 0; y < mat.size2(); y++)
            mat(x, y) = rand();

    return mat;
}

CE3D::Matrix
RandomMatrix(CE3D::Matrix::size_type m, CE3D::Matrix::size_type n)
{
    return RandomMatrix(
        m, n, static_cast<unsigned int>(NanosecondsSinceEpoch()));
}

float
Random(unsigned int seed)
{
    srand(seed);
    return rand();
}

float
Random()
{
    return Random(NanosecondsSinceEpoch());
}

std::vector<float>
RandomVector(std::vector<float>::size_type count, unsigned int seed)
{
    srand(seed);
    std::vector<float> vec(count);

    for (std::vector<float>::size_type i = 0; i < vec.size(); i++)
    {
        vec[i] = rand();
    }

    return vec;
}

std::vector<float>
RandomVector(std::vector<float>::size_type count)
{
    return RandomVector(
        count, static_cast<unsigned int>(NanosecondsSinceEpoch()));
}

}
}
