

#include <ctime>
#include <iostream>
#include <conio.h>
#include "SpriteRenderer.h"
#include "Block.h"
#include "Game.h"

#undef main

Game* SetupGame()
{
	auto p_game = new Game(500, 500, "DAC526-AE2: Edge Assassin");
	p_game->SetGameState(GameState::IN_PROGRESS);
	return p_game;
}

//Level* TestLevel()
//{
//	auto my_level = new Level();
//	Game::GetInstance()->SetLevel(my_level);
//
//	const auto middle_block_sprite = Sprite::GetOrCreateSprite("Assets/blank_test.bmp");
//	auto other_block_sprite = Sprite::GetOrCreateSprite("Assets/blank_test.bmp");
//	auto middle_block = new GameObject("Test block", new Vector2(50, 50), middle_block_sprite);
//
//	auto another_block = new GameObject("Another Block", new Vector2(150, 29), other_block_sprite);
//	middle_block->M_position->Translate( Vector2(50, 50));
//	delete(another_block);
//	other_block_sprite = Sprite::GetOrCreateSprite("Assets/blank_test.bmp");
//	auto yet_another_block = new GameObject("Another Block", new Vector2(150, 29), other_block_sprite);
//
//	
//
//	return my_level;
//}

int main()
{
	srand(time(nullptr));
	auto game = SetupGame();
	//auto gameLevel = TestLevel();

	Vector2* v2 = new Vector2(0.0f, 0.0f);

	GameObject* myGO = new GameObject("Test", v2);

	std::cout << myGO->M_name << std::endl;


	myGO->AddComponent<Block>();

	myGO->AddComponent<SpriteRenderer>();

	//auto myBlock = static_cast<Block*>(myGO->GetComponent<Block>());
	//auto myRend = static_cast<SpriteRenderer*>(myGO->GetComponent<SpriteRenderer>());
	auto myRend = myGO->GetComponent<SpriteRenderer>();

	auto myBlock = myGO->GetComponent <Block>();

	//std::cout << myRend->GetName() << "ID: " << myRend->M_id.GetID() << std::endl;
	std::cout << myBlock->GetName() << "ID: " << myBlock->M_id.GetID() << std::endl;

	
	while (game->GetGameState() != GameState::RESULT_SCREEN)
		game->UpdateGame();

	_getch();
	return 0;
}

