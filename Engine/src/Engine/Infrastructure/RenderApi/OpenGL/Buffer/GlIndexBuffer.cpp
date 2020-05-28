#ifdef ORB_OPENGL

#include <Engine/Infrastructure/RenderApi/OpenGL/Buffer/GlIndexBuffer.hpp>
#include <glad/glad.h>
#include <stdexcept>

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
#ifdef ORB_SAFE
	if(s_boundEbo != m_eboId)
	{
		throw std::runtime_error("EBO is not bound");
	}
#endif

	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices * sizeof(unsigned int), (void*)data);
}

orb::GlIndexBuffer::GlIndexBuffer(unsigned int eboId)
	:m_eboId(eboId)
{

}

orb::GlIndexBuffer::~GlIndexBuffer()
{
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_eboId);
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

#endif