#include <GLEW/glew.h>
#include <cstring>
#include <iostream>

#include "glutils.h"
#include "test_triangle.h"

void test_triangle::init(float vertices[], int dimensions, int vertexNo)
{
	glGenBuffers(1, &(this->vertexBuffer));

	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 3 * dimensions * sizeof(float), vertices, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, dimensions, GL_FLOAT, GL_FALSE, dimensions *sizeof(float), 0);
	shaderProgramm = GLUtils::CreateShaders("D:\\Scoala\\Licenta\\TestOpenGL\\TestOpenGL\\vertexShaderTest.glsl", "D:\\Scoala\\Licenta\\TestOpenGL\\TestOpenGL\\fragmentShaderTest.glsl");
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void test_triangle::draw()
{
	glUseProgram(this->shaderProgramm);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glUseProgram(0);
}

void test_triangle::changeData(float vertices[], int size)
{
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
}

