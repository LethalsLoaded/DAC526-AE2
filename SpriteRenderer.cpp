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
	Game::GetInstance()->M_p_sprites[sprite] = m_p_game_object;
}

SpriteRenderer::~SpriteRenderer()
{
	Game::GetInstance()->M_p_sprites.erase(m_p_sprite);
	if (Game::GetInstance()->M_p_sprites.find(m_p_sprite) == Game::GetInstance()->M_p_sprites.end())
		delete(m_p_sprite);
}
