#include <Engine/Core/Renderer/Shader/ShaderResource.hpp>

orb::ShaderResource::ShaderResource(orb::ShaderSource *openglVertexShader, orb::ShaderSource *openglFragmentShader)
	:m_openglVertexShader(openglVertexShader), m_openglFragmentShader(openglFragmentShader)
{

}

const orb::ShaderSource &orb::ShaderResource::requireOpenglFragmentShader() const
{
	if(!m_openglFragmentShader)
		throw ShaderRequirementError("OpenGL FragmentShader");

	return *m_openglFragmentShader;
}

const orb::ShaderSource &orb::ShaderResource::requireOpenglVertexShader() const
{
	if(!m_openglVertexShader)
		throw ShaderRequirementError("OpenGL VertexShader");

	return *m_openglVertexShader;
}
