#ifdef ORB_OPENGL


#include <Engine/Infrastructure/RenderApi/OpenGL/Shader/GlShader.hpp>
#include <glad/glad.h>

unsigned int orb::GlShader::s_boundShader = 0;

unsigned int compileShader(unsigned int type, const std::string& source)
{
	const char* sourceStr = source.c_str();

	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &sourceStr, NULL);
	glCompileShader(shader);

	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		throw orb::ShaderCompileException(infoLog);
	}

	return shader;
}

void orb::GlShader::bind()
{
	glUseProgram(m_shaderId);
	s_boundShader = m_shaderId;
}

void orb::GlShader::unBind()
{
	glUseProgram(0);
	s_boundShader = 0;
}

orb::GlShader::GlShader(unsigned int shaderId)
	:m_shaderId(shaderId)
{

}

orb::GlShader *orb::GlShader::create(const std::string &vertexSource, const std::string &fragmentSource)
{
	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

	unsigned int shader = glCreateProgram();
	glAttachShader(shader, vertexShader);
	glAttachShader(shader, fragmentShader);
	glLinkProgram(shader);


	int success;
	char infoLog[512];
	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader, 512, NULL, infoLog);
		throw orb::ShaderCompileException(infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GlShader* glShader = new GlShader(shader);
	glShader->loadUniforms();

	return glShader;
}

void orb::GlShader::loadUniforms()
{
	int uniformCount;
	const GLsizei bufSize = 16;
	GLchar name[bufSize];
	GLsizei length;
	GLint size;
	GLenum type;

	glGetProgramiv(m_shaderId, GL_ACTIVE_UNIFORMS, &uniformCount);

	for (int i = 0; i < uniformCount; i++)
	{
		glGetActiveUniform(m_shaderId, (GLuint)i, bufSize, &length, &size, &type, name);

		m_uniformLocations[name] = i;
	}
}

#endif
