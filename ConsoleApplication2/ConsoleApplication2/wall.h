#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class wall
{
public:
    wall();

    // Add a wall to the game
    void addWall(const sf::Vector2f& position, const sf::Vector2f& size);

    // Render all walls
    void render(sf::RenderWindow& window);

    // Check if the player collides with any wall
    bool checkCollision(const sf::Sprite& playerSprite) const;

private:
    std::vector<sf::RectangleShape> wallShapes;


};

