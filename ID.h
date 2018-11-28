#ifndef ID_H
#define ID_H

#include "Component.h"
#include "GameObject.h"

class ID
{
private:
	unsigned long long m_id = 0;
public:
	ID();
	~ID();
	unsigned long long GetID();
	static unsigned long long GenerateID();
};

#endif