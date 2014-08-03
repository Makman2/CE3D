// This file is part of CE3D. License: GPL3

#include "CE3D/transformation/final_translation.h"

namespace CE3D
{
namespace Transformation
{

FinalTranslation::FinalTranslation()
{}

FinalTranslation::FinalTranslation(Vector const& translation)
: Translation(translation)
{}

FinalTranslation::~FinalTranslation()
{}

void FinalTranslation::UpdateMatrix() const
{
    Translation::UpdateMatrix();
    
    // Delete last line of Translation matrix.

    m_Matrix.resize(m_Matrix.size1() - 1, m_Matrix.size2(), true);
}


}
}
