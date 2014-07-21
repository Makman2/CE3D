// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_TRANSFORMATION_CHAIN_CODE_H
#define CE3D_TRANSFORMATION_TRANSFORMATION_CHAIN_CODE_H

namespace CE3D
{
namespace Transformation
{

template <typename TransformationType>
void
TransformationChain::PushBack(TransformationType const& transformation)
{
    EmplaceBack<TransformationType>(transformation);
}

template <typename TransformationType>
void
TransformationChain::PushFront(TransformationType const& transformation)
{
    Insert(transformation, Begin());
}

template <typename TransformationType, typename... Args>
void
TransformationChain::EmplaceFront(Args&&... args)
{
    Emplace<TransformationType>(Begin(), args...);
}

template <typename TransformationType, typename... Args>
void
TransformationChain::EmplaceBack(Args&&... args)
{
    m_TransformationList.push_back(
        std::unique_ptr<Transformation>(
        new TransformationType(args...)));
    m_NeedUpdate = true;
}

template <typename TransformationType, typename... Args>
TransformationChain::const_iterator
TransformationChain::Emplace (const_iterator it, Args&&... args)
{
    auto itm = m_TransformationList.begin();
    std::advance(itm, std::distance(Begin(), it));
    m_NeedUpdate = true;
    return const_iterator(m_TransformationList.insert(
        itm, std::unique_ptr<Transformation>
        (new TransformationType(args...))));
}

template <typename TransformationType>
TransformationChain::const_iterator
TransformationChain::Insert (TransformationType const& transformation,
                             size_type                 index)
{
    return Insert(transformation, Middle(index));
}

template <typename TransformationType>
TransformationChain::const_iterator
TransformationChain::Insert(TransformationType const& transformation,
                            const_iterator            it)
{
    return Emplace<TransformationType>(it, transformation);
}

template <typename TransformationType>
void
TransformationChain::Replace(TransformationType const& transformation,
                             size_type                 index)
{
    m_NeedUpdate = true;
    m_TransformationList[index] =
        std::unique_ptr<Transformation>(
        new TransformationType(transformation));
}

template <typename TransformationType>
void
TransformationChain::Replace(TransformationType const& transformation, 
                             const_iterator            it)
{
    auto itm = m_TransformationList.begin();
    std::advance(itm, std::distance(Begin(), it));
    m_NeedUpdate = true;
    *itm = std::unique_ptr<Transformation>
        (new TransformationType(transformation));
}

template <typename TransformationType>
TransformationType const&
TransformationChain::At(size_type index) const
{
    return static_cast<TransformationType const&>(At(index));
}

template <typename TransformationType>
TransformationType const&
TransformationChain::At(const_iterator it) const
{
    return static_cast<TransformationType const&>(At(it));
}

template <typename TransformationType>
TransformationType const&
TransformationChain::Front() const
{
    return static_cast<TransformationType const&>(Front());
}

template <typename TransformationType>
TransformationType const&
TransformationChain::Back() const
{
    return static_cast<TransformationType const&>(Back());
}

}
}

#endif
