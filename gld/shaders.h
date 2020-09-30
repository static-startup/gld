# pragma once
# ifndef SHADERS_H
# define SHADERS_H

# include "GL/glew.h"
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

namespace gld {
	GLuint load_shaders(std::string vertex_path, std::string fragment_path);
}

# endif
