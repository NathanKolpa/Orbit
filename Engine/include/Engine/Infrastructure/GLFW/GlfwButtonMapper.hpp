#pragma once

#include <Engine/Core/Model/Input/MouseButton.hpp>

namespace orb
{
	class GlfwButtonMapper
	{
	public:
		MouseButton getButton(int code);
	};
}