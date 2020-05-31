#ifdef ORB_OPENGL

#include <Engine/Infrastructure/RenderApi/OpenGL/OpenGLApi.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Engine/Core/pch.hpp>

#ifdef ORB_DEBUG
#include <examples/imgui_impl_opengl3.h>
#endif


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

	if(severity == 0x826b)
		return;

	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
}

const char *orb::OpenGLApi::getVersionString()
{
	return (const char *) glGetString(GL_VERSION);
}

orb::OpenGLApi orb::OpenGLApi::create()
{
	int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	if (!status)
	{
		throw std::runtime_error("Cannot init glad");
	}

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, nullptr);

#ifdef ORB_DEBUG
	ImGui_ImplOpenGL3_Init();
#endif

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

void orb::OpenGLApi::clear()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

orb::Shader *orb::OpenGLApi::createShader(const orb::ShaderResource &source)
{
	return GlShader::create(source.requireOpenglVertexShader().getSource(), source.requireOpenglFragmentShader().getSource());
}


#endif