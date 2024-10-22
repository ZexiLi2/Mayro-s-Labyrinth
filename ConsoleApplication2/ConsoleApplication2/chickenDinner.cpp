#include "chickenDinner.h"
using namespace sf;
using namespace std;

chickenDinner::chickenDinner()
{
    //textura del trofeu, �s l'estrella de mario
    gTexture.loadFromFile("graphics/star.png");
    gSprite.setTexture(gTexture);
    gSprite.setScale(0.5, 0.5); //mida
    gSprite.setPosition(1100.f, 650.f); //posici�

}

void chickenDinner::render(sf::RenderWindow& window) {
    window.draw(gSprite);
}
sf::Vector2f chickenDinner::getPosition() const {
    return gSprite.getPosition();
}

//get star = win
const sf::Sprite& chickenDinner::getSprite() const {
    return gSprite;
}