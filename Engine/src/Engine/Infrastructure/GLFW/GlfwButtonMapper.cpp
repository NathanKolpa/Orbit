#include <Engine/Infrastructure/GLFW/GlfwButtonMapper.hpp>
#include <GLFW/glfw3.h>
#include <Engine/Core/pch.hpp>

orb::MouseButton orb::GlfwButtonMapper::getButton(int code)
{
	switch(code)
	{
		case GLFW_MOUSE_BUTTON_1: return MouseButton ::LeftMouse;
		case GLFW_MOUSE_BUTTON_2: return MouseButton ::RightMouse;
		case GLFW_MOUSE_BUTTON_3: return MouseButton ::MiddleMouse;
		case GLFW_MOUSE_BUTTON_4: return MouseButton ::Mouse4;
		case GLFW_MOUSE_BUTTON_5: return MouseButton ::Mouse5;
	}

	throw std::invalid_argument("Unknown mouse button code");
}
