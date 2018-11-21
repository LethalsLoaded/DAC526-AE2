#include "Block.h"

Block::Block()
{
	this->test = "New Block";
}

std::string Block::GetName()
{
	return this->test;
}
