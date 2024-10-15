#include "SHADER.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "GLAD2/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char* VertexPath, const char* fragmentPath)
{
	// get vertex code + fragment code from filepath
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderfile;
	std::ifstream fShaderfile;

	// ensure ifstream objects can throw exceptions 
	vShaderfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files 
		vShaderfile.open(VertexPath);
		fShaderfile.open(fragmentPath);
		std::stringstream vShaderstream, fShaderstream;
		// read files buffer contents into streams
		vShaderstream << vShaderfile.rdbuf();
		fShaderstream << fShaderfile.rdbuf();
		// close file handlers
		vShaderfile.close();
		fShaderfile.close();
		// convert stream into string 
		vertexCode = vShaderstream.str();
		fragmentCode = fShaderstream.str();
	}

	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();


	// 2. compile shaders
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED \n" <<
			infoLog << std::endl;



	};

	// Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	// print compile errors if any 
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED \n" <<
			infoLog << std::endl;
	};

	// shader program 
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	// print linking errors
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED \n" <<
			infoLog << std::endl;

	}



	// delete shaders
	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

// activate shader

void Shader::use()
{
	glUseProgram(ID);

}

// utility uniform functions 

void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setVec3(const std::string& name, float x, float y, float z) const
{

	glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);

}
void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
{

	glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);

}
void Shader::setMat4(const std::string& name, glm::mat4 value) const
{

	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);

}
