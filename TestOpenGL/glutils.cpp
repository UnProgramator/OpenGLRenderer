#include <GLEW/glew.h>
#include <cassert>
#include <string>
#include <ios>
#include <iostream>
#include <fstream>

#include <exception>

#include "glutils.h"

using std::operator""s;

std::string getShaderText(const std::string& srcFile) {
	std::ifstream fin(srcFile);

	if (!fin.is_open()) {
		std::cerr << "error: at file opening";
		abort();
	}

	return std::string(std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>());
}

static GLuint CompileAShader(GLuint type, const std::string& source) {
	const GLuint id = glCreateShader(type);
	const char* str = source.c_str();
	glShaderSource(id, 1, &str, nullptr);
	glCompileShader(id);

	GLint result=GL_FALSE;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		if (length < 0) {
			std::cerr << "incorect buffer size. Could not read a valid value from openGL";
			throw GLUtils::shaderException(std::string("shader") + source + "not compiled corectly; invalid msl length; could not obtain msg");
		}
		char* msg = new char[(uint64_t)length + 1];
		glGetShaderInfoLog(id, length, &length, msg);
		std::cerr << "Failed to compile shader.\nError message: "<< msg;
		throw GLUtils::shaderException(std::string("shader") + source + "not compiled corectly" + msg);
	}

	return id;
}

GLuint GLUtils::CreateShaders(const std::string& vertexShader, const std::string& fragmentShader)
{
	try {
		
		GLuint program = glCreateProgram();

		GLuint vs = CompileAShader(GL_VERTEX_SHADER, getShaderText(vertexShader));
		GLuint fs = CompileAShader(GL_FRAGMENT_SHADER, getShaderText(fragmentShader));
		

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		std::cout << std::endl;

		return program;
	}
	catch (GLUtils::shaderException e) {
		
		throw GLUtils::shaderException("Error in compiling "s + vertexShader + " and " + fragmentShader + "\n" + e.what());
	}
	catch (std::ifstream::failure e) {
		std::cerr << "Error in file manipulation" << e.what() << std::endl;
		throw GLUtils::shaderException(e.what());
	}
}
