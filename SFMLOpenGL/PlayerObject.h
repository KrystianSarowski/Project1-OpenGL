#pragma once
#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

#include <stdio.h>
#include <string.h>
#include <Cube.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Graphics.hpp>

using namespace glm;

class PlayerObject
{
private:
	// Cube Elements
	GLfloat vertex[ARRAY_SIZE(vertices)];
	GLfloat uv[ARRAY_SIZE(uvs)];
	GLfloat index[ARRAY_SIZE(indices)];

	vec3 m_previousPos;
	vec3 m_position;
	vec3 m_rotation;

	vec3 m_velocity;

public:
	PlayerObject();
	~PlayerObject();

	sf::RectangleShape m_collisionBox;

	void update(sf::Time t_deltaTime);

	vec3 getPosition();

	vec3 getPreviousPos();

	mat4 getModelToWorldMatrix();

	void setPosition(vec3 position);

	void onGround();

	// Returns the first element of the array
	GLfloat* getVertex();
	// 3 Vertices
	int getVertexCount();

	// Returns the first element of the array
	GLfloat* getUV();
	// 3 Colors RGB
	int getUVCount();

	// Returns the first element of the array
	GLfloat* getIndex();
	// 3 Colors RGB
	int getIndexCount();
};

