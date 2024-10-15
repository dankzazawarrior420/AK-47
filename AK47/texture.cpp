#define STB_IMAGE_IMPLEMENTATION 
#include "stbi (TEXTURELOADER)/stb_image.h"
#include "GLAD2/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "texture.h"

unsigned int texture, texture1;


unsigned int setupTexture() {

	// generating texture 1
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// wrapping/filtering options 1
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// load and generate the texture 1
	int width, height, nrChannels;
	unsigned char* data = stbi_load("textures/grass/grass01.png", &width, &height, &nrChannels, 0);


	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

	}
	else
	{

		std::cout << "Failed to load texture" << std::endl;
	}


	stbi_image_free(data);


	return texture;

}

unsigned int setupTexture1() {


	stbi_set_flip_vertically_on_load(true);

	// generating texture 1
	glActiveTexture(GL_TEXTURE1);
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	// wrapping/filtering options 1
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// load and generate the texture 1
	int width, height, nrChannels;
	unsigned char* data = stbi_load("textures/CPUPhoto/cpu.jpg", &width, &height, &nrChannels, 0);


	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

	}
	else
	{

		std::cout << "Failed to load texture" << std::endl;
	}


	stbi_image_free(data);


	return texture1;

}
