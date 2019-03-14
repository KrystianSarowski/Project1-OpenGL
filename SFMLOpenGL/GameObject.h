#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <stdio.h>
#include <string.h>
#include <Cube.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Graphics.hpp>

using namespace glm;

class GameObject
{
private:

	//Position of the GameObject in the world.
	vec3 m_position;

	//Rotation of the GameObject.
	vec3 m_rotation;

public:
	GameObject();
	~GameObject();

	sf::RectangleShape m_collisionBox;

	vec3 getPosition();

	mat4 getModelToWorldMatrix();

	void setPosition(vec3 position);
};

#endif // !GAME_OBJECT_H

