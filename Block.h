#pragma once
#include <string>
#include "Component.h"
#include "Entity.h"

class Block : public Component
{
	Entity m_entity;

public:
	bool M_isWall;
	bool M_isDestructable;
	bool M_isPushable;
	void Spawn() override {}
	void Update() override {}
	void Destroy() override {}

	Block();
	std::string GetName();
};
