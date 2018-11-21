#pragma once
#include <string>
#include "Component.h"

class Block : public Component
{
	std::string test;

public:
	void Spawn() override {}
	void Update() override {}
	void Destroy() override {}
	Block();
	std::string GetName();
};
