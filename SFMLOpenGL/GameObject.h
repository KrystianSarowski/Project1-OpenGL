#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

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

class GameObject
{
private:

	vec3 m_position;
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

