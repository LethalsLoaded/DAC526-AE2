#ifndef NON_PLAYABLE_CHARACTER_H
#define NON_PLAYABLE_CHARACTER_H



#include "Entity.h"
#include "GameObject.h"

class NonPlayableCharacter : public Component, public Entity
{
private:
	std::vector<Vector2> m_node_locations;
	int m_current_point = 0;
	bool m_is_running = false;


public:
	void Spawn() override;
	void Update() override;
	void Destroy() override;
protected:
	void ExecuteAction(Action action) override {}
};

#endif