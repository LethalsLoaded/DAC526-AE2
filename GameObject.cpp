#include "GameObject.h"
#include "Game.h"
#include "SpriteRenderer.h"



GameObject::GameObject(std::string name, Vector2 * initial_position, Sprite * sprite)
{
	M_name = name;
	M_position = initial_position;
	//Game::GetInstance()->GetActiveLevel()->AddGameObjectToLevel(this);

	// If we were given a sprite
	if (sprite == nullptr) return;
	auto sprite_renderer = AddComponent<SpriteRenderer>();
	sprite_renderer->ChangeSprite(sprite);
}

GameObject::~GameObject()
{
	for (auto component : m_components)
		delete(component);
	m_components.empty();

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


bool operator<(const GameObject &ob1, const GameObject &ob2)
{
	printf("SORTING");
	return ob1.M_render_order < ob2.M_render_order;
}





