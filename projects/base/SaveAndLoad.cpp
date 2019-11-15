#include "SaveAndLoad.h"
#include <fstream>
#include <BrickGrid.h>

SaveAndLoad::SaveAndLoad()
{
	arrayTracker = 0;
}


SaveAndLoad::~SaveAndLoad()
{
}

void SaveAndLoad::Save(Brick* brickArray[])
{
	std::ofstream writeFile;
	writeFile.open("SaveFile.txt"); // Saving file into text file

	for (size_t y = 0; y < CELLS_HEIGHT_COUNT; y++)
	{
		for (size_t x = 0; x < CELLS_WIDTH_COUNT; x++)
		{
			writeFile << brickArray[arrayTracker]->brickID << ", ";
			arrayTracker++;
		}
		writeFile << std::endl;
	}
}

void SaveAndLoad::Load(Brick* brickArray[])
{
	std::string line;
	std::ifstream myfile("SaveFile.txt"); 
	if (myfile.is_open())
	{			
		int cellYCount = 0;

		while (getline(myfile, line))     // Load save file from text file
		{ 
			int x = 0;
			int cellXCount = 0;

			while (cellXCount < 9)
			{
				int j = line.find(',', x);
				std::string cut = line.substr(x, j - x);

				//remove white spaces
				std::string::iterator end_pos = std::remove(cut.begin(), cut.end(), ' ');
				cut.erase(end_pos, cut.end());

				if (cut == "1")
				{
					brickArray[cellXCount + cellYCount * 9]->m_sprite->setTexture
					(*kage::TextureManager::getTexture("Sprites/BrickBlock.png"));
				}

				x = j + 1;
				cellXCount++;
			}
			cellYCount++;
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
}
