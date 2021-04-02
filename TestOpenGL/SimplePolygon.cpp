#include "SimplePolygon.h"
#include "glutils.h"


void SimplePolygon::init(float vertices[], int dimensions, int vertexNo)
{
	vertexNumber = vertexNo;
	glGenBuffers(1, &(this->vertexBuffer));

	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexNumber * dimensions * sizeof(float), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, dimensions, GL_FLOAT, GL_FALSE, dimensions * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SimplePolygon::draw()
{
	glUseProgram(this->shaderProgramm);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glUniform1f(this->angleUniform, this->angle);
	glDrawArrays(GL_POLYGON, 0, vertexNumber);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glUseProgram(0);
}
