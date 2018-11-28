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
	std::string level_name;
	std::vector<GameObject*> m_p_game_objects;
	int m_game_time_elapsed, m_game_time_max;
public:
	Level()
	{
		// add to the game vector
	}
	std::vector<GameObject*> GetGameObjects() const;
	void Render();
	void AddGameObjectToLevel(GameObject* gameObject)
	{
		m_p_game_objects.push_back(gameObject);
	}
};

#endif