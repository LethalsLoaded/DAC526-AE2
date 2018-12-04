#include "Player.h"
#include "InputHandler.h"
#include "Physics.h"
#include "Game.h"

void Player::Spawn()
{
	// Default controls
	m_player_controls[SDL_SCANCODE_W] = Action::MOVE_UP;
	m_p_game_object->AddComponent<Physics>();
}
bool isPressed = false;
void Player::Update()
{
	if(InputHandler::GetInstance()->IsKeyPressed(SDL_SCANCODE_W))
	{
		//m_p_game_object->GetComponent<Physics>()->m_velocity.Translate(Vector2(0, 5));
		
		auto phys = m_p_game_object->GetComponent<Physics>();
	}/*
	for(std::pair<SDL_Scancode, Action> i : m_player_controls)
	{
		if (InputHandler::GetInstance()->IsKeyPressed(i.first))
			ExecuteAction(i.second);
	}*/

	if(InputHandler::GetInstance()->IsKeyPressed(SDL_SCANCODE_SPACE) && isPressed == false)
	{
		isPressed = true;
		for(auto i : Game::GetInstance()->GetActiveLevel()->GetGameObjects())
		{
			//std::cout << i->M_name;
		}
	}
	//else isPressed = false;
}

void Player::Destroy()
{
}

void Player::ExecuteAction(Action action)
{
	switch(action)
	{
	case MOVE_UP:
		m_p_game_object->GetComponent<Physics>()->M_velocity->Translate(Vector2(0, 5));
		break;
	case MOVE_LEFT: break;
	case MOVE_DOWN: break;
	case MOVE_RIGHT: break;
	case INTERACT: break;
	case USE: break;
	case TOGGLE_PAUSE: break;
	}
}
