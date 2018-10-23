#include "Block.h"

Block::Block()
{
	this->name = "New Block";
}

std::string Block::GetName()
{
	return this->name;
}
