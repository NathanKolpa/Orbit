#pragma once
#include <Engine/Core/pch.hpp>

namespace orb
{
	class ShaderCompileException : std::exception
	{
	public:
		explicit ShaderCompileException(std::string what);
	public:
		const char* what() const noexcept override;
	private:
		std::string m_what;
	};
}