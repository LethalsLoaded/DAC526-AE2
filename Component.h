#ifndef COMPONENT_H
#define COMPONENT_H
#include "ID.h"

class GameObject;

class Component
{
protected:
	GameObject* m_p_game_object = nullptr;
public:
	virtual ~Component() = 0 {};
	virtual void Spawn() = 0 {}
	virtual void Update() = 0 {}
	virtual void Destroy() = 0 {}

	void SetObject(GameObject* game_object)
	{
		m_p_game_object = game_object;
	}

	
	
	bool isActive = true;
	ID M_id;
};
#endif
