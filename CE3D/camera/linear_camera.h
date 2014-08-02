// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_LINEAR_CAMERA_H
#define CE3D_CAMERA_LINEAR_CAMERA_H

#include "CE3D/util/stdinc.h"

#include "CE3D/util/CE3D_matrix.h"
#include "CE3D/camera/camera.h"
#include "CE3D/transformation/transformation.h"
#include "CE3D/transformation/custom.h"
#include "CE3D/world/world.h"
#include "CE3D/transformation/transformation_chain.h"

namespace CE3D {

/**
 * This is a camera that applies an arbitrary set of transformations on render.
 */
template <typename MaterialType>
class LinearCamera : public Camera<MaterialType> {
private:
    /**
     * A chain of transformations applied sequentially on Paint().
     */
    Transformation::TransformationChain m_TransformationChain;

protected:
    /**
     * Returns a chain of transformations applied sequentially on Paint().
     *
     * @returns The transformation chain.
     */
    Transformation::TransformationChain&
    GetTransformationChain();

    /**
     * Returns a chain of transformations applied sequentially on Paint().
     * This version returns a const-type.
     *
     * @returns The transformation chain.
     */
    Transformation::TransformationChain const&
    GetTransformationChain() const;

public:
    /**
     * The type of material used for the camera.
     */
    using material_type = MaterialType;
    
    LinearCamera();
    
    virtual
    ~LinearCamera();

    /**
     * Applies all transformations on the transformation stack and returns the
     * newly created world.
     *
     * @return a unique_ptr to the new world - the caller is responsible for
     * tidying up!
     */
    std::unique_ptr<World<MaterialType> >
    Paint() const final override;
};

} /* namespace CE3D */

#include "linear_camera_code.h"

#endif /* CE3D_CAMERA_LINEAR_CAMERA_H */
