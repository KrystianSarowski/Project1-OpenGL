#pragma once

#include <stdio.h>
#include <string.h>
#include <Pyramid.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Graphics.hpp>

using namespace glm;

class PyramidObject
{
private:

	vec3 m_position;
	vec3 m_rotation;

public:
	PyramidObject();
	~PyramidObject();

	sf::RectangleShape m_collisionBox;

	vec3 getPosition();

	mat4 getModelToWorldMatrix();

	void setPosition(vec3 position);
};

