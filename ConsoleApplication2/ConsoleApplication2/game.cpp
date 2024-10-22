#include "game.h"
using namespace sf;
using namespace std;

const Time TimePerFrame = seconds(1.f / 60.f);

Game::Game()
	: mWindow(VideoMode(1280, 896), "SFML Application")
	, mPlayer(),Sbg(), mGoal(), mWallk(sf::Vector2f(200.f, 400.f), sf::Vector2f(800.f, 400.f), 0.5f)
{
	//aixó és el tilemap
	const int level[] = {
		2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 
		3, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 3, 2, 2, 2, 2, 3,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
		2, 2, 3, 2, 2, 2, 3, 2, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 3,
		2, 2, 2, 3, 2, 2, 2, 2, 0, 0
	
	};

	//carregar el tileset
	if (!mTilemap.load("graphics/tileset.png", sf::Vector2u(128, 128), level, 10, 7))
		throw std::runtime_error("Failed to load tilemap");

	//font
	fontText.loadFromFile("fonts/Crang.ttf");
	winText.setFont(fontText);
	//text de victoria, mida, color i posició
	winText.setString("You Win!");
	winText.setCharacterSize(150);
	winText.setFillColor(sf::Color::Black);
	winText.setPosition(150.f, 50.f);

	//aquí es creen les parets
	mWalls.addWall(Vector2f(0.f, 275.f), Vector2f(1000.f, 20.f));  //horizontal wall
	mWalls.addWall(Vector2f(300.f, 550.f), Vector2f(1000.f, 20.f));  //horizontal wall
	mWalls.addWall(Vector2f(500.f, 500.f), Vector2f(20.f, 290.f));  //vertical wall
	mWalls.addWall(Vector2f(500.f, 275.f), Vector2f(20.f, 85.f));  //vertical wall

}


void Game::run()
{
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		Time deltaTime = clock.restart();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		update(deltaTime);
		render();
	}
}

//void Game::processEvents()	
//{
//	//Event event;
//	//while (mWindow.pollEvent(event))
//	//{
//	//	/*if (event.type == Event::Closed)
//	//		mWindow.close();*/
//	//	switch (event.type)
//	//	{
//	//	case Event::KeyPressed:
//	//		handlePlayerInput(event.key.code, true);
//	//		break;
//	//	case Event::KeyReleased:
//	//		handlePlayerInput(event.key.code, false);
//	//		break;
//	//	case Event::Closed:
//	//		mWindow.close();
//	//		break;
//	//	}
//	//}
//}
//
//void Game::handlePlayerInput(Keyboard::Key key, bool isPressed)
//{
//	if (key == Keyboard::Up|| key == Keyboard::W)
//		mIsMovingUp = isPressed;
//	else if (key == Keyboard::Down || key==Keyboard::S)
//		mIsMovingDown = isPressed;
//	else if (key == Keyboard::A)
//		mIsMovingLeft = isPressed;
//	else if (key == Keyboard::D)
//		mIsMovingRight = isPressed;
//
//}
//


//mostrar les entitats: personatge, parets, enemic (és una paret en moviment amb sprite), estrella, tilemap 
void Game::render()
{
	mWindow.clear();
	mWindow.draw(Sbg);
	//mTilemap.draw(mWindow);
	mWindow.draw(mTilemap);
	mGoal.render(mWindow);
	mPlayer.render(mWindow);
	mWalls.render(mWindow);
	mWallk.render(mWindow);
	if (hasWon) {
		mWindow.draw(winText);
	}
	//mWindow.draw(mBrick);
	//mWindow.draw(mGoal);
	//mWindow.draw(Smayro);

	mWindow.display();
	
}

void Game::update(Time deltaTime)
{
	mPlayer.update(deltaTime.asSeconds());

	if (mPlayer.checkCollision(mGoal)) {
		hasWon = true;  //si jugador toca l'estralla, guanya
	}

	if (mWalls.checkCollision(mPlayer.getSprite())) {
		respawnPlayer();  //reviure jugador si toquen la paret
	}

	mWallk.update(deltaTime.asSeconds());

	// Check if the player is standing on the moving platform
	if (mWallk.getShape().getGlobalBounds().intersects(mPlayer.getSprite().getGlobalBounds())) {
		// Move the player along with the platform
		mPlayer.setPosition(mPlayer.getPosition().x + mWallk.getShape().getPosition().x - mWallk.getShape().getSize().x / 2, mPlayer.getPosition().y);
	}



}

void Game::respawnPlayer() {
	mPlayer.setPosition(100.f, 100.f);  //reviure jugador, reviuen a 100, 100
}

//void initShape(RectangleShape& shape, Vector2f const& pos, Color const& color)
//{
//	shape.setFillColor(Color::Red);
//	shape.setPosition(pos);
//	shape.setOrigin(shape.getSize() * .5f);
//}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();

			//Handle player input només si encara no ha guanyat, si guanya deixa de funcionar
		if (!hasWon) {
			if (event.type == sf::Event::KeyPressed)
				mPlayer.handleInput(event.key.code, true);
			else if (event.type == sf::Event::KeyReleased)
				mPlayer.handleInput(event.key.code, false);
		}
    }
}

