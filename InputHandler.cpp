#include "InputHandler.h"
#include <cstdio>


InputHandler* InputHandler::m_p_instance;

void InputHandler::Update()
{
	//if (m_p_keyboard_states != SDL_GetKeyboardState(nullptr))
	//	printf("Changed");
	//m_p_keyboard_states = SDL_GetKeyboardState(nullptr);

	SDL_PumpEvents();

	m_p_keyboard_states = const_cast<Uint8*>(SDL_GetKeyboardState(nullptr));

	// ***********************************

	while(SDL_PollEvent(&m_event))
	{
		switch(m_event.type)
		{
		case SDL_KEYDOWN:
			OnKeyDown();
			break;
		case SDL_KEYUP:
			OnKeyUp();
			break;
		}
	}
}

bool InputHandler::IsKeyPressed(SDL_Scancode key)
{
	return m_p_keyboard_states[key];
}

void InputHandler::OnKeyDown()
{
	m_p_keyboard_states = const_cast<Uint8*>(SDL_GetKeyboardState(nullptr));
}

void InputHandler::OnKeyUp()
{
	m_p_keyboard_states = const_cast<Uint8*>(SDL_GetKeyboardState(nullptr));
}
