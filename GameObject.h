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
	// Level, NPC, Player
	Vector2* position;
public:
	GameObject(std::string name, Vector2* initialPosition);
	std::vector<Component*> GetComponents();
	template <class Q> Component* GetComponent()
	{
		if (typeid(Component) == typeid(Q)) return nullptr;
		Q* returnItem = nullptr;
		for (auto i : m_components)
		{
			if (typeid(i) != typeid(Q))
				continue;
			returnItem = i;
			break;
		}
		return returnItem;
	}
	template <class Q> void AddComponent()
	{
		//Vector2* myVector = new Vector2(x, y);
		Q* newComponent = new Q();
		//this->m_components.push_back(dynamic_cast<Component>(newComponent));
	}

	std::string GetName();
};
