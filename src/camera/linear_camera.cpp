// This file is part of CE3D. License: GPL3

#include "camera/linear_camera.h"

namespace CE3D {

void LinearCamera::RecalculateMatrix() const
{
    m_AppendedTransformations = m_TransformationStack.size()-1;
    m_TransformationMatrix.SetMatrix(m_TransformationStack[0]->GetMatrix());
    AppendMatrices();
}

void LinearCamera::AppendMatrices() const
{
    for (std::uint8_t it = m_TransformationStack.size()
                         - m_AppendedTransformations;
         it < m_TransformationStack.size(); ++it)
    {
        m_TransformationMatrix.AppendTransformation(
            *(m_TransformationStack[it]));
    }
}

void LinearCamera::UpdateTransformation() const
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

std::unique_ptr<World> LinearCamera::Paint() const
{
    std::unique_ptr<World> TransformedWorld(new World());

    UpdateTransformation();

    TransformedWorld->Transform(m_TransformationMatrix);

    return std::move(TransformedWorld);
}

} /* namespace CE3D */
