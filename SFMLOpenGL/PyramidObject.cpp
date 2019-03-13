#include "PyramidObject.h"

PyramidObject::PyramidObject()
	: m_rotation(1.0f, 0.0f, 0.0f)
{
	m_position = vec3(0.0f, 0.0f, 0.0f);

	m_collisionBox.setSize(sf::Vector2f(1.5f, 1.5f));
	m_collisionBox.setOrigin(0.75f, 0.75f);
	m_collisionBox.setPosition(m_position.z, m_position.y);
}

PyramidObject::~PyramidObject()
{
}

vec3 PyramidObject::getPosition()
{
	return m_position;
}

mat4 PyramidObject::getModelToWorldMatrix()
{
	return mat4(translate(glm::mat4(1.f), m_position) * rotate(glm::mat4(1.f), 0.0f, m_rotation));
}
void PyramidObject::setPosition(vec3 position)
{
	m_position = position;
	m_collisionBox.setPosition(m_position.z, m_position.y);
}