#ifndef SPRITERENDERER_H
#define SPRITRERENDERER_H
#include "Component.h"
#include <string>
#include "Sprite.h"

class SpriteRenderer : public Component
{
private:
	
public:
	void Spawn() override {}
	void Update() override;
	void Destroy() override {}

	std::string M_sprite_name;
	SpriteRenderer();
	float m_size = 1.0f;
	Sprite* m_p_sprite;

	void ChangeSprite(Sprite* sprite);
	~SpriteRenderer();
};
#endif