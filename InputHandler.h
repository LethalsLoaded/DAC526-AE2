#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SDL.h>

class InputHandler
{
private:
	static InputHandler* m_p_instance;
	const Uint8* m_p_keyboard_states;
public:
	InputHandler()
	{
		m_p_instance = this;
	}

	static InputHandler* GetInstance()
	{
		if (m_p_instance == nullptr)
			m_p_instance = new InputHandler();
		return m_p_instance;
	}
	void Update();
	bool IsKeyPressed(SDL_Scancode key);
};

#endif