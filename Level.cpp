#include "Level.h"

std::vector<GameObject*> Level::GetGameObjects() const
{
	return m_p_game_objects;
}

void Level::Render()
{
	for(auto gameObject : m_p_game_objects)
	{
		for(auto component : gameObject->GetComponents())
		{
			component->Update();
		}
	}
}
