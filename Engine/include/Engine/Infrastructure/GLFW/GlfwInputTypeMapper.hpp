#pragma once

#include <Engine/Core/Model/Input/InputType.hpp>

namespace orb
{
	class GlfwInputTypeMapper
	{
	public:
		InputType getType(int type);
	};
}