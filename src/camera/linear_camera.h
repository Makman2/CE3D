// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_LINEAR_CAMERA_H
#define CE3D_CAMERA_LINEAR_CAMERA_H

#include "util/stdinc.h"

#include "camera/camera.h"
#include "transformation/transformation.h"

namespace CE3D {

class LinearCamera : Camera {
private:
    /**
     * A list of transformations applied sequentially on Paint().
     */
    std::vector<std::shared_ptr<Transformation::Transformation const>>
        m_TransformationStack;
public:
    LinearCamera();
    virtual ~LinearCamera();

    virtual std::unique_ptr<World>
    Paint() const override;
};

} /* namespace CE3D */

#endif /* CE3D_CAMERA_LINEAR_CAMERA_H */
