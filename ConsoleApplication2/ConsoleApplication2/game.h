#pragma once
/*#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
class Game
{
public: 
	Game();
	void run();
private:	//metodes
	void processEvents();
	void update(Time deltaTime);
	void render();
	void handlePlayerInput(Keyboard::Key key, bool isPressed);

private:	//atributs
	RenderWindow mWindow;
	CircleShape mPlayer;
	CircleShape mGoal;
	RectangleShape mBrick;
	Texture Tmayro;
	Sprite Smayro;
	Texture Tbg;
	Sprite Sbg;
		bool mIsMovingUp;
		bool mIsMovingDown;
		bool mIsMovingLeft;
		bool mIsMovingRight;
		//float PlayerSpeed=100.0f;
		const float PlayerSpeed = 150.f;
		const Time TimePerFrame = seconds(1.f / 60.f);
};*/

#include "player.h" 
#include "Tilemap.h"
#include "wall.h"
#include "wallk.h"
#include "chickenDinner.h"

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update(Time deltaTime);
	void render();

	RenderWindow mWindow;
	player mPlayer; 
	Sprite Sbg; 
	tilemap mTilemap;
	chickenDinner mGoal;
	wall mWalls;
	wallk mWallk;
	
	//get star = win
	bool hasWon = false;
	Font fontText;
	Text winText;

	void respawnPlayer();
};




