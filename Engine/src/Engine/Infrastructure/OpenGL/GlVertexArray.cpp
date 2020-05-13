#include <Engine/Infrastructure/OpenGL/GlVertexArray.hpp>
#include <glad/glad.h>

unsigned int orb::GlVertexArray::s_boundVaoId = 0;

void orb::GlVertexArray::bind()
{
	s_boundVaoId = m_vaoId;
	glBindVertexArray(m_vaoId);

}

void orb::GlVertexArray::unBind()
{
	glBindVertexArray(0);
	s_boundVaoId = 0;

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

	for(auto& vbo : m_vboArray)
	{
		delete vbo;
	}
}

orb::VertexBuffer* orb::GlVertexArray::addVertexBuffer(const orb::BufferLayout &layout, float *data, size_t allocatedVertices)
{
#ifdef ORB_SAFE
	if(s_boundVaoId != m_vaoId)
	{
		throw std::runtime_error("VAO is not bound");
	}
#endif

	GlVertexBuffer* buffer = GlVertexBuffer::create(layout, data, allocatedVertices);

	m_vboArray.push_back(buffer);

	return buffer;
}

void orb::GlVertexArray::draw(int vertices)
{
#ifdef ORB_SAFE
	if(s_boundVaoId != m_vaoId)
	{
		throw std::runtime_error("VAO is not bound");
	}
#endif

	for(auto& buffers : m_vboArray)
		buffers->bindAttribs();

	glDrawArrays(GL_TRIANGLES, 0, vertices);

	for(auto& buffers : m_vboArray)
		buffers->unBindAttribs();
}
