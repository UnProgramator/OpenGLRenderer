#pragma once
#include <GLEW/glew.h>

#include "glUtils.h"
#include "Mesh.h"

class SimplePolygon :
    public DirectMesh
{
	GLuint vertexNumber;
	GLuint vertexBuffer =0;
	
	GLuint angleUniform = 0;
	GLfloat angle = 0.f;

public:

	SimplePolygon(int vertexNumber) : vertexNumber(vertexNumber) {}

	virtual void setProgramm(unsigned int programmID) { 
		this->shaderProgramm = programmID; 
		angleUniform = glGetUniformLocation(shaderProgramm, "uAngle");
	};
	virtual void setProgramm(const std::string& vertexShader, const std::string& fragmentShader) override {
		shaderProgramm = GLUtils::CreateShaders(vertexShader, fragmentShader);
		angleUniform = glGetUniformLocation(shaderProgramm, "uAngle");
	};

	virtual void init(float[], int dimensions, int vertexNo) override;
	virtual void attatchTexture(std::string& fileName) override {};
	virtual void draw() override;
	virtual void rotateZ(float angle) { this->angle += angle; }
};

