#include <Engine/Core/Renderer/Shader/ShaderCompileException.hpp>

orb::ShaderCompileException::ShaderCompileException(std::string what)
	:m_what(what)
{

}

const char *orb::ShaderCompileException::what() const noexcept
{
	return m_what.c_str();
}
