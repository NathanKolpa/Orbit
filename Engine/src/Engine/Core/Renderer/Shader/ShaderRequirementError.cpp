#include <Engine/Core/Renderer/Shader/ShaderRequirementError.hpp>

orb::ShaderRequirementError::ShaderRequirementError(const char *requiredShader)
{
	m_message = requiredShader;
	m_message += " not provided";
}

const char *orb::ShaderRequirementError::what() const noexcept
{
	return m_message.c_str();
}
