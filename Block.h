#pragma once
#include <string>
#include "Component.h"

class Block : public Component
{
	std::string name;

public:
	Block();
	std::string GetName();
};
