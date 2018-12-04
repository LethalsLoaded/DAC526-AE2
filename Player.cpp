#include "Player.h"
#include "InputHandler.h"

void Player::Spawn()
{
	// Default controls
	m_player_controls[SDL_SCANCODE_W] = Action::MOVE_UP;
}

void Player::Update()
{
	if(InputHandler::GetInstance()->IsKeyPressed(SDL_SCANCODE_W))
	{
		printf("hi");
	}
	for(std::pair<SDL_Scancode, Action> i : m_player_controls)
	{
		if (InputHandler::GetInstance()->IsKeyPressed(i.first))
			ExecuteAction(i.second);
	}
}

void Player::Destroy()
{
}
