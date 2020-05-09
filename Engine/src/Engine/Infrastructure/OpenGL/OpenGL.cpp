#include <Engine/Infrastructure/OpenGL/OpenGL.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Engine/Core/pch.hpp>


void orb::OpenGL::init(orb::RenderContext &context)
{
	context.setContext();

	int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	if (!status)
	{
		throw std::runtime_error("Cannot init glad");
	}
}

void orb::OpenGL::destroy()
{

}

orb::RenderFactory &orb::OpenGL::getFactory()
{
	return m_factory;
}

const char *orb::OpenGL::getVersionString()
{
	return (const char*)glGetString(GL_VERSION);
}
