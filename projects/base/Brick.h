#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "kage2dutil/gameobject.h"

class Brick : public kage::GameObject
{
public:
	Brick();
	~Brick();
	int brickID;
};