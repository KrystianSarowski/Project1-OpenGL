#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>

#include <iostream>
#include <gl/glew.h>
#include <GL/wglew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GameObject.h>
#include <PlayerObject.h>
#include <Camera.h>
#include <EndGoal.h>

using namespace std;
using namespace sf;
using namespace glm;

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
private:

	GameObject* game_object[200];
	PlayerObject* m_playerObject;
	EndGoal* m_endGoal[3];

	RenderWindow window;
	Clock clock;
	Time time;
	bool isRunning = false;

	Camera m_camera;
	void initialize();
	void update(sf::Time t_deltaTime);
	void render();
	void unload();

	void resetGameWin();

	const int SCORE_GAIN{ 100 };

	int m_numOfCubes{ 200 };
	int m_score{ 0 };

	float m_difficultyMultiplier{ 1.0f };
};

#endif  // ! GAME_H