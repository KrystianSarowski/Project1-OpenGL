#include "Camera.h"

Camera::Camera()
	: m_viewDirection(0.0f, 0.0f, 0.0f)
	, m_position(10.0f, 10.0f, 0.0f)
	, UP(0.0f, 1.0f, 0.0f)
	, m_offSet(20.0f, 0.0, 0.0f)
{
}

void Camera::update(glm::vec3 t_playerPos)
{
	m_position = t_playerPos + m_offSet;
	m_viewDirection = t_playerPos;
}


glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(m_position, m_viewDirection, UP);
}
