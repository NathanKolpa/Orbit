#include <Engine/Infrastructure/GLFW/GlfwKeyMapper.hpp>
#include <GLFW/glfw3.h>
#include <Engine/Core/pch.hpp>

orb::GlfwKeyMapper::GlfwKeyMapper()
{
	m_map[GLFW_KEY_A] = KeyboardKey::A;
	m_map[GLFW_KEY_B] = KeyboardKey::B;
	m_map[GLFW_KEY_C] = KeyboardKey::C;
	m_map[GLFW_KEY_D] = KeyboardKey::D;
	m_map[GLFW_KEY_E] = KeyboardKey::E;
	m_map[GLFW_KEY_F] = KeyboardKey::F;
	m_map[GLFW_KEY_G] = KeyboardKey::G;
	m_map[GLFW_KEY_H] = KeyboardKey::H;
	m_map[GLFW_KEY_I] = KeyboardKey::I;
	m_map[GLFW_KEY_J] = KeyboardKey::J;
	m_map[GLFW_KEY_K] = KeyboardKey::K;
	m_map[GLFW_KEY_L] = KeyboardKey::L;
	m_map[GLFW_KEY_M] = KeyboardKey::M;
	m_map[GLFW_KEY_N] = KeyboardKey::N;
	m_map[GLFW_KEY_O] = KeyboardKey::O;
	m_map[GLFW_KEY_P] = KeyboardKey::P;
	m_map[GLFW_KEY_Q] = KeyboardKey::Q;
	m_map[GLFW_KEY_R] = KeyboardKey::R;
	m_map[GLFW_KEY_S] = KeyboardKey::S;
	m_map[GLFW_KEY_T] = KeyboardKey::T;
	m_map[GLFW_KEY_U] = KeyboardKey::U;
	m_map[GLFW_KEY_V] = KeyboardKey::V;
	m_map[GLFW_KEY_W] = KeyboardKey::W;
	m_map[GLFW_KEY_X] = KeyboardKey::X;
	m_map[GLFW_KEY_Y] = KeyboardKey::Y;
	m_map[GLFW_KEY_Z] = KeyboardKey::Z;

	m_map[GLFW_KEY_0] = KeyboardKey::Key0;
	m_map[GLFW_KEY_1] = KeyboardKey::Key1;
	m_map[GLFW_KEY_2] = KeyboardKey::Key2;
	m_map[GLFW_KEY_3] = KeyboardKey::Key3;
	m_map[GLFW_KEY_4] = KeyboardKey::Key4;
	m_map[GLFW_KEY_5] = KeyboardKey::Key5;
	m_map[GLFW_KEY_6] = KeyboardKey::Key6;
	m_map[GLFW_KEY_7] = KeyboardKey::Key7;
	m_map[GLFW_KEY_8] = KeyboardKey::Key8;
	m_map[GLFW_KEY_9] = KeyboardKey::Key9;

	m_map[GLFW_KEY_SPACE] = KeyboardKey::Space;
	m_map[GLFW_KEY_BACKSPACE] = KeyboardKey::Backspace;
	m_map[GLFW_KEY_TAB] = KeyboardKey ::Tab;
	m_map[GLFW_KEY_ESCAPE] = KeyboardKey ::Esc;
	m_map[GLFW_KEY_ENTER] = KeyboardKey ::Enter;

	m_map[GLFW_KEY_LEFT_SHIFT] = KeyboardKey::LeftShift;
	m_map[GLFW_KEY_LEFT_CONTROL] = KeyboardKey::LeftCtrl;
	m_map[GLFW_KEY_LEFT_SUPER] = KeyboardKey::LeftSuper;
	m_map[GLFW_KEY_LEFT_ALT] = KeyboardKey::LeftAlt;

	m_map[GLFW_KEY_RIGHT_SHIFT] = KeyboardKey::RightShift;
	m_map[GLFW_KEY_RIGHT_CONTROL] = KeyboardKey::RightCtrl;
	m_map[GLFW_KEY_RIGHT_ALT] = KeyboardKey::RightAlt;

	m_map[GLFW_KEY_F1] = KeyboardKey ::F1;
	m_map[GLFW_KEY_F2] = KeyboardKey ::F2;
	m_map[GLFW_KEY_F3] = KeyboardKey ::F3;
	m_map[GLFW_KEY_F4] = KeyboardKey ::F4;
	m_map[GLFW_KEY_F5] = KeyboardKey ::F5;
	m_map[GLFW_KEY_F6] = KeyboardKey ::F6;
	m_map[GLFW_KEY_F7] = KeyboardKey ::F7;
	m_map[GLFW_KEY_F8] = KeyboardKey ::F8;
	m_map[GLFW_KEY_F9] = KeyboardKey ::F9;
	m_map[GLFW_KEY_F10] = KeyboardKey ::F10;
	m_map[GLFW_KEY_F11] = KeyboardKey ::F11;
	m_map[GLFW_KEY_F12] = KeyboardKey ::F12;

	m_map[GLFW_KEY_UP] = KeyboardKey ::Up;
	m_map[GLFW_KEY_DOWN] = KeyboardKey ::Down;
	m_map[GLFW_KEY_LEFT] = KeyboardKey ::Left;
	m_map[GLFW_KEY_RIGHT] = KeyboardKey ::Right;

	m_map[GLFW_KEY_PAGE_UP] = KeyboardKey ::PageUp;
	m_map[GLFW_KEY_PAGE_DOWN] = KeyboardKey ::PageDown;
}

orb::KeyboardKey orb::GlfwKeyMapper::getKey(int code)
{
	if(m_map.find(code) == m_map.end())
	{
		throw std::invalid_argument("Unknown key code");
	}

	return m_map[code];
}
