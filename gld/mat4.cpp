# include "mat4.h"

namespace gld {
	mat4::mat4() {
		m0 = 0.0f;
		m1 = 0.0f;
		m2 = 0.0f;
		m3 = 0.0f;
		m4 = 0.0f;
		m5 = 0.0f;
		m6 = 0.0f;
		m7 = 0.0f;
		m8 = 0.0f;
		m9 = 0.0f;
		m10 = 0.0f;
		m11 = 0.0f;
		m12 = 0.0f;
		m13 = 0.0f;
		m14 = 0.0f;
	}

	mat4::mat4(float matrix[16]) {
		m0 = matrix[0];
		m1 = matrix[1];
		m2 = matrix[2];
		m3 = matrix[3];
		m4 = matrix[4];
		m5 = matrix[5];
		m6 = matrix[6];
		m7 = matrix[7];
		m8 = matrix[8];
		m9 = matrix[9];
		m10 = matrix[10];
		m11 = matrix[11];
		m12 = matrix[12];
		m13 = matrix[13];
		m14 = matrix[14];
		m15 = matrix[15];
	}
}
