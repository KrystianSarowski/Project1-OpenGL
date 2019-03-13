#include <GameObject.h>

GameObject::GameObject() 
	: m_rotation(1.0f, 0.0f, 0.0f)
{
	m_position = vec3(0.0f, 0.0f, 0.0f);

	m_collisionBox.setSize(sf::Vector2f(2.0f, 2.0f));
	m_collisionBox.setOrigin(1.0f, 1.0f);
	m_collisionBox.setPosition(m_position.z, m_position.y);
}

GameObject::~GameObject() 
{
}

vec3 GameObject::getPosition() 
{ 
	return m_position; 
}

mat4 GameObject::getModelToWorldMatrix()
{
	return mat4(translate(glm::mat4(1.f), m_position) * rotate(glm::mat4(1.f), 0.0f, m_rotation));
}
void GameObject::setPosition(vec3 position) 
{ 
	m_position = position;
	m_collisionBox.setPosition(m_position.z, m_position.y);
}