#include "ID.h"
#include <array>
#include <sstream>


ID::ID()
{
	
	m_id = GenerateID();
}

ID::~ID()
{
	m_id = NULL;
}

unsigned long long ID::GetID()
{
	if(m_id == 0) GenerateID();
	return m_id;
}

unsigned long long ID::GenerateID()
{
	std::stringstream ss;

	for (int i = 0; i < 15; i++) {
		auto ran = rand() % 10;
		ss << ran;
		printf("R[%d] num %d\n", i, ran);
	}
	
	unsigned long long result;
	ss >> result;
	return result;
}
