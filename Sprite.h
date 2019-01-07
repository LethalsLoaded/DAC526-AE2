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

	/*
	 * Modifies the m_file_path to whatever is provided in parameter
	 */
	void ChangeSpritePath(std::string file_path);

	/*
	 * Returns height
	 */
	int GetHeight()
	{
		return m_height;
	}

	/*
	 * Returns width
	 */
	int GetWidth()
	{
		return m_width;
	}

	/*
	 * Static method which checks if a sprite is loaded in memory.
	 * If it finds the sprite, will return a pointer to it
	 * otherwise will create it and return it.
	 * 
	 * This method prevents duplicate sprites being loaded into memory.
	 */
	static Sprite* GetOrCreateSprite(std::string file_path);
};

#endif