#ifndef LEVEL_H
#define LEVEL_H
#include "ID.h"
#include <string>
#include <vector>
#include "GameObject.h"


class Level
{
protected:
	ID m_id;
	std::string m_level_name;
	std::vector<GameObject*> m_p_game_objects;
	int m_game_time_elapsed, m_game_time_max;
	std::string m_level_path;
	std::vector<std::string> m_level_design;

public:
	bool M_is_active;
	Level(std::string path_to_level_data);
	std::vector<GameObject*> GetGameObjects() const;
	void Render();
	void AddGameObjectToLevel(GameObject* gameObject)
	{
		m_p_game_objects.push_back(gameObject);
	}
};

#endif