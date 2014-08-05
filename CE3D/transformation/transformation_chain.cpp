// This file is part of CE3D. License: GPL3

#include "transformation_chain.h"

#include <stdexcept>
#include <boost/numeric/ublas/operation.hpp>
#include <utility>

// TODO Implement TransformationChain

// ENHANCE Implement intelligent multiplication with a vector without
//         multiplying the whole matrix chain out.

// TODO Implement the lazy-update mechanism
//  - First efficiency level: stack frames that indicate what part of the
//    matrix was already calculated. See stack frame structure in the private
//    section of the class.
//  - Second efficiency level: inversion of matrices. If only one matrix was
//    removed at the top or beginning (not in the middle), it can be
//    cost-saving for small matrices to invert them. A value has to be
//    calculated to determine whether it's more useful to invert a matrix or
//    just to multiply the whole matrix chain again.

namespace CE3D
{
namespace Transformation
{

    TransformationChain::TransformationChain()
    : m_TransformationList()
    {}

    Matrix const& TransformationChain::GetMatrix() const
    {
        if (m_NeedUpdate)
        {
            UpdateMatrix();
        }

        return m_Matrix;
    }

    void TransformationChain::UpdateMatrix() const
    {
        if (IsEmpty())
        {
            throw std::length_error("TransformationChain is empty.");
        }

        auto it = Begin();
        m_Matrix = it->GetMatrix();
        it++;

        Matrix cache;
        while (it != End())
        {
            m_Matrix.swap(cache);
            m_Matrix.resize(cache.size1(), it->GetMatrix().size2(), false);

            boost::numeric::ublas::axpy_prod
                (cache, it->GetMatrix(), m_Matrix, true);

            it++;
        }

        m_NeedUpdate = false;
    }


    TransformationChain::const_iterator
    TransformationChain::Begin() const
    {
        return const_iterator(m_TransformationList.cbegin());
    }

    TransformationChain::const_iterator
    TransformationChain::Middle(TransformationChain::size_type index) const
    {
        if (index >= Size())
            throw std::out_of_range("Index out of bounds.");

        const_iterator it(m_TransformationList.cbegin());
        it += index;

        return it;
    }

    TransformationChain::const_iterator
    TransformationChain::End() const
    {
        return const_iterator(m_TransformationList.cend());
    }

    TransformationChain::const_reverse_iterator
    TransformationChain::RBegin() const
    {
        return const_reverse_iterator(m_TransformationList.crbegin());
    }

    TransformationChain::const_reverse_iterator
    TransformationChain::RMiddle(TransformationChain::size_type index) const
    {
        if (index >= Size())
            throw std::out_of_range("Index out of bounds.");

        const_reverse_iterator it(m_TransformationList.crbegin());
        it += index;

        return it;
    }

    TransformationChain::const_reverse_iterator
    TransformationChain::REnd() const
    {
        return const_reverse_iterator(m_TransformationList.crend());
    }

    void TransformationChain::Erase(TransformationChain::size_type index)
    {
        Erase(Middle(index));
    }

    void TransformationChain::Erase(TransformationChain::const_iterator it)
    {
        auto itm = m_TransformationList.begin();
        itm += std::distance(Begin(), it);
        m_TransformationList.erase(itm);
        m_NeedUpdate = true;
    }

    void TransformationChain::Clear()
    {
        m_TransformationList.clear();
        m_NeedUpdate = true;
    }

    void TransformationChain::Swap(TransformationChain& chain)
    {
        std::swap(m_Matrix, chain.m_Matrix);
        std::swap(m_NeedUpdate, chain.m_NeedUpdate);
        std::swap(m_TransformationList, chain.m_TransformationList);
    }

    void TransformationChain::Exchange(TransformationChain::size_type index1,
    TransformationChain::size_type index2)
    {
        m_TransformationList[index1].swap(m_TransformationList[index2]);
    }

    void TransformationChain::Exchange(TransformationChain::const_iterator it1,
                                       TransformationChain::const_iterator it2)
    {
        auto itm1 = m_TransformationList.begin();
        itm1 += std::distance(Begin(), it1);
        auto itm2 = m_TransformationList.begin();
        itm2 += std::distance(Begin(), it2);
        itm1->swap(*itm2);
    }

    Transformation const& TransformationChain::At
    (TransformationChain::size_type index) const
    {
        return *(m_TransformationList[index].get());
    }

    Transformation const& TransformationChain::At
    (TransformationChain::const_iterator it) const
    {
        return *it;
    }

    Transformation const& TransformationChain::operator []
    (TransformationChain::size_type index) const
    {
        return At(index);
    }

    Transformation const& TransformationChain::Front() const
    {
        return *(m_TransformationList.front().get());
    }

    Transformation const& TransformationChain::Back() const
    {
        return *(m_TransformationList.back().get());
    }

    TransformationChain::size_type TransformationChain::Size() const
    {
        return m_TransformationList.size();
    }

    bool TransformationChain::IsEmpty() const
    {
        return Size() == 0;
    }
}
}
