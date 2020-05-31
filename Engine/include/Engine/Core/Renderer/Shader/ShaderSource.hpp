#pragma once
#include <Engine/Core/pch.hpp>

namespace orb
{
	class ShaderSource
	{
	public:
		virtual std::string getSource() const = 0;
	};
}