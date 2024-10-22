#include "player.h"

using namespace sf;
using namespace std;

const float player::PlayerSpeed = 150.f; 

player::player()
{
    //carregar sprite de personatge
    mTexture.loadFromFile("graphics/justhead.png");
    mSprite.setTexture(mTexture);
    mSprite.setScale(0.5, 0.5);
    mSprite.setPosition(100.f, 100.f);
}

//player controller WASD o fletxes per moure
void player::handleInput(Keyboard::Key key, bool isPressed) {
    if (key == Keyboard::Up || key == Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == Keyboard::Down || key == Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == Keyboard::Left || key == Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == Keyboard::Right || key == Keyboard::D)
        mIsMovingRight = isPressed;

    //l'he tret d'aquí: https://stackoverflow.com/questions/67828725/problem-detecing-window-border-collision-in-sfml 
    //left border
    if (mSprite.getPosition().x < 0){   //si la posició del jugador és menor que 0 (fora de la pantalla esquerre)
        mSprite.setPosition(0, mSprite.getPosition().y);    //torna a 0
    }
    //top border 
    if (mSprite.getPosition().y < 0) {
        mSprite.setPosition(mSprite.getPosition().x, 0);
    };
    //right border 
    if (mSprite.getPosition().x > 1180) {
        mSprite.setPosition(1180, mSprite.getPosition().y);
    }
    //bottom border 
    
    if (mSprite.getPosition().y > 800) {
        mSprite.setPosition(mSprite.getPosition().x, 800);
    };

}

void player::update(float deltaTime) {
    Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= PlayerSpeed;
    if (mIsMovingDown)
        movement.y += PlayerSpeed;
    if (mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if (mIsMovingRight)
        movement.x += PlayerSpeed;

    mSprite.move(movement * deltaTime);

}

//dibuixar el personatge
void player::render(sf::RenderWindow& window) {
    window.draw(mSprite);
}

sf::Vector2f player::getPosition() const {
    return mSprite.getPosition();
}

//get star = win
bool player::checkCollision(const chickenDinner& trophy) const{
    return mSprite.getGlobalBounds().intersects(trophy.getSprite().getGlobalBounds());
}

const sf::Sprite& player::getSprite() const {
    return mSprite; // Returns the sprite for collision checking
}

void player::setPosition(float x, float y) {
    mSprite.setPosition(x, y); // Set the player's position
}