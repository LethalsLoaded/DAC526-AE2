#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <string>
#include "ID.h"
#include "Level.h"

class LevelManager
{
private:
	static LevelManager* m_p_instance;
protected:
	std::vector<std::string> m_level_names;
public:
	static LevelManager* GetInstance()
	{
		return m_p_instance;
	}
	LevelManager();
	static void LoadLevelByName(std::string level_name);
	static void LoadLevel(Level level);
	static Level* GetLevelByID(ID levelID);
	static Level* GetLevelByName(std::string levelName);
};

#endif