#pragma once

#include "app.h"
#include "BrickGrid.h"
#include "SaveAndLoad.h"

class Init : public App
{
private:
	BrickGrid brickGrid;
public:
	Init();
	virtual ~Init();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Init &inst();
	SaveAndLoad save;

	sf::Sprite *m_backgroundSprite;
};
