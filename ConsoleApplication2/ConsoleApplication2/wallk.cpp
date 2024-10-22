#include "wallk.h"
//aquest es full ai, no sabia per on començar

wallk::wallk(const sf::Vector2f& startPosition, const sf::Vector2f& endPosition, float speed)
    : mStartPosition(startPosition), mEndPosition(endPosition), mSpeed(speed), mMovementProgress(0.0f) {
    
    eTexture.loadFromFile("graphics/paragoomba.png");
    eSprite.setTexture(eTexture);
    eSprite.setScale(0.4, 0.4);
    eSprite.setPosition(mStartPosition);

    /*
    mshape(rectangle transparent) és la hitbox, tant el rectangle com l'sprite van tenen la mateixa velocitat
    i comencen al mateix lloc, la diferència és que l'sprite no té col·lisió, però el rectangle si.
    */
    mShape.setSize(sf::Vector2f(70.f, 70.f)); //mida hitbox
    mShape.setPosition(mStartPosition);
    mShape.setFillColor(sf::Color::Transparent); //color hitbox
    mShape.setOutlineColor(Color::Transparent); //outline de la hitbox (per saber la mida)
    mShape.setOutlineThickness(5.f);
    mCurrentDirection = (endPosition - startPosition);
    mCurrentDirection /= std::sqrt(mCurrentDirection.x * mCurrentDirection.x + mCurrentDirection.y * mCurrentDirection.y); // Normalize direction
}

void wallk::update(float deltaTime) {
    mMovementProgress += (mSpeed/2) * deltaTime; //Update progress based on speed

    // Check if we've reached the end position
    if (mMovementProgress >= 1.0f) {
        std::swap(mStartPosition, mEndPosition); // Swap start and end positions
        mMovementProgress = 0.0f; // Reset progress
        mCurrentDirection = (mEndPosition - mStartPosition);
        mCurrentDirection /= std::sqrt(mCurrentDirection.x * mCurrentDirection.x + mCurrentDirection.y * mCurrentDirection.y); // Normalize direction
    }

     //Calculate new position of the platform

    float distance = std::sqrt(std::pow(mEndPosition.x - mStartPosition.x, 2) +
        std::pow(mEndPosition.y - mStartPosition.y, 2));

    // Calculate the new position
    sf::Vector2f newPosition = mStartPosition + mCurrentDirection * (mMovementProgress * distance);

    // Set the position of the shape
    eSprite.setPosition(newPosition);
    mShape.setPosition(newPosition);
}

void wallk::render(sf::RenderWindow& window) {
    window.draw(eSprite);
    window.draw(mShape);
}

const sf::RectangleShape& wallk::getShape() const {
    return mShape;
}