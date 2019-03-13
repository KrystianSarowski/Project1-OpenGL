#include "PlayerObject.h"

PlayerObject::PlayerObject() 
	: m_rotation(1.0f, 0.0f, 0.0f)
	, m_velocity(0.0f, 0.0f, 0.0f)
{


	m_position = vec3(0.0f, 0.0f, 0.0f);

	m_collisionBox.setSize(sf::Vector2f(2.0f, 2.0f));
	m_collisionBox.setOrigin(1.0f, 1.0f);
	m_collisionBox.setPosition(m_position.z, m_position.y);

	m_velocity.z = -0.08f;

}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::update(sf::Time t_deltaTime)
{
	m_previousPos = m_position;

	vec3 acceleration(0.0f, -0.00098f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (m_velocity.y == 0.0f)
		{
			m_velocity.y = 0.1f;
		}
	}

	m_position = m_position + m_velocity;
	m_velocity = m_velocity + acceleration;

	m_collisionBox.setPosition(m_position.z, m_position.y);
}

vec3 PlayerObject::getPosition() 
{ 
	return m_position; 
}

vec3 PlayerObject::getPreviousPos()
{
	return m_previousPos;
}

mat4 PlayerObject::getModelToWorldMatrix()
{
	return mat4(translate(glm::mat4(1.f), m_position) * rotate(glm::mat4(1.f), 0.0f, m_rotation));
}
void PlayerObject::setPosition(vec3 position)
{ 
	m_position = position;
	m_collisionBox.setPosition(m_position.z, m_position.y);
}

void PlayerObject::onGround()
{
	m_velocity.y = 0.0f;
}


