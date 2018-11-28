#include "SpriteRenderer.h"
#include "Game.h"

void SpriteRenderer::Update()
{
	if (m_p_sprite == nullptr || m_p_sprite->GetTexture() == nullptr) return;
	SDL_Rect destRect = 
	{ 
		m_p_game_object->M_position->m_x,
		m_p_game_object->M_position->m_y,
		m_p_sprite->GetWidth(),
		m_p_sprite->GetHeight()
	};
	SDL_RenderCopy(Game::GetInstance()->GetRenderer(), m_p_sprite->GetTexture(), nullptr, &destRect);
}

SpriteRenderer::SpriteRenderer()
{
}

void SpriteRenderer::ChangeSprite(Sprite* sprite)
{
	m_p_sprite = sprite;
}
