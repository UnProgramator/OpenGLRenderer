#ifndef __TEST_TRIANGLE_H__INCLUDED_
#define __TEST_TRIANGLE_H__INCLUDED_

#include <GLEW/glew.h>
#include "Mesh.h"


class test_triangle :public DirectMesh
{
private:
	GLuint vertexBuffer;


public:
	test_triangle() =default;
	test_triangle(const test_triangle&) = delete;
	test_triangle(test_triangle&&) = delete;

	test_triangle& operator=(const test_triangle&) = delete;
	test_triangle& operator=(test_triangle&&) = delete;

	virtual void init(float vertices[], int dimensions = 3, int vertexNo=3) override;

	virtual void draw() override;

	void changeData(float vertices[], int size);

	virtual void attatchTexture(std::string& fileName) override {};
};

#endif
