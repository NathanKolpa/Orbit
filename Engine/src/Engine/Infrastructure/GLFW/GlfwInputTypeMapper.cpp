#include <GLFW/glfw3.h>
#include <Engine/Core/Model/Input/InputType.hpp>
#include <Engine/Infrastructure/GLFW/GlfwInputTypeMapper.hpp>
#include <Engine/Core/pch.hpp>

orb::InputType orb::GlfwInputTypeMapper::getType(int type)
{
	switch(type)
	{
		case GLFW_PRESS: return InputType ::Press;
		case GLFW_RELEASE: return InputType ::Release;
		case GLFW_REPEAT: return InputType ::Repeat;
	}

	throw std::invalid_argument("Unknown input type code");
}
