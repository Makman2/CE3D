// This file is part of CE3D. License: GPL3

#include "camera.h"

#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>


namespace CE3D
{

	World Camera::GetWorld()
	{
		return this->m_World;
	}

	void Camera::SetWorld(World value)
	{
		this->m_World = value;
	}
}