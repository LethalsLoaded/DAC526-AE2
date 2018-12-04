#include "Game.h"
#include "InputHandler.h"

//const int Game::FRAMES_PER_SECOND = 60;
Game* Game::m_p_game_instance = nullptr;
const std::string Game::ASSETS_FOLDER = "Assets";

void Game::FirstSetup()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	//TODO: TEXT: TTF_Init();

	/*****************************************/

	// Create the game window

	m_p_window = SDL_CreateWindow
	(
		m_window_name.c_str(),
		50,
		50,
		m_window_width,
		m_window_height,
		0
	);

	// Check for error
	if (!m_p_window)
	{
		printf("WINDOW init failed: %s\n", SDL_GetError());
		printf("Press any key to continue.");
		getchar();
		return;
	}

	/*****************************************/

	// Create the game renderer
	m_p_renderer = SDL_CreateRenderer
	(
		m_p_window,
		-1,
		0
	);

	if (!m_p_renderer)
	{
		printf("RENDERER init failed: %s\n", SDL_GetError());
		printf("Press any key to continue.");
		getchar();
		return;
	}

	/*****************************************/

	if (m_p_level_manager == nullptr)
		m_p_level_manager = new LevelManager();

}

Game * Game::GetInstance()
{
	return m_p_game_instance;
}

Game::Game(int window_height, int window_width, std::string window_name, Level * force_level)
{
	m_p_game_instance = this;

	m_window_height = window_height;
	m_window_width = window_width;
	m_window_name = window_name;
	if (force_level != nullptr)
	{
		m_p_current_level = force_level;
		m_p_game_levels.push_back(force_level);
	}

	FirstSetup();
}

GameState Game::GetGameState() const
{
	return m_game_state;
}

void Game::SetGameState(GameState game_state)
{
	m_game_state = game_state;
}

void Game::UpdateGame()
{
	// Update the input handler
	InputHandler::GetInstance()->Update();

	m_frame_start = SDL_GetTicks();
	SDL_RenderClear(m_p_renderer);



	// Update the renderer
	m_p_current_level->Render();

	SDL_RenderPresent(m_p_renderer);

	// FPS limiter
	m_frame_time = SDL_GetTicks() - m_frame_start;
	if (FRAME_DELAY > m_frame_time)
		SDL_Delay(FRAME_DELAY - m_frame_time);
}

Level* Game::GetActiveLevel() const
{
	return m_p_current_level;
}
