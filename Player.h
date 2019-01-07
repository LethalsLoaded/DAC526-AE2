#ifndef PLAYER_H
#define PLAYER_H
#include "Component.h"
#include "Entity.h"
#include <unordered_map>
#include <SDL.h>

class Player : public Component, public Entity
{
private:
	/*
	 * Attaches a key to an action which in future can be modular
	 * so that they can be changed.
	 */
	std::unordered_map<SDL_Scancode, Action> m_player_controls;
public:
	void Spawn() override;
	void Update() override;
	void Destroy() override;
protected:
	/*
	 * This method is used to create responsive  controls (WASD)
	 */
	void ExecuteAction(Action action) override;
};

#endif