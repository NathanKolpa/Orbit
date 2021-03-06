#ifdef ORB_OPENGL

#include <Engine/Infrastructure/RenderApi/OpenGL/Buffer/GlVertexBuffer.hpp>
#include <utility>
#include <glad/glad.h>

unsigned int orb::GlVertexBuffer::s_boundVboId = 0;

void orb::GlVertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
	s_boundVboId = m_vboId;
}

void orb::GlVertexBuffer::unBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	s_boundVboId = 0;
}

void orb::GlVertexBuffer::setData(float *data, size_t vertices)
{
#ifdef ORB_SAFE
	if(s_boundVboId != m_vboId)
	{
		throw std::runtime_error("VBO is not bound");
	}
#endif

	glBufferSubData(GL_ARRAY_BUFFER, 0, vertices * m_vertexSize, (void*)data);
}

orb::GlVertexBuffer::~GlVertexBuffer()
{
	glDeleteBuffers(1, &m_vboId);
}

orb::GlVertexBuffer::GlVertexBuffer(unsigned int vboId, std::vector<int> attribArray, int vertexSize)
		: m_attribArray(std::move(attribArray)), m_vboId(vboId), m_vertexSize(vertexSize)
{

}

orb::GlVertexBuffer *orb::GlVertexBuffer::create(const BufferLayout& layout, float *data, size_t allocatedVertices)
{
	unsigned int vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, allocatedVertices * layout.getTotalSizeInBytes(), data, GL_DYNAMIC_DRAW);

	std::vector<int> attribs;
	int offset = 0;

	for(auto element : layout.getElements())
	{
		glVertexAttribPointer(element.getElementIndex(), element.getElementCount(), GL_FLOAT, GL_FALSE, element.getSizeInBytes(), (void*)offset);

		offset += element.getSizeInBytes();

		attribs.push_back(element.getElementIndex());
	}

	glBindBuffer(GL_ARRAY_BUFFER, s_boundVboId);
	return new GlVertexBuffer(vbo, attribs, layout.getTotalSizeInBytes());
}

void orb::GlVertexBuffer::bindAttribs()
{
	for(auto& attrib : m_attribArray)
		glEnableVertexAttribArray(attrib);
}

void orb::GlVertexBuffer::unBindAttribs()
{
	for(auto& attrib : m_attribArray)
		glDisableVertexAttribArray(attrib);
}

#endif