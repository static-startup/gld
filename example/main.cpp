# include <iostream>
# include <fstream>
# include <sstream>
# include <stdlib.h>
# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include "gld/gld.h"

int main() {
	// create window
	glewExperimental = true;
	if(!glfwInit()) {
		std::cerr << "Failed to initialize GLFW." << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(640, 640, "title", NULL, NULL);
	if(window == NULL) {
		std::cerr << "Failed to create window." << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	if(glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW." << std::endl;
		return -1;
	}

	// make vertex array object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// define vertices of triangle
	gld::vec4 v1(-0.5f, -0.5f, 0.0f, 1.0f);
	gld::vec4 v2(0.5f, -0.5f, 0.0f, 1.0f);
	gld::vec4 v3(0.0f, 1.0f, 0.0f, 1.0f);

	// load shaders
	GLuint program = gld::load_shaders("../res/shaders/triangle.vertex", "../res/shaders/triangle.fragment");

	// make vbo of triangle
	GLuint vb;
	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// loop until esc pressed or glfw should close
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) != true) {
		float speed = 0.05f;

		// moving object
		//v1.translate(gld::vec3(speed, 0.0f, 0.0f));
		//v2.translate(gld::vec3(speed, 0.0f, 0.0f));
		//v3.translate(gld::vec3(speed, 0.0f, 0.0f));
		v1.rotate(gld::vec2(0.0f, 0.0f), speed);
		v2.rotate(gld::vec2(0.0f, 0.0f), speed);
		v3.rotate(gld::vec2(0.0f, 0.0f), speed);

		// define vertices
		GLfloat vertices[] = {
			v1.x, v1.y, v1.z,
			v2.x, v2.y, v2.z,
			v3.x, v3.y, v3.z,
		};

		//std::cout << vertices[0] << " " << v1.x << std::endl;

		// buffer data 
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// clear and use shader
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);

		// draw
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vb);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);

		// swap buffers and get events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
