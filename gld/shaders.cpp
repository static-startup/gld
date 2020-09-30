# include "shaders.h"

namespace gld {
	GLuint load_shaders(std::string vertex_path, std::string fragment_path) {
		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertex_shader_source;
		std::ifstream read(vertex_path);
		if(read.is_open()) {
			std::stringstream stream;
			stream << read.rdbuf();
			vertex_shader_source = stream.str();
			read.close();
		} else {
			std::cerr << "cannot open \"" << vertex_path << "\" as vertex shader\n";
			exit(-1);
		}

		std::string fragment_shader_source;
		read = std::ifstream(fragment_path);
		if(read.is_open()) {
			std::stringstream stream;
			stream << read.rdbuf();
			fragment_shader_source = stream.str();
			read.close();
		} else {
			std::cerr << "cannot open \"" << fragment_path << "\" as fragment shader\n";
			exit(-1);
		}

		int log_length;

		char const *vertex_c_str = vertex_shader_source.c_str();
		glShaderSource(vertex_shader, 1, &vertex_c_str, NULL);
		glCompileShader(vertex_shader);
		
		glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &log_length);
		if(log_length > 0) {
			char error_message[log_length + 1];
			glGetShaderInfoLog(vertex_shader, log_length, NULL, &error_message[0]);
			std::cout << &error_message[0] << std::endl;
			exit(-1);
		}

		char const *fragment_c_str = fragment_shader_source.c_str();
		glShaderSource(fragment_shader, 1, &fragment_c_str, NULL);
		glCompileShader(fragment_shader);

		glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &log_length);
		if(log_length > 0) {
			char error_message[log_length + 1];
			glGetShaderInfoLog(fragment_shader, log_length, NULL, &error_message[0]);
			std::cout << &error_message[0] << std::endl;
			exit(-1);
		}

		GLuint program = glCreateProgram();
		glAttachShader(program, vertex_shader);
		glAttachShader(program, fragment_shader);
		glLinkProgram(program);

		glGetProgramiv(fragment_shader, GL_INFO_LOG_LENGTH, &log_length);
		if(log_length > 0) {
			char error_message[log_length + 1];
			glGetProgramInfoLog(program, log_length, NULL, &error_message[0]);
			std::cout << &error_message[0] << std::endl;
			exit(-1);
		}

		glDetachShader(program, vertex_shader);
		glDetachShader(program, fragment_shader);
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		return program;
	}
}
