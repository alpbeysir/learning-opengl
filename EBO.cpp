#include "EBO.h"

EBO::EBO(GLuint* indices, GLsizeiptr size)
{
	//Generate indices buffer
	glGenBuffers(1, &ID);
	//Bind so we can us it
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	//Set buffer data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void EBO::Bind()
{
	//Bind
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
	//Unbind
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	//Delete
	glDeleteBuffers(1, &ID);
}
