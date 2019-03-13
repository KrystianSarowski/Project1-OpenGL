#include "EndGoal.h"

EndGoal::EndGoal()
	: m_rotation(0.0f)
{
	// Copy the Cube contents into GameObject
	memcpy(vertex, vertices, sizeof(vertex));
	memcpy(uv, uvs, sizeof(uv));

	// Copy UV's to all faces
	for (int i = 1; i < 6; i++)
	{
		memcpy(&uv[i * 4 * 2], &uv[0], 2 * 4 * sizeof(GLfloat));
	}

	memcpy(index, indices, sizeof(index));

	m_position = vec3(0.0f, 0.0f, 0.0f);

	m_collisionBox.setSize(sf::Vector2f(2.0f, 2.0f));
	m_collisionBox.setOrigin(1.0f, 1.0f);
	m_collisionBox.setPosition(m_position.z, m_position.y);
}


EndGoal::~EndGoal()
{
}

void EndGoal::update()
{
	m_rotation += 0.01f;

	if (m_rotation > 360.0f)
	{
		m_rotation = 0.0f;
	}
}

vec3 EndGoal::getPosition()
{
	return m_position;
}

mat4 EndGoal::getModelToWorldMatrix()
{
	return mat4(translate(glm::mat4(1.f), m_position) * rotate(glm::mat4(1.f), m_rotation, vec3(1.0f, 0.0f, 0.0f)));
}
void EndGoal::setPosition(vec3 position)
{
	m_position = position;
	m_collisionBox.setPosition(m_position.z, m_position.y);
}

// Returns the first element of the Vertex array
GLfloat* EndGoal::getVertex() { return vertex; }
// 3 Vertices
int EndGoal::getVertexCount() { return ARRAY_SIZE(vertex) / 3; }

// Returns the first element of the UV array
GLfloat* EndGoal::getUV() { return uv; }
// 3 Colors RGB
int EndGoal::getUVCount() { return ARRAY_SIZE(uv); }

// Returns the first element of the Index array
GLfloat* EndGoal::getIndex() { return index; }
// 3 Colors RGB
int EndGoal::getIndexCount() { return ARRAY_SIZE(index) / 3; }
