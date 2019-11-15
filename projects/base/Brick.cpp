#include "Brick.h"
#include "kage2dutil/texture_manager.h"

Brick::Brick()
{
	brickID = 0;
	m_sprite = kage::TextureManager::getSprite("Sprites/TransparentBrickBlock.png");
}


Brick::~Brick()
{
}
