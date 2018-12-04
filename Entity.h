#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <queue>

enum Action
{
	MOVE_UP,
	MOVE_LEFT,
	MOVE_DOWN,
	MOVE_RIGHT,
	INTERACT,
	USE,
	TOGGLE_PAUSE,
	LAST_ACTION
};

enum Team
{
	RED,
	GREEN,
	BLUE,
	YELLOW
};

enum ActionState
{
	IDLE,
	RUNNING
};

enum Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};
class Entity
{
	std::string m_display_name;
	int m_lives_remaining;
	int m_bombs_available;
	// CHANGE TO PERK POINTER
	std::vector<std::string> m_p_perks;
	int m_placed_bombs;
	int m_destroyed_blocks;
	int m_collected_perks;
	int m_kills;
	Team m_team;
	Direction m_direction;
	int m_explosive_power;
	int m_kick_power;

protected:
	std::queue<Action> m_action_queue;
	void ExecuteAction(Action action);
};

#endif