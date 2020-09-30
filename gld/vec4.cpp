# include "vec4.h"

# include <cmath>
# include <iostream>

namespace gld {
	vec4::vec4() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	vec4::vec4(float x_, float y_, float z_, float w_) {
		x = x_;
		y = y_;
		z = z_;
		w = w_;
	}

	void vec4::multiply(mat4 mat) {
		float t_x, t_y, t_z, t_w;
		t_x = mat.m0 * x + mat.m1 * y + mat.m2 * z + mat.m3 * w;
		t_y = mat.m4 * x + mat.m5 * y + mat.m6 * z + mat.m7 * w;
		t_z = mat.m8 * x + mat.m9 * y + mat.m10 * z + mat.m11 * w;
		t_w = mat.m12 * x + mat.m13 * y + mat.m14 * z + mat.m15 * w;
		x = t_x;
		y = t_y;
		z = t_x;
		w = t_w;
	}

	void vec4::translate(vec3 vec) {
		float translation_matrix[16] = {1.0f, 0.0f, 0.0f, vec.x,
										0.0f, 1.0f, 0.0f, vec.y,
										0.0f, 0.0f, 1.0f, vec.z,
										0.0f, 0.0f, 0.0f, 1.0f};
		multiply(mat4(translation_matrix));
	}

	void vec4::translate(vec2 vec) {
		float translation_matrix[16] = {1.0f, 0.0f, 0.0f, vec.x,
										0.0f, 1.0f, 0.0f, vec.y,
										0.0f, 0.0f, 1.0f, 0.0f,
										0.0f, 0.0f, 0.0f, 1.0f};
		multiply(mat4(translation_matrix));
	}

	void vec4::scale(vec3 vec) {
		float scaling_matrix[16] = {vec.x, 0.0f, 0.0f, 0.0f,
									0.0f, vec.y, 0.0f, 0.0f,
									0.0f, 0.0f, vec.z, 0.0f,
									0.0f, 0.0f, 0.0f, 1.0f};
		multiply(mat4(scaling_matrix));
	}

	void vec4::scale(vec2 vec) {
		float scaling_matrix[16] = {vec.x, 0.0f, 0.0f, 0.0f,
									0.0f, vec.y, 0.0f, 0.0f,
									0.0f, 0.0f, 1.0f, 0.0f,
									0.0f, 0.0f, 0.0f, 1.0f};
		multiply(mat4(scaling_matrix));
	}

	void vec4::rotate(vec2 pivot, float delta) {
		float rotation_matrix[16] = {static_cast<float>(cos(delta)), static_cast<float>(-sin(delta)), 0.0f, 0.0f,
									 static_cast<float>(sin(delta)), static_cast<float>(cos(delta)), 0.0f, 0.0f,
									 0.0f, 0.0f, 1.0f, 0.0f,
									 0.0f, 0.0f, 0.0f, 1.0f};
		multiply(mat4(rotation_matrix));
	}

	void vec4::rotate(vec2 vec) {

	}
}
