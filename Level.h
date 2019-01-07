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
	int enemy_count;

public:
	bool M_is_active;
	/*
	 * Itterates through the file related to level and creates all the game
	 * objects that the level needs.
	 * 
	 * Creates some data for NPC too as a temporary solution to node type
	 * waypoints.
	 */
	Level(std::string path_to_level_data);
	~Level();
	
	std::vector<GameObject*> GetGameObjects() const;

	/*
	 * Gets all components with the SpriteRenderer and renders their
	 * sprites in a specified order.
	 */
	void Render();

	void AddGameObjectToLevel(GameObject* gameObject)
	{
		m_p_game_objects.push_back(gameObject);
	}
	std::string GetLevelName() const
	{
		return m_level_name;
	}

	std::string GetLevelPath() const
	{
		return m_level_path;
	}
};

#endif