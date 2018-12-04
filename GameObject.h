#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "Vector2.h"
#include "ID.h"

#include "Component.h"

class Sprite;

class GameObject
{
protected:
	std::vector<Component*> m_components;
	
public:
	ID M_id;
	std::string M_name;
	Vector2*	M_position;
	GameObject(std::string name, Vector2* initial_position, Sprite* sprite = nullptr);
	~GameObject();
	std::vector<Component*> GetComponents();
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

	static GameObject* FindWithName(std::string name);
	static GameObject* FindWithID(ID id);
};

#endif
