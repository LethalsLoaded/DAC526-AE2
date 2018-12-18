#include "SpriteRenderer.h"
#include "Game.h"
#include "Collider.h"

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
	if (GameObject::GameObjectHasComponent<Collider>(m_p_game_object)) {
		//TODO: Performance intensive? Do on move perhaps?
		// Set the height & width of the box
		auto bounding_box = m_p_game_object->GetComponent<Collider>()->GetBox();
		bounding_box->width = m_p_sprite->GetWidth();
		bounding_box->height = m_p_sprite->GetHeight();
		// Set the four sides
		bounding_box->left = destRect.x;
		bounding_box->right = destRect.x + m_p_sprite->GetWidth();
		bounding_box->top = destRect.y;
		bounding_box->bottom = destRect.y + m_p_sprite->GetHeight();
		// Set the four corners
		bounding_box->top_left = Vector2(destRect.x, destRect.y);
		bounding_box->top_right = Vector2::Translate(bounding_box->top_left, Vector2(0, m_p_sprite->GetWidth()));
		bounding_box->bottom_left = Vector2::Translate(bounding_box->top_left, Vector2(0, m_p_sprite->GetHeight()));
		bounding_box->bottom_right = Vector2::Translate(bounding_box->top_right, Vector2(0, m_p_sprite->GetHeight()));
		m_p_game_object->GetComponent<Collider>()->SetBox(bounding_box);
	}

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
