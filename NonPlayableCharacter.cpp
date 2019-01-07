#include "NonPlayableCharacter.h"
#include <valarray>

void NonPlayableCharacter::Spawn()
{
}

void NonPlayableCharacter::Update()
{
	if (m_node_locations.empty()) return;
	
	if (is_complete)
	{
		is_complete = false;
		target_position = m_node_locations[m_current_point];
		m_current_point++;
		if (m_current_point > m_node_locations.size() - 1)
			m_current_point = 0;
		CalculateNewMovement();
	}

	local_speed += (0.1667 / m_speed);
	Move(local_speed);
}

void NonPlayableCharacter::Destroy()
{

}

void NonPlayableCharacter::CalculateNewMovement()
{
	old_position = *m_p_game_object->M_position;
	distance = std::sqrt(
		pow((old_position.m_x - target_position.m_x), 2) + pow((old_position.m_y - target_position.m_y), 2));
	local_speed = 1;
}

void NonPlayableCharacter::Move(float n)
{
	m_p_game_object->M_position = new Vector2(old_position.m_x + n / distance * (target_position.m_x - old_position.m_x),
		old_position.m_y + n / distance * (target_position.m_y - old_position.m_y));

	if (n > distance)
		is_complete = true;
}
