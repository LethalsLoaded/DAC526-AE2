#include "Sprite.h"
#include "Game.h"


void Sprite::ChangeSpritePath(std::string file_path)
{

}

Sprite* Sprite::GetOrCreateSprite(std::string file_path)
{
	Sprite* return_sprite = nullptr;
	for(auto i : Game::GetInstance()->M_p_sprites)
	{
		if (i->GetFilePath() != file_path) continue;
		return_sprite = i;
		break;
	}

	if(return_sprite == nullptr)
	{
		Sprite* new_sprite = new Sprite(file_path);
		return_sprite = new_sprite;
	}

	return return_sprite;
}

Sprite::Sprite(std::string file_path)
{
	M_sprite_name = "Default Sprite";
	m_file_path = file_path;

	

	// Create the surface
	SDL_Surface* p_surface = SDL_LoadBMP(m_file_path.c_str());
	if (!p_surface)
	{
		printf("Surface for bitmap %s not loaded.\n", m_file_path.c_str());
		printf("%s\n", SDL_GetError());
		return;
	}

	// Create the texture
	m_p_texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), p_surface);
	if (!m_p_texture)
	{
		// Output an error if texture loading went south
		printf("Texture for bitmap %s not loaded.\n", m_file_path.c_str());
		printf("%s\n", SDL_GetError());
	}

	// Set the height and width
	m_height = p_surface->h;
	m_width = p_surface->w;

	SDL_FreeSurface(p_surface);
}

Sprite::~Sprite()
{
	if (m_p_texture) SDL_DestroyTexture(m_p_texture);
}

std::string Sprite::GetFilePath()
{
	return m_file_path;
}

SDL_Texture * Sprite::GetTexture()
{
	return m_p_texture;
}
