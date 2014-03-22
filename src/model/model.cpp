// This file is part of CE3D. License: GPL3

#include "model.h"

#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>

namespace CE3D
{
	// TODO: Doxygen comments.
	void Model::Transform(boost::numeric::ublas::matrix<model_data_t> matrix)
	{

		for (boost::container::vector<model_data_t>::size_type
			 i = this->Vectors().begin; i != this->Vectors().end; i++)
		{
			boost::numeric::ublas::axpy_prod(matrix, this->Vectors().at(i), this->Vectors().at(i), true);
		}
		
	}

}
