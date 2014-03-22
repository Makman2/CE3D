// This file is part of CE3D. License: GPL3

#ifndef _MODEL_H
#define _MODEL_H

#include <string>
#include <boost/container/vector.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

namespace CE3D
{

/**
 * TODO
 */
class Model
{
public:
	
	std::string Name;
	boost::container::vector<boost::numeric::ublas::vector<model_data_t>> Vectors;


	RW_PROPERTY(public, bool, IsVisible);

	
private:
	

	
	
private:
};

}

#endif /* _MODEL_H */
