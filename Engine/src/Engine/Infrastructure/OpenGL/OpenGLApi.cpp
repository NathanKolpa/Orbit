#include <Engine/Infrastructure/OpenGL/OpenGLApi.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Engine/Core/pch.hpp>


const char *orb::OpenGLApi::getVersionString()
{
	return (const char*)glGetString(GL_VERSION);
}

orb::OpenGLApi orb::OpenGLApi::create(orb::RenderContext &context)
{
	context.setContext();

	int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	if (!status)
	{
		throw std::runtime_error("Cannot init glad");
	}

	return OpenGLApi();
}
