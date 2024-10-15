#ifndef SHADER_H
#define SHADER_H

#include "GLAD2/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



class Shader {

public:
	// program ID
	unsigned int ID;

	// constructor reads and builds the shader
	Shader(const char* VertexPath, const char* fragmentPath);

	// activate the shader
	void use();

	// utility uniform functions 
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec4(const std::string& name, float x, float y, float z, float w) const;
	void setMat4(const std::string& name, glm::mat4 value) const;


};

#endif

