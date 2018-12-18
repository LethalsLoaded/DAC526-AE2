#ifndef COLLIDER_H
#define COLLIDER_H
#include "Component.h"
#include "Physics.h"

struct Bounding_Box
{
	int width, height;
	int left, right, top, bottom;
	Vector2 top_left, top_right, bottom_left, bottom_right;
};

class Collider : public Component
{
private:
	Bounding_Box* m_p_bounding_box;
public:
	Vector2* M_last_safe_pos;

	Collider()
	{
		m_p_bounding_box = new Bounding_Box();
	}
	void SetBox(Bounding_Box* box)
	{
			m_p_bounding_box = box;
	}

	Bounding_Box* GetBox() const
	{
		return m_p_bounding_box;
	}
	bool CanMoveTop()
	{
		//// Check Top Left
		//auto ray_length_horizontal = m_p_bounding_box->height + 1;
		////auto ray_length_vertical = m_p_box->width + 1;
		//auto test = GameObject::GetGameObjectsWithComponent<Collider>();
		for(auto i : GameObject::GetGameObjectsWithComponent<Collider>())
		{
			if (i->M_id.GetID() == m_p_game_object->M_id.GetID()) continue;
			auto const component_box = i->GetComponent<Collider>()->m_p_bounding_box;
			if (CheckCollision(m_p_bounding_box, component_box))
				return true;
		}
		return false;
	}

	bool CanMove() const
	{
		for (auto i : GameObject::GetGameObjectsWithComponent<Collider>())
		{
			if (i->M_id.GetID() == m_p_game_object->M_id.GetID()) continue;
			//return CheckCollision(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			switch (m_p_game_object->GetDirection())
			{
			case NORTH:
				return CheckTop(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			case EAST: 
				return CheckRight(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			case SOUTH: 
				return CheckBottom(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			case WEST: 
				return CheckLeft(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			}
			
		}
		return true;

	}

	Collider* IsCollidingCollider() const
	{
		bool horizontal_value = false, vertical_value = false;
		Collider* return_value = nullptr;

		for (auto i : GameObject::GetGameObjectsWithComponent<Collider>())
		{
			if (i->M_id.GetID() == m_p_game_object->M_id.GetID()) continue;

			if (m_p_game_object->GetComponent<Physics>()->M_velocity->m_x > 0)
				horizontal_value = CheckRight(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			else
				horizontal_value = CheckLeft(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);

			if (m_p_game_object->GetComponent<Physics>()->M_velocity->m_y > 0)
				vertical_value = CheckTop(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			else
				vertical_value = CheckBottom(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);

			if (vertical_value || horizontal_value)
			{
				return_value = i->GetComponent<Collider>();
				break;
			}
		}

		if (horizontal_value) return return_value;
		if (vertical_value) return return_value;
		return return_value;
	}

	bool IsColliding() const
	{
		bool horizontal_value = false, vertical_value = false;
		for (auto i : GameObject::GetGameObjectsWithComponent<Collider>())
		{
			if (i->M_id.GetID() == m_p_game_object->M_id.GetID()) continue;

			if (m_p_game_object->GetComponent<Physics>()->M_velocity->m_x > 0)
				horizontal_value = CheckRight(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			else
				horizontal_value = CheckLeft(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);

			if (m_p_game_object->GetComponent<Physics>()->M_velocity->m_y > 0)
				vertical_value = CheckTop(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);
			else
				vertical_value = CheckBottom(m_p_bounding_box, i->GetComponent<Collider>()->m_p_bounding_box);

			if (vertical_value || horizontal_value) break;
		}

		if (horizontal_value) return true;
		if (vertical_value) return true;
		return false;
	}

	static const int OFFSET = 1;

	static bool CheckRight(Bounding_Box* box_a, Bounding_Box* box_b)
	{
		if (box_a->bottom <= box_b->top
			|| box_a->top >= box_b->bottom)
			return false;

		if (box_a->right + OFFSET <= box_b->left
			|| box_a->left >= box_b->right + OFFSET)
			return false;

		return true;
	}

	static bool CheckLeft(Bounding_Box* box_a, Bounding_Box* box_b)
	{
		if (box_a->bottom <= box_b->top
			|| box_a->top >= box_b->bottom)
			return false;

		if (box_a->right <= box_b->left + OFFSET
			|| box_a->left + OFFSET >= box_b->right)
			return false;

		return true;
	}

	static bool CheckTop(Bounding_Box* box_a, Bounding_Box* box_b)
	{
		if (box_a->bottom <= box_b->top + OFFSET
			|| box_a->top + OFFSET >= box_b->bottom)
			return false;

		if (box_a->right <= box_b->left
			|| box_a->left >= box_b->right)
			return false;

		return true;
	}

	static bool CheckBottom(Bounding_Box* box_a, Bounding_Box* box_b)
	{
		if (box_a->bottom + OFFSET <= box_b->top
			|| box_a->top>= box_b->bottom + OFFSET)
			return false;

		if (box_a->right <= box_b->left
			|| box_a->left >= box_b->right)
			return false;

		return true;
	}

	static bool CheckCollision(Bounding_Box* box_a, Bounding_Box* box_b)
	{
		if (box_a->bottom <= box_b->top)
			return false;

		if (box_a->top >= box_b->bottom)
			return false;

		if (box_a->right <= box_b->left)
			return false;

		if (box_a->left >= box_b->right)
			return false;

		return true;
	}

	void Spawn() override {}
	void Update() override
	{
		
	}
	void Destroy() override {}
};

#endif