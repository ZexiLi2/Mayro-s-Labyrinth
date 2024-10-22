#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
//winner winner chicken dinner

class chickenDinner {

public:
	chickenDinner();
	void render(RenderWindow& window);
	Vector2f getPosition() const;

	//get star = win
	const Sprite& getSprite() const;

private:
	Sprite gSprite;
	Texture gTexture;
};

