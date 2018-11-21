#pragma once
#include <string>
#include "Component.h"

class Block : public Component
{
	std::string test;

public:
	Block();
	std::string GetName();
};
