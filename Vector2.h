#pragma once
class Vector2
{
public:
	float m_x;
	float m_y;

public:
	/*
	 * Constructors.
	 * Constructor with no parameters defaults them to 0,0
	 */
	Vector2();
	Vector2(float xPos, float yPos);

	/*
	 * Static method that translates two vectors by each other
	 */
	static Vector2 Translate(const Vector2& const vectorA, const Vector2& const vectorB);

	/*
	 * Translates this vector by vectorB
	 */
	Vector2 Translate(const Vector2& vectorB);

	/*
	 * Multiplication operator to allow vector * vector operations
	 */
	Vector2 operator*(const int & i);
};
