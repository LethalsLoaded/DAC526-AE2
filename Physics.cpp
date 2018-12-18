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

	if (m_p_game_object->GetComponent<Collider>()->IsColliding())
	{
		M_velocity = new Vector2(0, 0);
		m_p_game_object->M_position = m_p_game_object->GetComponent<Collider>()->M_last_safe_pos;
		return;
	}
	const float speed_reduction = 1.0f;
	const float speed_limit = 100.0f;

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
	}

void Physics::Destroy()
{
}
