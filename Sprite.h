#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <SDL.h>



class Sprite
{
private:
	int m_height, m_width;
	std::string m_file_path;
	SDL_Texture* m_p_texture;
	
public:
	std::string M_sprite_name;
	// Constructor populates private variables
	Sprite(std::string file_path);
	// Deconstructor destroys the texture
	~Sprite();
	// Returns file path
	std::string GetFilePath();
	// Returns the texture pointer
	SDL_Texture* GetTexture();

	void ChangeSpritePath(std::string file_path);
	int GetHeight()
	{
		return m_height;
	}

	int GetWidth()
	{
		return m_width;
	}

	

	static Sprite* GetOrCreateSprite(std::string file_path);
};

#endif