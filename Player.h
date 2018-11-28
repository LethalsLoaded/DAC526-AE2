#ifndef PLAYER_H
#define PLAYER_H
#include "Component.h"
#include "Entity.h"
#include <unordered_map>

class Player : public Component, public Entity
{
private:
	// CHANGE TO SDL_KEYCODE FROM INT
	std::unordered_map<int, Action> m_player_controls;
public:
	void Spawn() override;
	void Update() override;
	void Destroy() override;
};

#endif