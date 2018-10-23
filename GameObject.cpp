#include "GameObject.h"

GameObject::GameObject(std::string name, Vector2* initialPosition)
{
	this->m_name = name;
	this->position = initialPosition;
}

std::vector<Component*> GameObject::GetComponents()
{
	return this->m_components;
}

std::string GameObject::GetName()
{
	return this->m_name;
}







