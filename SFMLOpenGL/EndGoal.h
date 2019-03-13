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

class EndGoal
{
private:
	// Cube Elements
	GLfloat vertex[ARRAY_SIZE(vertices)];
	GLfloat uv[ARRAY_SIZE(uvs)];
	GLfloat index[ARRAY_SIZE(indices)];

	vec3 m_position;
	float m_rotation;

public:
	EndGoal();
	~EndGoal();

	sf::RectangleShape m_collisionBox;

	void update();

	vec3 getPosition();

	mat4 getModelToWorldMatrix();

	void setPosition(vec3 position);
};

