#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <queue>
#include "Vector2.h"

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

enum ActionState
{
	IDLE,
	RUNNING
};
class Entity
{
	std::string m_display_name = "Anonymous Entity";
	float m_speed = 1.0f;

protected:
	std::queue<Action> m_action_queue;
	virtual void ExecuteAction(Action action) = 0 {}
};

#endif