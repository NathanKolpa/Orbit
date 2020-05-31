#pragma once
#include <Engine/Core/pch.hpp>

namespace orb
{
	class ShaderRequirementError : std::exception
	{
	public:
		explicit ShaderRequirementError(const char* requiredShader);
	public:
		const char* what() const noexcept override;
	private:
		std::string m_message;
	};
}