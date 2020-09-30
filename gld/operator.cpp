# include "operator.h"

namespace gld {
	vec4 operator*(vec4 vec, mat4 mat) {
		vec.multiply(mat);
		return vec;
	}
}
