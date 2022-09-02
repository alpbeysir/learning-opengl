#include "Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
	//Load texture from file
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load(image, &width, &height, &numColCh, 0);

	//Generate texture
	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(texType, ID);

	//Set parameters like filtering, wrap etc.
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_R, GL_REPEAT);

	//Read texture data from char array
	glTexImage2D(texType, 0, GL_RGBA, width, height, 0, format, pixelType, bytes);

	//Generate mipmaps
	glGenerateMipmap(texType);

	//Clean up
	stbi_image_free(bytes);
}
void Texture::TexUnit(Shader& shader, const char* uniform, GLuint unit)
{
	//Activating shader is necessary before accessing uniform
	shader.Activate();
	//Get location in memory
	GLuint uniLoc = glGetUniformLocation(shader.ID, uniform);
	//Set texture unit 
	glUniform1i(uniLoc, unit);
}
void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}
