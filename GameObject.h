#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "Vector2.h"
#include "ID.h"


class GameObject
{
protected:
	std::vector<Component*> m_components;
	
public:
	ID M_id;
	std::string M_name;
	Vector2*	M_position;
	GameObject(std::string name, Vector2* initialPosition);
	std::vector<Component*> GetComponents();
	template <class Q> Q* GetComponent()
	{
		if (!std::is_base_of<Component, Q>::value)
		{
			printf("You tried to access a component which the GameObject does not contain.");
			return nullptr;
		}

		for (Component *p : m_components)
		{
			const std::type_info& tiQ = typeid(Q);
			const std::type_info& tiComponent = typeid(*p);

			// Debug code to get the names of the classes
			std::string nameQ{ tiQ.name() };
			std::string nameComp{ tiComponent.name() };

			if (tiQ.name() != tiComponent.name())
				continue;
			return dynamic_cast<Q*>(p);
		}
		// If it gets this far we haven't found the component
		return nullptr;
	}

	template <class Q> Q* AddComponent()
	{
		//Vector2* myVector = new Vector2(x, y);
		Q* newComponent = new Q;
		this->m_components.push_back(static_cast<Component*>(newComponent));
		static_cast<Component*>(newComponent)->SetObject(this);
		return newComponent;
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
