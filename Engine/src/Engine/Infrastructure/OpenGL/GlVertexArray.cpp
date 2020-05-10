#include <Engine/Infrastructure/OpenGL/GlVertexArray.hpp>
#include <glad/glad.h>

void orb::GlVertexArray::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vaoId);
	glBindVertexArray(m_vaoId);

}

void orb::GlVertexArray::unBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void orb::GlVertexArray::draw()
{
}

void orb::GlVertexArray::draw(int vertexCount)
{
	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}

orb::GlVertexArray::GlVertexArray(unsigned int vaoId)
		: m_vaoId(vaoId)
{
}

orb::GlVertexArray *orb::GlVertexArray::create()
{

	unsigned int vao;
	glGenVertexArrays(1, &vao);

	return new GlVertexArray(vao);
}

orb::GlVertexArray::~GlVertexArray()
{
	glDeleteVertexArrays(1, &m_vaoId);
}
