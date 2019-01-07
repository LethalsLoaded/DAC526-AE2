#ifndef SPRITERENDERER_H
#define SPRITRERENDERER_H
#include "Component.h"
#include <string>
#include "Sprite.h"
#include "Vector2.h"



class SpriteRenderer : public Component
{
	

public:
	void Spawn() override {}
	/*
	 * Runs every frame; draws the sprite
	 * attached to the component every
	 * frame.
	 */
	void Update() override;
	void Destroy() override {}

	std::string M_sprite_name;
	SpriteRenderer();
	float m_size = 1.0f;
	Sprite* m_p_sprite;

	/*
	 * Changes what sprite is drawn.
	 */
	void ChangeSprite(Sprite* sprite);
	~SpriteRenderer();

};
#endif

//

// 0, 16, 32, 48
// 16 x   x   x
// 32 x   x   x
// 48 x   x   x