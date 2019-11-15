#include "example.h"


Init::Init(): App(), brickGrid(m_window)
{
}

Init::~Init()
{
}

Init &Init::inst()
{
	static Init s_instance;
	return s_instance;
}

bool Init::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	brickGrid.Start();
	return true;
}

void Init::update(float deltaT)
{
	brickGrid.Update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	if (ImGui::Button("Save"))
	{
		save.Save(brickGrid.bricks);
	}
	if (ImGui::Button("Load"))
	{
		save.Load(brickGrid.bricks);
	}
	ImGui::End();
}

void Init::render()
{
	m_window.draw(*m_backgroundSprite);
	brickGrid.Draw();
}

void Init::cleanup()
{
	delete m_backgroundSprite;
}

