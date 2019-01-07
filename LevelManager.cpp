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
	m_current_level_index = 0;
	LoadLevelByName(m_level_names[m_current_level_index]);
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
	if (Game::GetInstance()->GetActiveLevel() != nullptr) delete(Game::GetInstance()->GetActiveLevel());
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

void LevelManager::RestartLevel()
{
	Level* active_level = Game::GetInstance()->GetActiveLevel();
	std::string name = active_level->GetLevelName();
	delete(active_level);
	auto new_level = new Level(name);
	Game::GetInstance()->SetActiveLevel(new_level);
	new_level->M_is_active = true;
}

void LevelManager::NextLevel()
{
	GetInstance()->m_current_level_index++;
	LoadLevelByName(GetInstance()->m_level_names[GetInstance()->m_current_level_index]);
}
