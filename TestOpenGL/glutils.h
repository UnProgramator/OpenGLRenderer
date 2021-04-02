#pragma once
#include <string>
#include <exception>

namespace GLUtils {

	GLuint CreateShaders(const std::string& vertexShader, const std::string& fragmentShader);

	class shaderException :public std::exception {
	public:
		shaderException() = delete;
		shaderException(const char* msg):std::exception(msg) {}
		shaderException(const std::string&msg) :shaderException(msg.c_str()) {}
		~shaderException(){}
	};
}
