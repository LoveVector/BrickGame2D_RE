#pragma once
#include <Brick.h>
class SaveAndLoad
{
public:
	SaveAndLoad();
	~SaveAndLoad();
	int arrayTracker;
	void Save(Brick* brickArray[]); 
	void Load(Brick* brickArray[]);
};

