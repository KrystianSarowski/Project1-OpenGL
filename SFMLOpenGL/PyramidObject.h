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

	//Position of the PyramidObject in the world.
	vec3 m_position;

	//Rotation of the PyramidObject.
	vec3 m_rotation;

public:
	PyramidObject();
	~PyramidObject();

	sf::RectangleShape m_collisionBox;

	vec3 getPosition();

	mat4 getModelToWorldMatrix();

	void setPosition(vec3 position);
};

