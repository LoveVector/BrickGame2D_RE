#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "kage2dutil/gameobject.h"
#include "kage2dutil/world.h"
#include "kage2dutil/texture_manager.h"
#include "Brick.h"
#define CELLS_WIDTH_COUNT 9
#define CELLS_HEIGHT_COUNT 7
#define BRICKS_ARRAY_SIZE 9*7
#define SCREEN_RESOLUTION_WIDTH 1920.0f
#define SCREEN_RESOLUTION_HEIGHT 1080.0f
#define CELL_SIZE_WIDTH 220
#define CELL_SIZE_HEIGHT 88
#define CELL_ROTATION 90.0f

class BrickGrid
{
public:
	sf::RectangleShape horizontalL[13];
	sf::RectangleShape verticalL[10];
	sf::Vector2i mousePosScreen;
	sf::Vector2i currentGrid;
	Brick* bricks[BRICKS_ARRAY_SIZE];

	sf::RenderWindow& window;

	BrickGrid(sf::RenderWindow& window);
	~BrickGrid();

	void Start();
	void Update();
	void Draw();
};