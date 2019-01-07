#include "Level.h"
#include "Game.h"
#include <fstream>
#include <algorithm>
#include "Block.h"
#include "NonPlayableCharacter.h"
#include "SpriteRenderer.h"
#include "Player.h"
#include "Collider.h"

Level::Level(std::string path_to_level_data)
{
	enemy_count = 0;
	m_level_name = path_to_level_data;
	Game::GetInstance()->AddGameLevel(this);
	Game::GetInstance()->SetGameState(GameState::TRANSITION);
	std::ifstream file_stream("Assets/Levels/" + m_level_name);

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
					new_game_object->AddComponent<Collider>();
						new_game_object->M_name = "Wall";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/wall.bmp"));
						auto const block = new_game_object->AddComponent<Block>();
						block->M_isWall = true;
						//new_game_object->AddComponent<Collider>();
					}
					break;
				// ENEMY
				case 'E':
					{
					auto floor_object = new GameObject("floor_object_to_change",
						new Vector2(x_spacing, y_spacing),
						Sprite::GetOrCreateSprite("Assets/floor.bmp"));
						AddGameObjectToLevel(floor_object);
						new_game_object->M_name = "Enemy";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/enemy.bmp"));
						new_game_object->M_render_order = 10;
						auto const npc = new_game_object->AddComponent<NonPlayableCharacter>();
						auto collider = new_game_object->AddComponent<Collider>();
						collider->M_isTrigger = true;
						if(m_level_name == "Level_1.txt")
						{
							npc->m_node_locations.emplace_back(370, 64);
							npc->m_node_locations.emplace_back(370, 100);
							npc->m_node_locations.emplace_back(370, 235);
							npc->m_node_locations.emplace_back(550, 235);
							npc->m_node_locations.emplace_back(550, 125);
							npc->m_node_locations.emplace_back(370, 120);
						}
						else
						{
							if (enemy_count == 0)
							{
								npc->m_node_locations.emplace_back(370, 64);
								npc->m_node_locations.emplace_back(370, 100);
								npc->m_node_locations.emplace_back(370, 235);
								npc->m_node_locations.emplace_back(550, 235);
								npc->m_node_locations.emplace_back(550, 125);
								npc->m_node_locations.emplace_back(370, 120);
							}
							else
							{
								npc->m_node_locations.emplace_back(128, 90);
								npc->m_node_locations.emplace_back(362, 90);
								npc->m_node_locations.emplace_back(352, 320);
								npc->m_node_locations.emplace_back(385, 320);
								npc->m_node_locations.emplace_back(385, 385);
								npc->m_node_locations.emplace_back(128, 385);
							}
							enemy_count++;
						}
					}
					break;
				// TARGET
				case 'T':
					{
					auto floor_object = new GameObject("floor_object_to_change",
						new Vector2(x_spacing, y_spacing),
						Sprite::GetOrCreateSprite("Assets/floor.bmp"));
						AddGameObjectToLevel(floor_object);
						new_game_object->M_name = "Target";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/target.bmp"));
						auto const target = new_game_object->AddComponent<NonPlayableCharacter>();
						new_game_object->M_render_order = 10;
						auto collider = new_game_object->AddComponent<Collider>();
						collider->M_isTrigger = true;
					}
					break;
				case 'P':
					{
						new_game_object->AddComponent<Collider>();

						auto floor_object = new GameObject("floor_object_to_change", 
							new Vector2(x_spacing, y_spacing),
							Sprite::GetOrCreateSprite("Assets/floor.bmp"));
						AddGameObjectToLevel(floor_object);
						new_game_object->M_name = "Player";
						new_sprite_rend->ChangeSprite(Sprite::GetOrCreateSprite("Assets/player.bmp"));
						new_game_object->AddComponent<Player>();
						new_game_object->M_render_order = 15;
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

	Game::GetInstance()->SetGameState(GameState::IN_PROGRESS);
	printf("STATE: %d\n", Game::GetInstance()->GetGameState());

}

Level::~Level()
{
	for (auto i : m_p_game_objects)
		delete(i);
}

std::vector<GameObject*> Level::GetGameObjects() const
{
	return m_p_game_objects;
}

void Level::Render()
{
	if (!M_is_active) return;

	std::sort(m_p_game_objects.begin(), m_p_game_objects.end(), OverloadOperator());
	//printf("STATE: %d\n", Game::GetInstance()->GetGameState());
	if(Game::GetInstance()->GetGameState() == GameState::IN_PROGRESS)
		for(auto game_object : m_p_game_objects)
		{
			for(auto component : game_object->GetComponents())
			{
				component->Update();
			}
		}
}
