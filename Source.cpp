

#include <ctime>
#include <iostream>
#include <conio.h>
#include "SpriteRenderer.h"
#include "Block.h"
#include "Game.h"

#undef main

Game* SetupGame()
{
	auto p_game = new Game(480, 800, "DAC526-AE2: Edge Assassin");
	return p_game;
}

int main()
{
	srand(time(nullptr));
	auto game = SetupGame();
	//auto gameLevel = TestLevel();

	//auto myBlock = static_cast<Block*>(myGO->GetComponent<Block>());
	//auto myRend = static_cast<SpriteRenderer*>(myGO->GetComponent<SpriteRenderer>());

	//std::cout << myRend->GetName() << "ID: " << myRend->M_id.GetID() << std::endl;

	
	while (game->GetGameState() != GameState::RESULT_SCREEN)
			game->UpdateGame();

	_getch();
	return 0;
}

