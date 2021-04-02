#pragma once

#include <string>
#include <initializer_list>
#include "glutils.h"


class BasicMesh {
protected:
	GLuint shaderProgramm = 0;
public:
	virtual void setProgramm(unsigned int programmID) {
		this->shaderProgramm = programmID;
	};
	virtual void setProgramm(const std::string& vertexShader, const std::string& fragmentShader){
		shaderProgramm = GLUtils::CreateShaders(vertexShader, fragmentShader);
	};

	virtual void attatchTexture(std::string& fileName) = 0;
	virtual void attatchTexture(std::string& fileName, std::initializer_list<unsigned int> indexes) = 0;
	virtual void draw() = 0;
};

class DirectMesh: public BasicMesh {
public:
	virtual void init(float[], int dimensions, int vertexNo) = 0;
};

class Mesh: public BasicMesh {
public:
	virtual void fromFile(std::string& fileName) = 0;
	virtual void fromFile(std::ifstream& inputBufer) = 0;
};