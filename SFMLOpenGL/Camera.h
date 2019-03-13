#pragma once
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();

	void update(glm::vec3 t_playerPos);

	glm::mat4 getWorldToViewMatrix() const;

private:

	glm::vec3 m_position;
	glm::vec3 m_viewDirection; 
	glm::vec3 m_offSet;
	const glm::vec3 UP;
};

