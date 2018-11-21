#pragma once

#include <string>
#include <vector>
#include "Component.h"
#include "Vector2.h"
#include "Block.h"

class GameObject
{
	std::string m_name;
	std::vector<Component*> m_components;
	std::vector<void*> m_newComponents;

	// Level, NPC, Player
	Vector2* position;
public:
	GameObject(std::string name, Vector2* initialPosition);
	std::vector<Component*> GetComponents();
	template <class Q> Component* GetComponent()
	{
		//	if (typeid(Component) != typeid(Q)) return nullptr;

		//	Component* returnItem = nullptr;
		//	for (Component* i : m_components)
		//	{
		//		//if (typeid(*i) != typeid(Q))
		//		//	continue;
		//		//returnItem = static_cast<Component*>(i);
		//		//break;
		//	}
		//	return returnItem;


		/*Component* returnItem = nullptr;
		if (!std::is_base_of<Component, Q>::value)
			return returnItem;*/
/*
		for(Component* i : m_components)
		{
			if (typeid(*i->attachedComponent) != typeid(Q))
				continue;
			returnItem = i;
			break;
		}
*/
		if (!std::is_base_of<Component, Q>::value)
			return nullptr;
		Component* returnItem = nullptr;

		for(Component *p : m_components)
		{
			const std::type_info& tiQ = typeid(Q);
			const std::type_info& tiComponent = typeid(*p);

			std::string nameQ{ tiQ.name() };
			std::string nameComp{ tiComponent.name() };

			if (tiQ.name() != tiComponent.name())
				continue;
			returnItem = p;
		}

		return returnItem;
		
	}
	template <class Q> void AddComponent()
	{
		//Vector2* myVector = new Vector2(x, y);
		Q* newComponent = new Q;
		this->m_components.push_back(static_cast<Component*>(newComponent));
	}

	std::string GetName();
};
