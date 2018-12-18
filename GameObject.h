#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "Vector2.h"
#include "ID.h"

#include "Component.h"

class Sprite;
enum Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};
class GameObject
{
protected:
	std::vector<Component*> m_components;
	Direction m_direction = NORTH;
public:
	ID M_id;
	std::string M_name;
	Vector2*	M_position;
	int M_render_order = 1;
	GameObject(std::string name, Vector2* initial_position, Sprite* sprite = nullptr);
	~GameObject();
	std::vector<Component*> GetComponents();

	Direction GetDirection() const
	{
		return m_direction;
	}
	void SetDirection(Direction direction)
	{
		m_direction = direction;
	}

	template <class Q> Q* GetComponent()
	{
		// Checking if object is derived from Component
		if (!std::is_base_of<Component, Q>::value)
		{
			printf("You tried to access an object which is not a component.");
			return nullptr;
		}

		// Looking for the component
		for (auto *p : m_components)
		{
			const auto& type_info_q = typeid(Q);
			const auto& type_info_component = typeid(*p);

			if (type_info_q.name() != type_info_component.name())
				continue;
			return dynamic_cast<Q*>(p);
		}

		// If it gets this far we haven't found the component
		printf("You tried to access a component which the GameObject does not contain.");
		return nullptr;
	}

	template <class Q> static bool GameObjectHasComponent(GameObject* game_object)
	{
		// Looking for the component
		for (auto *p : game_object->m_components)
		{
			const auto& type_info_q = typeid(Q);
			const auto& type_info_component = typeid(*p);

			if (type_info_q.name() != type_info_component.name())
				continue;
			return true;
		}
		return false;
	}

	template <class Q> Q* AddComponent()
	{
		//Vector2* myVector = new Vector2(x, y);
		Q* new_component = new Q;
		Component* p_new_component_cast = static_cast<Component*>(new_component);
		this->m_components.push_back(p_new_component_cast);
		p_new_component_cast->SetObject(this);
		p_new_component_cast->Spawn();
		return new_component;
	}

	template <class Q> void DeleteComponent()
	{
		for(int i = 0; i < m_components.size(); i++)
		{
			const std::type_info& tiQ = typeid(Q);
			const std::type_info& tiComponent = typeid(*m_components[i]);
			if (tiQ.name() != tiComponent.name()) continue;
			m_components.erase(i);
			delete(m_components[i]);
			break;
		}
	}

	template <class Q> static std::vector<GameObject*> GetGameObjectsWithComponent()
	{
		std::vector<GameObject*> return_vector;
		if (!std::is_base_of<Component, Q>::value)
		{
			printf("You tried to access an object which is not a component.");
			return return_vector;
		}
		const std::type_info& ti_target = typeid(Q);
		for(auto game_object : Game::GetInstance()->GetActiveLevel()->GetGameObjects())
		{
			for(auto component : game_object->GetComponents())
			{
				const std::type_info& ti_component = typeid(*component);
				if(ti_target.name() != ti_component.name()) continue;
				return_vector.push_back(game_object);
			}
		}

		return return_vector;
	}

	static GameObject* FindWithName(std::string name);
	static GameObject* FindWithID(ID id);

};

struct CallMeSomething
{
	bool operator()(GameObject *ob1, GameObject *ob2) const
	{
		return ob1->M_render_order < ob2->M_render_order;
	}

};


#endif
