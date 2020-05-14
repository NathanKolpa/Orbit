#ifdef ORB_OPENGL

#include <Engine/Infrastructure/RenderApi/OpenGL/OpenGLApi.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Engine/Core/pch.hpp>


void GLAPIENTRY
MessageCallback(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar *message,
		const void *userParam)
{

	auto stream = severity != 0x826b ? stderr : stdout;

	fprintf(stream, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
}

const char *orb::OpenGLApi::getVersionString()
{
	return (const char *) glGetString(GL_VERSION);
}

orb::OpenGLApi orb::OpenGLApi::create(orb::RenderContext &context)
{
	context.setContext();

	int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	if (!status)
	{
		throw std::runtime_error("Cannot init glad");
	}

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, nullptr);

	return OpenGLApi();
}

orb::VertexArray *orb::OpenGLApi::createVertexArray()
{
	return GlVertexArray::create();
}

void orb::OpenGLApi::setViewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}

#endif