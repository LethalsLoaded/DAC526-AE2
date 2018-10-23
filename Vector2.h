#pragma once
class Vector2
{
public:
	float m_x;
	float m_y;

public:
	Vector2(float xPos, float yPos);
	Vector2 Translate(const Vector2& const vectorA, const Vector2& const vectorB);
};
