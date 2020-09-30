# include "vec3.h"

namespace gld {
	vec3::vec3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(float x_, float y_, float z_) {
		x = x_;
		y = y_;
		z = z_;
	}
}
