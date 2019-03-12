#include "PlayerObject.h"

PlayerObject::PlayerObject() :
	m_rotation(1.0f, 0.0f, 0.0f)
{
	// Copy the Cube contents into GameObject
	memcpy(vertex, vertices, sizeof(vertex));
	memcpy(color, colors, sizeof(color));
	memcpy(uv, uvs, sizeof(uv));

	// Copy UV's to all faces
	for (int i = 1; i < 6; i++)
		memcpy(&uv[i * 4 * 2], &uv[0], 2 * 4 * sizeof(GLfloat));

	memcpy(index, indices, sizeof(index));

	m_position = vec3();
}

PlayerObject::~PlayerObject()
{
}

vec3 PlayerObject::getPosition() { return m_position; }

mat4 PlayerObject::getModelToWorldMatrix()
{
	return mat4(translate(glm::mat4(1.f), m_position) * rotate(glm::mat4(1.f), 0.0f, m_rotation));
}
void PlayerObject::setPosition(vec3 position) { m_position = position; }

// Returns the first element of the Vertex array
GLfloat* PlayerObject::getVertex() { return vertex; }
// 3 Vertices
int PlayerObject::getVertexCount() { return ARRAY_SIZE(vertex) / 3; }

// Returns the first element of the Color array
GLfloat* PlayerObject::getColor() { return color; }
// 4 Colors RGBA
int PlayerObject::getColorCount() { return ARRAY_SIZE(color) / 4; }

// Returns the first element of the UV array
GLfloat* PlayerObject::getUV() { return uv; }
// 3 Colors RGB
int PlayerObject::getUVCount() { return ARRAY_SIZE(uv); }

// Returns the first element of the Index array
GLfloat* PlayerObject::getIndex() { return index; }
// 3 Colors RGB
int PlayerObject::getIndexCount() { return ARRAY_SIZE(index) / 3; }
