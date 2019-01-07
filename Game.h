#ifndef GAME_H
#define GAME_H

#include <string>
#include "Level.h"
#include <vector>
#include <SDL.h>
#include "Sprite.h"
#include <unordered_map>
#include "LevelManager.h"

enum GameState
{
	MENU,
	IN_PROGRESS,
	PAUSE,
	TRANSITION,
	RESULT_SCREEN,
	LAST_ENUM
};

class Game
{
private:
	static Game* m_p_game_instance;
	static const std::string ASSETS_FOLDER;

	Uint32 m_frame_start;
	int m_frame_time;

	GameState m_game_state = GameState::MENU;
	int m_window_height, m_window_width;
	std::string m_window_name;
	Level* m_p_current_level;
	std::vector<Level*> m_p_game_levels;

	SDL_Window* m_p_window = nullptr;
	SDL_Renderer* m_p_renderer = nullptr;

	LevelManager* m_p_level_manager = nullptr;

protected:
	void FirstSetup();
public:
	static const int FRAMES_PER_SECOND = 60;
	const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;
	static const int RELATIVE_TILE_SPACE = 32;

	std::unordered_map<Sprite*, GameObject*> M_p_sprites;

	static Game* GetInstance();
	Game(int window_height, int window_width, std::string window_name, Level* force_level = nullptr);
	GameState GetGameState() const;
	void SetGameState(GameState game_state);
	void UpdateGame();
	Level* GetActiveLevel() const;
	SDL_Renderer* GetRenderer()
	{
		return m_p_renderer;
	}

	void SetLevel(Level* level)
	{
		m_p_current_level = level;
	}

	void AddGameLevel(Level* level)
	{
		m_p_game_levels.push_back(level);
	}

	void SetActiveLevel(Level* level)
	{
		m_p_current_level = level;
	}

	void SetWindowSize(Vector2 new_size) const
	{
		SDL_SetWindowSize(m_p_window, new_size.m_x, new_size.m_y);
	}
};

#endif
