#pragma once

#include <Engine/Core/Model/Input/KeyboardKey.hpp>
#include <Engine/Core/pch.hpp>

namespace orb
{
	class GlfwKeyMapper
	{
	public:
		GlfwKeyMapper();
	public:
		KeyboardKey getKey(int code);
	private:
		std::unordered_map<int, KeyboardKey> m_map;
	};
}