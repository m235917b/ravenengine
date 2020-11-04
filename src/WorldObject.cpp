/*
 * WorldObject.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#include <glm\gtx\rotate_vector.hpp>
#include <loadShader.hpp>
#include <WorldObject.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

WorldObject::WorldObject(float posX, float posY, float posZ) {
	programID = loadShaders("shader/vertexShader.vert",
			"shader/fragmentShader.frag");

	model = glm::mat4(1.0f);

	pos = glm::vec3(posX, posY, posZ);
	rot = glm::vec3(0.0f, 1.0f, 0.0f);
	angle = 0.0f;

	matrixID = glGetUniformLocation(programID, "MVP");

	textureID = 0;

	vertexbuffer = 0;
	normalbuffer = 0;
	texbuffer = 0;
	indexbuffer = 0;
	vertexarray = 0;
	vertexCount = 0;
}

WorldObject::~WorldObject() {

}

void WorldObject::genBuffers(std::vector<GLfloat> &vertexData,
		std::vector<GLfloat> &normalData, std::vector<GLfloat> &texData,
		std::vector<GLuint> &indexData) {
	glGenVertexArrays(1, &vertexarray);
	glBindVertexArray(vertexarray);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER,
			vertexData.size() * sizeof(GLfloat), vertexData.data(),
			GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER,
			normalData.size() * sizeof(GLfloat), normalData.data(),
			GL_STATIC_DRAW);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &texbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, texbuffer);
	glBufferData(GL_ARRAY_BUFFER, texData.size() * sizeof(GLfloat),
			texData.data(),
			GL_STATIC_DRAW);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &indexbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			indexData.size() * sizeof(GLuint), indexData.data(),
			GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glDeleteBuffers(1, &colorbuffer);
	//glDeleteBuffers(1, &vertexbuffer);

	glBindVertexArray(0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	//glDeleteVertexArrays(1, &vertexarray);

	vertexCount = indexData.size() + 1;
}

void WorldObject::genTexture(const char *path) {
	// load image, create texture
	int width, height, nrChannels;
	// load image file with stbi library
	unsigned char *imageBuffer = stbi_load(path, &width, &height,
			&nrChannels, 0);

	// load and create a texture
	// -------------------------
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// set the texture on the device
	GLenum colorFormat = GL_RGB;
	if (nrChannels == 4)
		colorFormat = GL_RGBA;

	glTexImage2D(GL_TEXTURE_2D, 0, colorFormat, width, height, 0, colorFormat,
	GL_UNSIGNED_BYTE, imageBuffer);
	//glGenerateMipmap(GL_TEXTURE_2D);

	// free memory for loaded image
	stbi_image_free(imageBuffer);
}

void WorldObject::run() {

}

void WorldObject::move(glm::vec3 dist) {
	pos += dist;
}

void WorldObject::render(glm::mat4 &projection, glm::mat4 &view) {
	run();

	glm::mat4 mvp = projection * view
			* glm::rotate(glm::translate(model, pos), angle, rot);

	glUseProgram(programID);
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glBindVertexArray(vertexarray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexbuffer);
	glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);
}

