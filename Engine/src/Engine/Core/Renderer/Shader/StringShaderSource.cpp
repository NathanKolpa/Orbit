#include <Engine/Core/Renderer/Shader/StringShaderSource.hpp>

orb::StringShaderSource::StringShaderSource(std::string source)
	:m_source(source)
{

}

std::string orb::StringShaderSource::getSource() const
{
	return m_source;
}
