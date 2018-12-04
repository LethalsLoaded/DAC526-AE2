#ifndef NON_PLAYABLE_CHARACTER_H
#define NON_PLAYABLE_CHARACTER_H



#include "Entity.h"
#include "GameObject.h"

class NonPlayableCharacter : public Component, public Entity
{
private:
	Vector2 m_target_location;
	GameObject m_target_entity, m_threat_entity, m_target_perk;

public:
	void Spawn() override;
	void Update() override;
	void Destroy() override;
protected:
	void ExecuteAction(Action action) override {}
};

#endif