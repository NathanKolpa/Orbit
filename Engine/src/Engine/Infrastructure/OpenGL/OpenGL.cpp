#include <Engine/Infrastructure/OpenGL/OpenGL.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Engine/Core/pch.hpp>

void orb::OpenGL::init()
{
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		std::runtime_error("Cannot init glad");
	}
}
