#include "Physics.h"
#include "Game.h"
#include <iostream>

void Physics::Spawn()
{
}

void Physics::Update()
{
	m_p_game_object->M_position->Translate(
		Vector2(
			M_velocity->m_x / Game::FRAMES_PER_SECOND,
			M_velocity->m_y / Game::FRAMES_PER_SECOND
		));
}

void Physics::Destroy()
{
}
