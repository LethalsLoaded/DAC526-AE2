#ifndef PHYSICS_H
#define PHYSICS_H
#include "Vector2.h"
#include "Component.h"
#include <cstdio>

class Physics : public Component
{
public:
	void Spawn() override;
	/*
	 * As of now, collision resolution is handled within physics.
	 * Update handles velocity of the player and in future will become
	 * more advanced with an algorithm that takes mass, drag etc into effect
	 */
	void Update() override;
	void Destroy() override;
private:
	float m_mass;
public:
	Physics() {}
	~Physics() {}
	Vector2* M_velocity = new Vector2();
	bool M_collisionFixed = true;
	bool M_isInTrigger = true;
};

#endif