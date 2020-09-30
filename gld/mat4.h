# pragma once
# ifndef MAT4_H
# define MAT4_H

namespace gld {
	class mat4 {
		public:
			
			float m0, m1, m2, m3;
			float m4, m5, m6, m7;
			float m8, m9, m10, m11;
			float m12, m13, m14, m15;

			mat4();
			mat4(float matrix[16]);
	};
}

# endif
