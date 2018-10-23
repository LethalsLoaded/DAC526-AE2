#include "GameObject.h"
#include <conio.h>
#include <iostream>
#include "Block.h"

int main()
{
	Vector2* v2 = new Vector2(0.0f, 0.0f);
	GameObject* myGO = new GameObject("Test", v2);

	std::cout << myGO->GetName() << std::endl;
	_getch();

	myGO->AddComponent<Block>();
	Block* myBlock = dynamic_cast<Block&>(*myGO->GetComponent<Block>());
	std::string name =myBlock->GetName();
	std::cout << name;
	_getch();
}
