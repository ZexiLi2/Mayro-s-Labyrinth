#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
class wallk
{
public:
    wallk(const Vector2f& startPosition, const Vector2f& endPosition, float speed);

    void update(float deltaTime);
    void render(RenderWindow& window);
    const RectangleShape& getShape() const;

private:
    RectangleShape mShape;

    //e = enemy
    Sprite eSprite;
    Texture eTexture;
    Vector2f mStartPosition;
    Vector2f mEndPosition;
    Vector2f mCurrentDirection;
    float mSpeed;
    float mMovementProgress; // A value from 0 to 1 representing the movement along the platform's path

};

