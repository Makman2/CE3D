// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_LINEAR_CAMERA_H
#define CE3D_CAMERA_LINEAR_CAMERA_H

#include "util/stdinc.h"

#include "util/CE3D_matrix.h"
#include "camera/camera.h"
#include "transformation/transformation.h"
#include "transformation/custom.h"
#include "world/world.h"

namespace CE3D {

/**
 * This is a camera that applies an arbitrary set of transformations on render.
 */
class LinearCamera : Camera {
private:
    /**
     * A list of transformations applied sequentially on Paint().
     */
    std::vector<std::shared_ptr<Transformation::Transformation const> >
        m_TransformationStack;

    /**
     * The product of all matrices on the transformation stack.
     */
    mutable Transformation::Custom m_TransformationMatrix;

    /**
     * Contains the number of matrices on the transformation stack that are
     * new or deleted.
     */
    mutable std::uint8_t m_NeededUpdates;
    /**
     * Contains the number of matrices on the transformation stack that are
     * appended.
     */
    mutable std::uint8_t m_AppendedTransformations;

    /**
     * Updates the transformation matrix if needed.
     */
    void UpdateTransformation() const;

    /**
     * Recalculates the whole transformation matrix.
     */
    void RecalculateMatrix() const;

    /**
     * Appends new transformation matrices.
     */
    void AppendMatrices() const;


public:
    inline
    LinearCamera() {};
    inline virtual
    ~LinearCamera() {};

    /**
     * Applies all transformations on the transformation stack and returns the
     * newly created world.
     *
     * @return a unique_ptr to the new world - the caller is responsible for
     *         tidying up!
     */
    virtual std::unique_ptr<World>
    Paint() const override;
};

} /* namespace CE3D */

#endif /* CE3D_CAMERA_LINEAR_CAMERA_H */
