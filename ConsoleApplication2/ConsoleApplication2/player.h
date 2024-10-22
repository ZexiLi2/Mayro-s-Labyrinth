#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "chickenDinner.h"

using namespace sf;

class player {
public:
	player();
	void handleInput(Keyboard::Key key, bool isPressed);
	void update(float deltaTime);
	void render(RenderWindow& window);
	Vector2f getPosition() const;

	//get star = win
	bool checkCollision(const chickenDinner& trophy) const;


	void setPosition(float x, float y);
	const sf::Sprite& getSprite() const; 

private:
	Sprite mSprite;
	Texture mTexture;
	static const float PlayerSpeed;
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
};


