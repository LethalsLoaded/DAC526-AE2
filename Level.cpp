#include "Level.h"
#include "Game.h"
#include <fstream>
#include "Block.h"
#include "NonPlayableCharacter.h"
#include "SpriteRenderer.h"
#include "Player.h"

Level::Level(std::string path_to_level_data)
{
	m_level_path = path_to_level_data;
	Game::GetInstance()->AddGameLevel(this);
	std::ifstream file_stream("Assets/Levels/" + m_level_path);

	std::string tempLine;
	while (std::getline(file_stream, tempLine))
	{
		if (!tempLine.empty())
			m_level_design.push_back(tempLine);
	}
	file_stream.close();


	int y_spacing = 0;

	// Y
	for(auto y_path : m_level_design)
	{
		// X 
		int x_spacing = 0;
		for(auto x_tile : y_path)
		{
			auto new_game_object = new GameObject("Wall", new Vector2(x_spacing, y_spacing));
			AddGameObjectToLevel(new_game_object);
			auto new_sprite_rend = new_game_object->AddComponent<SpriteRenderer>();

			switch(x_tile)
			{
				case 'W':
					{
						new_game_object->M_name = "Wall";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/wall.bmp"));
						auto const block = new_game_object->AddComponent<Block>();
						block->M_isWall = true;
					}
					break;
				// ENEMY
				case 'E':
					{
						new GameObject("Floor",
						new Vector2(x_spacing, y_spacing),
						Sprite::GetOrCreateSprite("Assets/floor.bmp"));
						new_game_object->M_name = "Enemy";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/enemy.bmp"));
						//auto const npc = new_game_object->AddComponent<NonPlayableCharacter>();
					}
					break;
				// TARGET
				case 'T':
					{
						new GameObject("Floor",
						new Vector2(x_spacing, y_spacing),
						Sprite::GetOrCreateSprite("Assets/floor.bmp"));
						new_game_object->M_name = "Target";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/target.bmp"));
						//auto const target = new_game_object->AddComponent<NonPlayableCharacter>();
					}
					break;
				case 'P':
					{
						new GameObject("Floor", 
							new Vector2(x_spacing, y_spacing),
							Sprite::GetOrCreateSprite("Assets/floor.bmp"));
						new_game_object->M_name = "IM HERE PLZ";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/player.bmp"));
						auto const player = new_game_object->AddComponent<Player>();
						new_game_object->M_render_order = 10;
					}
					break;
				case '.':
					{
						new_game_object->M_name = "Ground";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/floor.bmp"));
					}
					break;
			}
			x_spacing += Game::RELATIVE_TILE_SPACE;
		}
		y_spacing += Game::RELATIVE_TILE_SPACE;
	}
}

std::vector<GameObject*> Level::GetGameObjects() const
{
	return m_p_game_objects;
}

void Level::Render()
{
	if (!M_is_active) return;

	std::sort(m_p_game_objects.begin(), m_p_game_objects.end());
	
	for(auto game_object : m_p_game_objects)
	{
		for(auto component : game_object->GetComponents())
		{
			component->Update();
		}
	}
}
