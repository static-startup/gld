CC = g++
LIBS = -lGLEW -lGL -lglfw

install: example/main.cpp
	${CC} -fPIC -shared gld/mat4.cpp gld/shaders.cpp gld/vec2.cpp gld/vec3.cpp gld/vec4.cpp gld/gld.h gld/mat4.h gld/shaders.h gld/vec2.h gld/vec3.h gld/vec4.h -o gld/gld.so
	${CC} -I./ example/main.cpp gld/gld.so ${LIBS} -o a
