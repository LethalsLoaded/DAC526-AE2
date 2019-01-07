#include "Physics.h"
#include "Game.h"
#include <algorithm>
#include "Collider.h"
#include "Player.h"

void Physics::Spawn()
{
}

void Physics::Update()
{

	//printf("Velocity : (%f , %f) | DIR: %s\n", M_velocity->m_x, M_velocity->m_y, std::to_string(m_p_game_object->GetDirection()).c_str());

	//if (M_velocity->m_x > 0) m_p_game_object->SetDirection(EAST);
	//else m_p_game_object->SetDirection(WEST);

	//if (M_velocity->m_y > 0) m_p_game_object->SetDirection(SOUTH);
	//else m_p_game_object->SetDirection(NORTH);
	
	if (m_p_game_object->GetComponent<Collider>()->IsColliding() && M_collisionFixed)
	{
		auto collider_game_object = m_p_game_object->GetComponent<Collider>()->IsCollidingCollider();
		if (!collider_game_object->GetComponent<Collider>()->M_isTrigger)
		{
			M_velocity->m_y;
			M_velocity = new Vector2(M_velocity->m_x * -1, M_velocity->m_y * -1);
			printf("NEW VELOCITY: ( %f , %f )\n", M_velocity->m_x, M_velocity->m_y);
			M_collisionFixed = false;
		}
		else if (!M_isInTrigger)
		{
			printf("hi im %s )\n", collider_game_object->M_name.c_str());
			if (collider_game_object->M_name == "Target")
			{
				LevelManager::NextLevel();
				return;
			}
			if (collider_game_object->M_name == "Enemy")
			{
				LevelManager::RestartLevel();
				return;
			}
		}
	}

	const auto speed_reduction = 1.0f;
	const auto speed_limit = 100.0f;

	if (M_velocity->m_x > 0) M_velocity->Translate(Vector2(-speed_reduction, 0));
	if (M_velocity->m_x < 0) M_velocity->Translate(Vector2(speed_reduction, 0));
	if (M_velocity->m_y > 0) M_velocity->Translate(Vector2(0, -speed_reduction));
	if (M_velocity->m_y < 0) M_velocity->Translate(Vector2(0, speed_reduction));

	M_velocity->m_x = std::max(-speed_limit, std::min(M_velocity->m_x, speed_limit));
	M_velocity->m_y = std::max(-speed_limit, std::min(M_velocity->m_y, speed_limit));

	m_p_game_object->M_position->Translate(
		Vector2(
			M_velocity->m_x / Game::FRAMES_PER_SECOND,
			M_velocity->m_y / Game::FRAMES_PER_SECOND
		));

	m_p_game_object->GetComponent<Collider>()->M_last_safe_pos = m_p_game_object->M_position;

	if (!m_p_game_object->GetComponent<Collider>()->IsColliding())
	{
		M_collisionFixed = true;
		M_isInTrigger = false;
	}
	// colliding already so M_collisionfixed is never set to true because im still colliding
	}

void Physics::Destroy()
{
}
