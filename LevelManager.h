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

public:
	std::vector<std::string> m_level_names;
	int m_current_level_index;

	/*
	 * Static method that returns instance of the created LevelManager
	 */
	static LevelManager* GetInstance()
	{
		return m_p_instance;
	}
	LevelManager();

	/*
	 * Loads a level by a name, uses m_level_names to find
	 * file path
	 */
	static void LoadLevelByName(std::string level_name);

	/*
	 * Starts rendering provided level and removes the previous one.
	 */
	static void LoadLevel(Level level);

	/*
	 * Finds a level that is loaded by ID
	 */
	static Level* GetLevelByID(ID levelID);

	/*
	 * Finds a level that is loaded by name
	 */
	static Level* GetLevelByName(std::string levelName);

	/*
	 * Changes everything to how it was when level
	 * was first loaded.
	 */
	static void RestartLevel();

	/*
	 * Switches to next level on the level directory list.
	 */
	static void NextLevel();
};

#endif