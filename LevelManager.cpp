#include "LevelManager.h"
#include <fstream>
#include "Game.h"

//Game* Game::m_p_game_instance = nullptr;
LevelManager* LevelManager::m_p_instance = nullptr;
LevelManager::LevelManager()
{
	m_p_instance = this;
	std::ifstream inputStream("Assets/Levels/_Level_Directory.txt");

	std::string tempLine;
	while (std::getline(inputStream, tempLine))
	{
		if (!tempLine.empty())
			m_level_names.push_back(tempLine);
	}
	inputStream.close();

	LoadLevelByName(m_level_names[0]);
}

void LevelManager::LoadLevelByName(std::string level_name)
{
	bool found = false;
	for(auto i : GetInstance()->m_level_names)
	{
		if (i != level_name) continue;
		found = true;
		break;
	}

	if (!found) return;

	auto new_level_pointer = new Level(level_name);
	new_level_pointer->M_is_active = true;
	Game::GetInstance()->SetActiveLevel(new_level_pointer);
}

void LevelManager::LoadLevel(Level level)
{
}

Level * LevelManager::GetLevelByID(ID levelID)
{
	return nullptr;
}

Level * LevelManager::GetLevelByName(std::string levelName)
{
	return nullptr;
}
