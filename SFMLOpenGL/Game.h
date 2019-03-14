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
#include <PyramidObject.h>

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

	const int SCORE_GAIN{ 100 };
	const int NUM_OF_GAME_OBJECTS{ 200 };
	const int NUM_OF_PYRAMID_OBJECTS{ 45 };

	//Array of gameObject cubes.
	GameObject* m_gameObjects[200];

	//Array of playerObject cubes.
	PlayerObject* m_playerObject;

	//Array of endGoal cubes.
	EndGoal* m_endGoalObjects[3];

	//Array of pyramidObject pyramids.
	PyramidObject* m_pyramidObject[45];

	//Window to which the game draws to
	RenderWindow m_window;

	//Camera through which we see the world
	Camera m_camera;

	// Game font
	Font m_font;	

	//The current score that the player has.
	int m_score{ 0 };

	//The difficulty increase.
	float m_difficultyMultiplier{ 1.0f };

	//Checks if the game is running or not.
	bool m_isRunning{ false };

	void initialize();
	void update(sf::Time t_deltaTime);
	void render();
	void unload();

	void resetGameWin();
	void resetGameLose();

	void bindPlayerTexture();
	void bindObjectTexture();
	void bindPyramidTexture();
	void bindGoalTexture();
};

#endif  // ! GAME_H