#include <Engine/Infrastructure/RenderApi/OpenGL/Buffer/GlIndexBuffer.hpp>
#include <glad/glad.h>

unsigned int orb::GlIndexBuffer::s_boundEbo = 0;

void orb::GlIndexBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboId);
	s_boundEbo = m_eboId;
}

void orb::GlIndexBuffer::unBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	s_boundEbo = 0;
}

void orb::GlIndexBuffer::setData(unsigned int *data, size_t indices)
{

}

orb::GlIndexBuffer::GlIndexBuffer(unsigned int eboId)
	:m_eboId(eboId)
{

}

orb::GlIndexBuffer *orb::GlIndexBuffer::create(unsigned int *data, size_t allocatedVertices)
{

	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, allocatedVertices * sizeof(unsigned int), data, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_boundEbo);
	return new GlIndexBuffer(ebo);
}

orb::GlIndexBuffer::~GlIndexBuffer()
{
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_eboId);
}