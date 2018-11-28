#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(std::string name, Vector2* initialPosition)
{
	M_name = name;
	M_position = initialPosition;

	Game::GetInstance()->GetActiveLevel()->AddGameObjectToLevel(this);
}

std::vector<Component*> GameObject::GetComponents()
{
	return this->m_components;
}

GameObject * GameObject::FindWithName(std::string name)
{
	auto active_level = Game::GetInstance()->GetActiveLevel();
	GameObject* return_object = nullptr;
	for(auto i : active_level->GetGameObjects())
	{
		if (i->M_name != name)
			continue;
		return_object = i;
	}
	return return_object;
}

//GameObject * GameObject::FindWithID(ID* id)
//{
//	//auto active_level = Game::GetInstance()->GetActiveLevel();
//	//GameObject* return_object = nullptr;
//	//for (auto i : active_level->GetGameObjects())
//	//{
//	//	if (i->M_id.GetID() != id->GetID())
//	//		continue;
//	//	return_object = i;
//	//}
//	//return return_object;
//	return GameObject * ;
//}








