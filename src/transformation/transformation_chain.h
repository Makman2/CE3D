// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_CHAIN_H
#define CE3D_TRANSFORMATION_CHAIN_H

#include <vector>

#include "util/stdinc.h"
#include "util/CE3D_matrix.h"

#include "transformation/transformation.h"
#include "util/dereference_iterator.h"

namespace CE3D
{
namespace Transformation
{

/**
 * Manages a list of transformations that should be applied on a transformation.
 *
 * The evaluation with a vector is performed top-down, so the resulting matrix
 * calculation is bottom-up.
 */
class TransformationChain
{
private:
    /**
     * The matrix that represents the transformations when sequentially applied.
     *
     * This is mutable since it is implicit information which is lazy filled in
     * a const function if needed.
     */
    mutable Matrix m_Matrix;

    /**
     * Determines whether the matrix was modified and needs to be updated.
     *
     * Set this to true if you set information that implicitly changes the
     * matrix so you can recalculate it lazy.
     */
    mutable bool m_NeedUpdate;

    /**
     * The list that contains the transformations.
     */
    std::vector<std::unique_ptr<Transformation> > m_TransformationList;

protected:

    /**
     * Updates the matrix.
     *
     * This function is invoked by GetMatrix if m_NeedUpdate is true. It is
     * used to calculate implicit information (the matrix) lazy because it is
     * rarely needed for some transformations.
     */
    void UpdateMatrix() const;

public:
   
    /**
     * The size type the transformation chain uses for the transformation list.
     */
    typedef std::vector<std::unique_ptr<Transformation> >::size_type size_type;
    
    /**
     * The transformation chain const_iterator class. Exposes const access to it's
     * matrices.
     */
    typedef dereference_iterator<std::vector<std::unique_ptr<Transformation> 
    >::const_iterator> const_iterator;

    /**
     * The transformation chain const_reverse_iterator class. Exposes const access to
     * it's matrices.
     */
    typedef dereference_iterator<std::vector<std::unique_ptr<Transformation>
    >::const_reverse_iterator> const_reverse_iterator;

    TransformationChain();
    inline virtual
    ~TransformationChain() {}
    
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
     * Returns a const_reverse_iterator pointing at the first transformation in the
     * chain.
     *
     * @returns The iterator.
     */
    const_reverse_iterator
    RBegin() const;
    
    /**
     * Returns a const_reverse_iterator pointing at the transformation at the
     * specified index relative to the end.
     *
     * @param index The index relative to the end where the transformation lies.
     * @returns The iterator.
     */
    const_reverse_iterator
    RMiddle(size_type index) const;

    /**
     * Returns a const_reverse_iterator pointing at last transformation in the chain.
     *
     * @returns The iterator.
     */
    const_reverse_iterator
    REnd() const;

    /**
     * Pushes back a new transformation onto the top of the chain.
     *
     * @tparam TransformationType The type of transformation the function is passed.
     * @param transformation The transformation to push.
     */
    template <typename TransformationType>
    void
    PushBack(TransformationType const& transformation)
    {
        m_TransformationList.push_back(
            std::unique_ptr<Transformation>(new TransformationType(transformation)));
        m_NeedUpdate = true;
    }
    /**
     * Adds a new transformation at the bottom of the chain.
     *
     * @tparam TransformationType The type of transformation the function is passed.
     * @param transformation The transformation to add.
     */
    template <typename TransformationType>
    void
    PushFront(TransformationType const& transformation)
    {
        Insert(transformation, Begin());
    }
    /**
     * Inserts a new transformation into the chain at the specified position.
     *
     * @tparam TransformationType The type of transformation the function is passed.
     * @param transformation The transformation to add.
     * @param index The position where to insert. If index equals the size of
     * the chain, the function behaves like PushBack.
     */
    template <typename TransformationType>
    const_iterator
    Insert(TransformationType const& transformation, size_type index)
    {
        return Insert(transformation, Middle(index));
    }
    /**
     * Inserts a new transformation into the chain at the specified position.
     *
     * @tparam TransformationType The type of transformation the function is passed.
     * @param transformation The transformation to add.
     * @param it The iterator that indicates the position where to insert.
     * @returns An const_iterator pointing at the new inserted element.
     */
    template <typename TransformationType>
    const_iterator
    Insert(TransformationType const& transformation, const_iterator it)
    {
        auto itm = m_TransformationList.begin();
        std::advance(itm, std::distance(Begin(), it));
        m_NeedUpdate = true;
        return const_iterator(m_TransformationList.insert(
            itm, std::unique_ptr<Transformation>
            (new TransformationType(transformation))));
    }

    /**
     * Replaces the transformation at the specified index with the given one.
     *
     * @tparam TransformationType The type of transformation the function is passed.
     * @param transformation The transformation to replace with.
     * @param index The index where to replace.
     */
    template <typename TransformationType>
    void
    Replace(TransformationType const& transformation, size_type index)
    {
        m_NeedUpdate = true;
        m_TransformationList[index] = 
            std::unique_ptr<Transformation>(new TransformationType(transformation));
    }

    /**
     * Replaces the transformation at the specified index with the given one.
     *
     * @tparam TransformationType The type of transformation the function is passed.
     * @param transformation The transformation to replace with.
     * @param it The iterator that indicates the position where to replace.
     * @returns The const_iterator pointing at the new transformation.
     */
    template <typename TransformationType>
    void
    Replace(TransformationType const& transformation,  const_iterator it)
    {
        auto itm = m_TransformationList.begin();
        std::advance(itm, std::distance(Begin(), it));
        m_NeedUpdate = true;
        *itm = std::unique_ptr<Transformation>
            (new TransformationType(transformation));
    }

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
     * @param it The iterator that indicates the position of the transformation to
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
     * Returns the transformation at the given index.
     *
     * @param index The index of the transformation.
     * @returns The transformation at index.
     */
    Transformation const&
    At(size_type index) const;

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
     * Accesses the last transformation of the chain.
     *
     * @returns The transformation at the end of the chain.
     */
    Transformation const&
    Back() const;
    
    /**
     * Returns the number of matrices in the transformation chain.
     *
     * @returns The number of transformations.
     */
    size_type
    Size() const;
    

    /**
     * Returns the matrix that represents the complete linear transformation.
     *
     * @returns The matrix. If no transformation is pushed onto the chain the
     * function serves undefined behaviour.
     */
    virtual Matrix const&
    GetMatrix() const;

};


}
}

#endif /* CE3D_TRANSFORMATION_CHAIN_H */
