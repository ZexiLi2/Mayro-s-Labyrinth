#include "wall.h"


wall::wall() {}

void wall::addWall(const sf::Vector2f& position, const sf::Vector2f& size) {
    sf::RectangleShape wall;

    //aqui es creen el setSize i setPosition, però es defineixen després a game.cpp
    wall.setSize(size);
    wall.setPosition(position);
    wall.setFillColor(sf::Color::Red);  //wall color 
    wallShapes.push_back(wall);
}

//mostrar per pantalla les parets
void wall::render(sf::RenderWindow& window) {
    for (const auto& wall : wallShapes) {
        window.draw(wall);
    }
}

bool wall::checkCollision(const sf::Sprite& playerSprite) const {
    for (const auto& wall : wallShapes) {
        if (playerSprite.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            return true;  // Collision detected
        }
    }
    return false;  // No collision
}
