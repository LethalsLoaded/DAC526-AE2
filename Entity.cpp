#include "Entity.h"

void Entity::ExecuteAction(Action action)
{
	if (action == Action::MOVE_UP)
		printf("Move up");
}
