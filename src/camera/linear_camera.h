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

class LinearCamera : Camera {
private:
    /**
     * A list of transformations applied sequentially on Paint().
     */
    std::vector<std::shared_ptr<Transformation::Transformation const>>
        m_TransformationStack;

    mutable Transformation::Custom m_TransformationMatrix;

    mutable std::uint8_t m_NeededUpdates;
    mutable std::uint8_t m_AppendedTransformations;

    void UpdateTransformation() const;
    void RecalculateMatrix() const;
    void AppendMatrices() const;
public:
    inline
    LinearCamera() {};
    inline virtual
    ~LinearCamera() {};

    virtual std::unique_ptr<World>
    Paint() const override;
};

} /* namespace CE3D */

#endif /* CE3D_CAMERA_LINEAR_CAMERA_H */
