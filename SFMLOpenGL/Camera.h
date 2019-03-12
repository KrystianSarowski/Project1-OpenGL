#pragma once
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();
	void mouseUpdate(const glm::vec2& newMousePosition);
	glm::mat4 getWorldToViewMatrix() const;

private:

	glm::vec3 m_position;
	glm::vec3 m_viewDirection; 
	const glm::vec3 UP;
};

