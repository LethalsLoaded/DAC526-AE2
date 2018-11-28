#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <string>
#include "ID.h"
#include "Level.h"

class LevelManager
{
public:
	static void LoadLevelByName(std::string levelName);
	static void LoadLevel(Level level);
	static Level* GetLevelByID(ID levelID);
	static Level* GetLevelByName(std::string levelName);
};

#endif