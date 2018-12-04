#include "InputHandler.h"
#include <cstdio>


InputHandler* InputHandler::m_p_instance;

void InputHandler::Update()
{
	if (m_p_keyboard_states != SDL_GetKeyboardState(nullptr))
		printf("Changed");
	m_p_keyboard_states = SDL_GetKeyboardState(nullptr);
}

bool InputHandler::IsKeyPressed(SDL_Scancode key)
{
	return m_p_keyboard_states[key];
}
