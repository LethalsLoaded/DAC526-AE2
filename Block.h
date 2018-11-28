#pragma once
#include <string>
#include "Component.h"
#include "Entity.h"

class Block : public Component
{
	Entity m_entity;

public:
	void Spawn() override {}
	void Update() override {}
	void Destroy() override {}

	Block();
	std::string GetName();
};
