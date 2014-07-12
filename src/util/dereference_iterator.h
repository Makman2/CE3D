// This file is part of CE3D. License: GPL3

#ifndef CE3D_DEREFERENCE_ITERATOR_H
#define CE3D_DEREFERENCE_ITERATOR_H

#include <iterator>

/**
 * An adapter for iterators with types that are dereferencable. The iterator
 * behaves like the base iterator but retrieves the held type of the iterator
 * value type.
 *
 * @tparam IteratorType The base type of the iterator to create the adapter
 * from. Must be tagged with std::random_access_iterator_tag.
 */
template <typename IteratorType>
class dereference_iterator
: public std::iterator<std::random_access_iterator_tag,
  typename IteratorType::value_type::element_type,
  typename IteratorType::difference_type>
{
public:
    using iterator_type = IteratorType;

private:
    iterator_type m_base_iterator;

public:

    dereference_iterator(iterator_type const& base)
    : m_base_iterator(base)
    {}

    dereference_iterator()
    : m_base_iterator()
    {}

    dereference_iterator(dereference_iterator const& obj)
    : m_base_iterator(obj.m_base_iterator)
    {}

    virtual ~dereference_iterator()
    {}

    dereference_iterator& operator =(dereference_iterator const& rhs)
    {
        if (this != &rhs)
        {
            dereference_iterator tmp(rhs);
            swap(tmp);
        }
        return *this;
    }

    dereference_iterator&
    operator ++()
    {
        m_base_iterator++;
        return *this;
    }
    
    dereference_iterator
    operator ++(int)
    {
        ++m_base_iterator;
        return *this;
    }

    dereference_iterator&
    operator --()
    {
        m_base_iterator--;
        return *this;
    }

    dereference_iterator
    operator --(int)
    {
        --m_base_iterator;
        return *this;
    }

    dereference_iterator
    operator +(typename iterator_type::difference_type rhs) const
    {
        dereference_iterator tmp(*this);
        tmp.m_base_iterator = m_base_iterator + rhs;
        return tmp;
    }

    friend dereference_iterator
    operator +
    (typename iterator_type::difference_type lhs,
     dereference_iterator const& rhs)
    {
        return rhs + lhs;
    }

    dereference_iterator
    operator -(typename iterator_type::difference_type rhs) const
    {
        dereference_iterator tmp(*this);
        tmp.m_base_iterator = m_base_iterator - rhs;
        return tmp;
    }

    typename iterator_type::difference_type
    operator -(dereference_iterator const& rhs) const
    {
        return m_base_iterator - rhs.m_base_iterator;
    }

    dereference_iterator&
    operator +=(typename iterator_type::difference_type rhs)
    {
        m_base_iterator += rhs;
        return *this;
    }

    dereference_iterator&
    operator -=(typename iterator_type::difference_type rhs)
    {
        m_base_iterator -= rhs;
        return *this;
    }

    bool
    operator ==(dereference_iterator const& rhs) const
    {
        return m_base_iterator == rhs.m_base_iterator;
    }
    
    bool
    operator !=(dereference_iterator const& rhs) const
    {
        return m_base_iterator != rhs.m_base_iterator;
    }
    
    bool
    operator <(dereference_iterator const& rhs) const
    {
        return m_base_iterator < rhs.m_base_iterator;
    }

    bool
    operator >(dereference_iterator const& rhs) const
    {
        return m_base_iterator > rhs.m_base_iterator;
    }

    bool
    operator <=(dereference_iterator const& rhs) const
    {
        return m_base_iterator <= rhs.m_base_iterator;
    }

    bool
    operator >=(dereference_iterator const& rhs) const
    {
        return m_base_iterator >= rhs.m_base_iterator;
    }

    typename iterator_type::value_type::element_type&
    operator [](typename iterator_type::difference_type index)
    {
        return *(this + index);
    }

    typename iterator_type::value_type::element_type&
    operator *() const
    {
        return *(*m_base_iterator);
    }

    typename iterator_type::value_type::element_type*
    operator ->() const
    {
        return &(*(*m_base_iterator));
    }

    static void swap(dereference_iterator& lhs, dereference_iterator& rhs)
    {
        std::swap(lhs.m_base_iterator, rhs.m_base_iterator);
    }

    void swap(dereference_iterator& rhs)
    {
        swap(*this, rhs);
    }

};



#endif /* CE3D_DEREFERENCE_ITERATOR_H */
