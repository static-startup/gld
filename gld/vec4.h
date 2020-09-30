# pragma once
# ifndef VEC4_H
# define VEC4_H

# include "vec3.h"
# include "vec2.h"
# include "mat4.h"

namespace gld {
	class vec4 {
		public:

			float x;
			float y;
			float z;
			float w;

			vec4();
			vec4(float x_, float y_, float z_, float w_);
			void multiply(mat4 mat);
			void translate(vec3 vec);
			void translate(vec2 vec);
	};
}

# endif
