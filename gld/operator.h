# pragma once
# ifndef OPERATOR_H
# define OPERATOR_H

# include "mat4.h"
# include "vec4.h"

namespace gld {
	vec4 operator*(vec4 vec, mat4 mat);
}

# endif
