#include "BrickGrid.h"
#include <SFML/Graphics.hpp>

BrickGrid::BrickGrid(sf::RenderWindow& window) : window(window)
{

}

BrickGrid::~BrickGrid()
{

}

void BrickGrid::Start()
{
	for (size_t y = 0; y < CELLS_HEIGHT_COUNT; y++) // For loop to add GameObjects with Transparent Sprites
	{
		for (size_t x = 0; x < CELLS_WIDTH_COUNT; x++)
		{
			bricks[x+y * CELLS_WIDTH_COUNT] = kage::World::build<Brick>();
			bricks[x + y * CELLS_WIDTH_COUNT]->m_position = sf::Vector2i(x * CELL_SIZE_WIDTH, y * CELL_SIZE_HEIGHT);
		}
	}
}

void BrickGrid::Update()
{
	mousePosScreen = sf::Mouse::getPosition(window);

	for (size_t i = 0; i < 13; i++) // For loop to add Grids
	{
		horizontalL[i] = sf::RectangleShape(sf::Vector2f(SCREEN_RESOLUTION_HEIGHT, 1.f));
		horizontalL[i].setPosition(sf::Vector2f(0, CELL_SIZE_HEIGHT * i));
	}

	for (size_t i = 0; i < 10; i++)
	{
		verticalL[i] = sf::RectangleShape(sf::Vector2f(SCREEN_RESOLUTION_HEIGHT, 1.f));
		verticalL[i].setPosition(sf::Vector2f(CELL_SIZE_WIDTH * i, 0));
		verticalL[i].rotate(CELL_ROTATION);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Mouse functions here, render sprites when mouse left click on position of screen
	{
		if (mousePosScreen.x >= 0 && mousePosScreen.y >= 0 && mousePosScreen.x <= CELLS_WIDTH_COUNT* CELL_SIZE_WIDTH && mousePosScreen.y <= CELLS_HEIGHT_COUNT* CELL_SIZE_HEIGHT)
		{
			currentGrid = sf::Vector2i(mousePosScreen.x / CELL_SIZE_WIDTH, mousePosScreen.y  / CELL_SIZE_HEIGHT);
			bricks[currentGrid.x + currentGrid.y * CELLS_WIDTH_COUNT]->m_sprite->setTexture
			(*kage::TextureManager::getTexture("Sprites/BrickBlock.png"));
			bricks[currentGrid.x + currentGrid.y * CELLS_WIDTH_COUNT]->brickID = 1;
		}
	}
}

void BrickGrid::Draw()
{
	for (size_t i = 0; i < 13; i++) //Draw the Grids onto the screen
	{
		window.draw(horizontalL[i]);
	}

	for (size_t i = 0; i < 10; i++)
	{
		window.draw(verticalL[i]);
	}
}