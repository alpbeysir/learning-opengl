#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>
#include "shaderClass.h"

class Texture {
public:
	GLuint ID;
	int width, height, numColCh;

	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
	
	void TexUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();
};


#endif
