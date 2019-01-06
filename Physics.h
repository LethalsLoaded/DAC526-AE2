#ifndef PHYSICS_H
#define PHYSICS_H
#include "Vector2.h"
#include "Component.h"

class Physics : public Component
{
public:
	void Spawn() override;
	void Update() override;
	void Destroy() override;
private:
	float m_mass;
public:
	Vector2* M_velocity = new Vector2();
	bool M_collisionFixed = true;
	bool M_isInTrigger = true;
};

#endif