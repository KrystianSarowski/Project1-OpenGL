#pragma once

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

	//Position of the end goal in the world.
	vec3 m_position;

	//Rotation of the end goal.
	float m_rotation;

public:
	EndGoal();
	~EndGoal();

	//Collision rectangle ofr the end Goal;
	sf::RectangleShape m_collisionBox;

	void update();

	vec3 getPosition();

	mat4 getModelToWorldMatrix();

	void setPosition(vec3 position);
};

