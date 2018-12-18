#include "Player.h"
#include "InputHandler.h"
#include "Physics.h"
#include "Game.h"
#include "Collider.h"

void Player::Spawn()
{
	// Default controls
	m_player_controls[SDL_SCANCODE_W] = MOVE_UP;
	m_player_controls[SDL_SCANCODE_SPACE] = INTERACT;
	m_player_controls[SDL_SCANCODE_D] = MOVE_RIGHT;
	m_player_controls[SDL_SCANCODE_A] = MOVE_LEFT;
	m_player_controls[SDL_SCANCODE_S] = MOVE_DOWN;

	m_p_game_object->AddComponent<Physics>();
}

bool isPressed = false;

void Player::Update()
{
	//if(InputHandler::GetInstance()->IsKeyPressed(SDL_SCANCODE_W))
	//{
	//	//m_p_game_object->GetComponent<Physics>()->m_velocity.Translate(Vector2(0, 5));
	//	
	//	auto phys = m_p_game_object->GetComponent<Physics>();
	//}
	for (std::pair<SDL_Scancode, Action> i : m_player_controls)
	{
		if (InputHandler::GetInstance()->IsKeyPressed(i.first))
			ExecuteAction(i.second);
	}


	//else isPressed = false;
}

void Player::Destroy()
{
}

void Player::ExecuteAction(Action action)
{
	auto physics = m_p_game_object->GetComponent<Physics>();

	switch (action)
	{
	case MOVE_LEFT:
		physics->M_velocity->Translate(Vector2(-5, 0));
		break;
	case MOVE_RIGHT:
		physics->M_velocity->Translate(Vector2(5, 0));
		break;
	case MOVE_DOWN:
		physics->M_velocity->Translate(Vector2(0, 5));
		break;
	case MOVE_UP:
		physics->M_velocity->Translate(Vector2(0, -5));
		break;
	case INTERACT:
		if (isPressed) break;
		isPressed = true;
		for (auto i : Game::GetInstance()->GetActiveLevel()->GetGameObjects())
		{
			printf("T: %s\n", i->M_name.c_str());
		}
		break;
	case USE: break;
	case TOGGLE_PAUSE: break;
	}
}
