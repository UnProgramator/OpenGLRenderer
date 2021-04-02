#pragma once
#include <GLEW/glew.h>

#include "glUtils.h"
#include "Mesh.h"

class SimpleCuber :
    public DirectMesh
{
private:
	unsigned int angleUniform = 0;
	unsigned int positionUniform = 0;
	unsigned int indexBuffer = 0;
	unsigned int vertexBuffer = 0;
	float angle =0;
	float poztion[3] = { 0.f, 0.f, 0.f };
	uint8_t indexNo;
public:
	virtual void setProgramm(unsigned int programmID) override{
		this->shaderProgramm = programmID;
		angleUniform = glGetUniformLocation(shaderProgramm, "uAngle");
		positionUniform = glGetUniformLocation(shaderProgramm, "uLocation");
	};
	virtual void setProgramm(const std::string& vertexShader, const std::string& fragmentShader) override {
		shaderProgramm = GLUtils::CreateShaders(vertexShader, fragmentShader);
		angleUniform = glGetUniformLocation(shaderProgramm, "uAngle");
		positionUniform = glGetUniformLocation(shaderProgramm, "uLocation");
	};

	virtual void attatchTexture(std::string& fileName) override {};
	virtual void attatchTexture(std::string& fileName, std::initializer_list<unsigned int> indexes) override {};
	virtual void draw() override;

	virtual void init(float[], int dimensions=3, int vertexNo=8) override;
	void setIndexBuffer(unsigned int indexes[], uint8_t size=36);
	void rotateZ(float angle) { this->angle += angle; }
	void move(float x, float y, float z) { poztion[0] = x; poztion[1] = y; poztion[2] = z;}
};

