// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_TRANSFORMATION_CHAIN_H
#define CE3D_TRANSFORMATION_TRANSFORMATION_CHAIN_H

#include <vector>

#include "CE3D/util/stdinc.h"
#include "CE3D/util/CE3D_matrix.h"

#include "CE3D/transformation/transformation.h"
#include "CE3D/util/dereference_iterator.h"

namespace CE3D
{
namespace Transformation
{

/**
 * Manages a list of transformations that should be applied on a
 * transformation.
 *
 * The evaluation with a vector is performed top-down, so the resulting matrix
 * calculation is bottom-up.
 */
class TransformationChain : public Transformation
{
private:

    /**
     * The list that contains the transformations.
     */
    std::vector<std::unique_ptr<Transformation> > m_TransformationList;

protected:

    virtual void
    UpdateMatrix() const override;

public:

    /**
     * The size type the transformation chain uses for the transformation list.
     */
    using size_type = std::vector<std::unique_ptr<Transformation> >::size_type;

    /**
     * The transformation chain const_iterator class. Exposes const access to
     * it's
     * matrices.
     */
    using const_iterator =
    dereference_iterator<std::vector<std::unique_ptr<Transformation> >
    ::const_iterator>;

    /**
     * The transformation chain const_reverse_iterator class. Exposes const
     * access to
     * it's matrices.
     */
    using const_reverse_iterator =
    dereference_iterator<std::vector<std::unique_ptr<Transformation> >
    ::const_reverse_iterator>;

    TransformationChain();
    virtual

    /**
     * Returns a const_iterator pointing at first transformation in the chain.
     *
     * @returns The iterator.
     */
    const_iterator
    Begin() const;

    /**
     * Returns a const_iterator pointing at the transformation at the specified
     * index.
     *
     * @param index The index where the transformation lies.
     * @returns The iterator.
     */
    const_iterator
    Middle(size_type index) const;

    /**
     * Returns a const_iterator pointing at last transformation in the chain.
     *
     * @returns The iterator.
     */
    const_iterator
    End() const;

    /**
     * Returns a const_reverse_iterator pointing at the first transformation in
     * the chain.
     *
     * @returns The iterator.
     */
    const_reverse_iterator
    RBegin() const;

    /**
     * Returns a const_reverse_iterator pointing at the transformation at the
     * specified index relative to the end.
     *
     * @param index The index relative to the end where the transformation
     * lies.
     * @returns The iterator.
     */
    const_reverse_iterator
    RMiddle(size_type index) const;

    /**
     * Returns a const_reverse_iterator pointing at last transformation in the
     * chain.
     *
     * @returns The iterator.
     */
    const_reverse_iterator
    REnd() const;

    /**
     * Pushes back a new transformation onto the top of the chain.
     *
     * @tparam TransformationType The type of transformation the function is
     * passed.
     * @param transformation The transformation to push.
     */
    template <typename TransformationType>
    void
    PushBack(TransformationType const& transformation);

    /**
     * Adds a new transformation at the bottom of the chain.
     *
     * @tparam TransformationType The type of transformation the function is
     * passed.
     * @param transformation The transformation to add.
     */
    template <typename TransformationType>
    void
    PushFront(TransformationType const& transformation);

    /**
     * Constructs and inserts transformation at the bottom of the chain.
     *
     * @tparam TransformationType The type of transformation the function is
     * passed. You must give this template argument excplicitly so
     * EmplaceFront() knows what transformation is used where to call the
     * constructor.
     * @tparam Args The variadic template arguments that are passed to the
     * constructor of TransformationType. Determined automatically from the
     * function call parameters.
     */
    template <typename TransformationType, typename... Args>
    void
    EmplaceFront(Args&&... args);

    /**
     * Constructs and inserts transformation at the top of the chain.
     *
     * @tparam TransformationType The type of transformation the function is
     * passed. You must give this template argument excplicitly so
     * EmplaceBack() knows what transformation is used where to call the
     * constructor.
     * @tparam Args The variadic template arguments that are passed to the
     * constructor of TransformationType. Determined automatically from the
     * function call parameters.
     */
    template <typename TransformationType, typename... Args>
    void
    EmplaceBack(Args&&... args);

    /**
     * Constructs and inserts transformation into the chain at the specified
     * position.
     *
     * @param it The const_iterator that indicates the position where to
     * construct and insert.
     * @tparam TransformationType The type of transformation the function is
     * passed. You must give this template argument excplicitly so
     * Emplace() knows what transformation is used where to call the
     * constructor.
     * @tparam Args The variadic template arguments that are passed to the
     * constructor of TransformationType. Determined automatically from the
     * function call parameters.
     * @returns A const_iterator pointing at the new inserted element.
     */
    template <typename TransformationType, typename... Args>
    const_iterator
    Emplace(const_iterator it, Args&&... args);

    /**
     * Inserts a new transformation into the chain at the specified position.
     *
     * @tparam TransformationType The type of transformation the function is
     * passed.
     * @param transformation The transformation to add.
     * @param index The position where to insert. If index equals the size of
     * the chain, the function behaves like PushBack.
     */
    template <typename TransformationType>
    const_iterator
    Insert(TransformationType const& transformation, size_type index);

    /**
     * Inserts a new transformation into the chain at the specified position.
     *
     * @tparam TransformationType The type of transformation the function is
     * passed.
     * @param transformation The transformation to add.
     * @param it The iterator that indicates the position where to insert.
     * @returns An const_iterator pointing at the new inserted element.
     */
    template <typename TransformationType>
    const_iterator
    Insert(TransformationType const& transformation, const_iterator it);

    /**
     * Replaces the transformation at the specified index with the given one.
     *
     * @tparam TransformationType The type of transformation the function is
     * passed.
     * @param transformation The transformation to replace with.
     * @param index The index where to replace.
     */
    template <typename TransformationType>
    void
    Replace(TransformationType const& transformation, size_type index);

    /**
     * Replaces the transformation at the specified index with the given one.
     *
     * @tparam TransformationType The type of transformation the function is
     * passed.
     * @param transformation The transformation to replace with.
     * @param it The iterator that indicates the position where to replace.
     * @returns The const_iterator pointing at the new transformation.
     */
    template <typename TransformationType>
    void
    Replace(TransformationType const& transformation, const_iterator it);

    /**
     * Deletes the transformation at the specified position.
     *
     * @param index The position of the transformation to delete.
     */
    void
    Erase(size_type index);

    /**
     * Deletes the transformation at the specified position.
     *
     * @param it The iterator that indicates the position of the transformation
     * to
     * delete.
     */
    void
    Erase(const_iterator it);

    /**
     * Deletes all transformations in the chain.
     */
    void
    Clear();

    /**
     * Exchanges the content of this chain with the given one.
     *
     * @param chain The chain to switch content with.
     */
    void Swap(TransformationChain& chain);

    /**
     * Exchanges the positions of the transformations at the given indices.
     *
     * @param index1 The first index.
     * @param index2 The second index.
     */
    void
    Exchange(size_type index1, size_type index2);

    /**
     * Exchanges the positions of the transformations at the given iterator
     * positions.
     *
     * @param it1 The first iterator position.
     * @param index2 The second iterator position.
     */
    void
    Exchange(const_iterator it1, const_iterator it2);

    /**
     * Returns the transformation at the given index.
     *
     * @param index The index of the transformation.
     * @returns The transformation at index.
     */
    Transformation const&
    At(size_type index) const;

    /**
     * Returns the transformation from the given iterator.
     *
     * @param it The const_iterator that points at the transformation.
     * @returns The transformation at the given iterator.
     */
    Transformation const&
    At(const_iterator it) const;

    /**
     * Returns the transformation at the given index and casts it to the
     * given type of transformation.
     * Note: The conversion is unsafe, so you have to ensure that the cast is
     * valid.
     *
     * @tparam TransformationType The transformation type to convert to.
     * @param index The index of the transformation.
     * @returns The transformation at index.
     */
    template <typename TransformationType>
    TransformationType const&
    At(size_type index) const;

    /**
     * Returns the transformation from the given iterator and casts it to the
     * given type of transformation.
     * Note: The conversion is unsafe, so you have to ensure that the cast is
     * valid.
     *
     * @tparam TransformationType The transformation type to convert to.
     * @param it The const_iterator that points at the transformation.
     * @returns The transformation at the given iterator.
     */
    template <typename TransformationType>
    TransformationType const&
    At(const_iterator it) const;

    /**
     * Returns the transformation at the given index.
     *
     * This operator invokes At().
     *
     * @param index The index of the transformation.
     * @returns The transformation at index.
     */
    Transformation const&
    operator [](size_type index) const;

    /**
     * Accesses the first transformation of the chain.
     *
     * @returns The transformation at the beginning of the chain.
     */
    Transformation const&
    Front() const;

    /**
     * Accesses and casts the first transformation of the chain to the
     * specified template transformation type.
     * Note: The conversion is unsafe, so you have to ensure that the cast ist
     * valid.
     *
     * @tparam TransformationType The transformation type to convert to.
     * @returns The transformation at the beginning of the chain.
     */
    template <typename TransformationType>
    TransformationType const&
    Front() const;

    /**
     * Accesses the last transformation of the chain.
     *
     * @returns The transformation at the end of the chain.
     */
    Transformation const&
    Back() const;

    /**
     * Accesses and casts the last transformation of the chain to the
     * specified template transformation type.
     * Note: The conversion is unsafe, so you have to ensure that the cast ist
     * valid.
     *
     * @tparam TransformationType The transformation type to convert to.
     * @returns The transformation at the end of the chain.
     */
    template <typename TransformationType>
    TransformationType const&
    Back() const;

    /**
     * Returns the number of matrices in the transformation chain.
     *
     * @returns The number of transformations.
     */
    size_type
    Size() const;

    /**
     * Returns whether the number of matrices in transformation chain is zero.
     *
     * @return true if empty, false if not.
     */
    bool
    IsEmpty() const;

    /**
     * Returns the matrix that represents the complete linear transformation.
     *
     * @returns The matrix. If no transformation is pushed onto the chain the
     * function serves undefined behaviour.
     */
    virtual Matrix const&
    GetMatrix() const override;

};



}
}

#include "transformation_chain_code.h"

#endif /* CE3D_TRANSFORMATION_TRANSFORMATION_CHAIN_H */
