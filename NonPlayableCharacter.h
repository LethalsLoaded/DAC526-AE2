#ifndef NON_PLAYABLE_CHARACTER_H
#define NON_PLAYABLE_CHARACTER_H



#include "Entity.h"
#include "GameObject.h"

class NonPlayableCharacter : public Component, public Entity
{
private:
	int m_current_point = 0;
	bool m_is_running = false;
	bool is_complete = true;
	Vector2 old_position;
	float distance;
	Vector2 target_position;
	float local_speed;


public:
	std::vector<Vector2> m_node_locations;

	void Spawn() override;
	void Update() override;
	void Destroy() override;
	/*
	 * This method populated the `distance` variable by applying
	 * pythag theorem between two points.
	 * 
	 * This method also populates `old_position` so that the
	 * distance is always calculated between correct positions.
	 * 
	 * This method only runs when nodes are changing.
	 */
	void CalculateNewMovement();

	/*
	 * Applies linear interpolation to move the object by `n`
	 */
	void Move(float n);
protected:
	void ExecuteAction(Action action) override {}
};

#endif