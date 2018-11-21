#pragma once

class Component
{
private:
	
public:
	virtual void Spawn() = 0 {}
	virtual void Update() = 0 {}
	virtual void Destroy() = 0 {}
};