// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_LINEAR_CAMERA_CODE_H
#define CE3D_CAMERA_LINEAR_CAMERA_CODE_H

#include "camera/linear_camera.h"

namespace CE3D {

template <typename t_Material>
void LinearCamera<t_Material>::RecalculateMatrix() const
{
    m_AppendedTransformations = m_TransformationStack.size()-1;
    m_TransformationMatrix.SetMatrix(m_TransformationStack[0]->GetMatrix());
    AppendMatrices();
}

template <typename t_Material>
void LinearCamera<t_Material>::AppendMatrices() const
{
    for (std::uint8_t it = m_TransformationStack.size()
                         - m_AppendedTransformations;
         it < m_TransformationStack.size(); ++it)
    {
        m_TransformationMatrix.AppendTransformation(
            *(m_TransformationStack[it]));
    }
}

template <typename t_Material>
void LinearCamera<t_Material>::UpdateTransformation() const
{
    if (m_NeededUpdates > 0)
    {
        if (m_NeededUpdates == m_AppendedTransformations)
        {
            AppendMatrices();
        }
        else
        {
            RecalculateMatrix();
        }

        m_NeededUpdates = 0;
        m_AppendedTransformations = 0;
    }
}

template <typename t_Material>
std::unique_ptr<World<t_Material> > LinearCamera<t_Material>::Paint() const
{
    std::unique_ptr<World<t_Material> > TransformedWorld(new World());

    UpdateTransformation();

    TransformedWorld->Transform(m_TransformationMatrix);

    return std::move(TransformedWorld);
}

} /* namespace CE3D */

#endif /* CE3D_CAMERA_LINEAR_CAMERA_CODE_H */
