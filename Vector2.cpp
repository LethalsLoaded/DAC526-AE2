#include "Vector2.h"

Vector2::Vector2()
{
	m_x = 0; m_y = 0;
}

Vector2::Vector2(float xPos, float yPos)
{
	this->m_x = xPos;
	this->m_y = yPos;
}


Vector2 Vector2::Translate(const Vector2& const vectorA, const Vector2& const vectorB)
{
	const Vector2 result(vectorA.m_x + vectorB.m_x, vectorA.m_x + vectorB.m_y);

	return result;
}

Vector2 Vector2::Translate(const Vector2& vectorB)
{
	this;

	const auto result_x = this->m_x + vectorB.m_x;
	const auto result_y = this->m_y + vectorB.m_y;
	m_x = result_x;
	m_y = result_y;
	const Vector2 result(result_x, result_y);
	return result;
}

Vector2 Vector2::operator*(const int& i)
{
	this->m_x *= i;
	this->m_y *= i;

	return *this;
}
