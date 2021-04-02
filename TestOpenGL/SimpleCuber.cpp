#include "SimpleCuber.h"

void SimpleCuber::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBuffer);
	glUseProgram(this->shaderProgramm);
	glUniform1f(this->angleUniform, this->angle);
	glUniform3f(this->positionUniform, this->poztion[0], this->poztion[1], this->poztion[2]);

	glDrawElements(GL_TRIANGLES, indexNo, GL_UNSIGNED_INT, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glUseProgram(0);
}

void SimpleCuber::init(float vertices[], int dimensions, int vertexNo)
{
	glGenBuffers(1, &(this->vertexBuffer));

	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexNo * (4 + dimensions) * sizeof(float), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, dimensions, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7*sizeof(float), (void*)(3 * sizeof(float)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SimpleCuber::setIndexBuffer(unsigned int indexes[], uint8_t size)
{
	indexNo = size;
	glGenBuffers(1, &(this->indexBuffer));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indexes, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
