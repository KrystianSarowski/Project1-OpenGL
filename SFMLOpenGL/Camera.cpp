#include "Camera.h"

Camera::Camera()
	: m_viewDirection(0.0f, 0.0f, 0.0f)
	, m_position(0.0f, 10.0f, 10.0f)
	, UP(0.0f, 1.0f, 0.0f)
{
}

void Camera::mouseUpdate(const glm::vec2 & newMousePosition)
{
}

glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(m_position, m_viewDirection, UP);
}
