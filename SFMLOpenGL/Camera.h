#pragma once
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera();

	void update(glm::vec3 t_playerPos);

	glm::mat4 getWorldToViewMatrix() const;

private:

	//The position that the camera is located at.
	glm::vec3 m_position;

	//The position at which the camera is looking at.
	glm::vec3 m_viewDirection; 

	//Offset by which the camera is moved from the passed in position.
	glm::vec3 m_offSet;

	//We are looking normaly.
	const glm::vec3 UP;

	//Checks if we are trying to rotate the camera.
	bool m_rotate;

	//Checks if we have rotated the camera.
	bool m_rotated;
};

