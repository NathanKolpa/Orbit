#include <Engine/Core/Renderer/Renderer2D.hpp>

orb::Renderer2D::Renderer2D(orb::RenderApi &api)
		: m_renderApi(api)
{
	orb::BufferLayout layout({orb::BufferElement(0, 2)});

	m_vao = api.createVertexArray();
	m_vao->bind();

	m_vbo = m_vao->addVertexBuffer(layout, nullptr, m_maxVertices);
	m_ebo = m_vao->setIndexBuffer(nullptr, m_maxIndices);

	m_vao->unBind();
}

void orb::Renderer2D::beginScene()
{
	m_drawCalls = 0;
}

void orb::Renderer2D::endScene()
{
	flush();
}

void orb::Renderer2D::flush()
{
	if (m_indexCount != 0)
	{
		m_vbo->bind();
		m_vbo->setData(m_vertexArray, m_vertexCount);
		m_vbo->unBind();

		m_ebo->bind();
		m_ebo->setData(m_indexArray, m_indexCount);
		m_ebo->unBind();

		m_vao->bind();
		m_vao->draw(m_indexCount);
		m_vao->unBind();

		m_drawCalls++;
	}

	m_indexCount = 0;
	m_vertexCount = 0;
}

void orb::Renderer2D::drawQuad(const glm::vec2 &position, const glm::vec2 &size)
{
	if(m_indexCount > (int)m_maxIndices - 6 || m_vertexCount > (int)m_maxVertices - 4)
	{
		flush();
	}

	m_indexArray[m_indexCount + 0] = m_indexCount + 0;
	m_indexArray[m_indexCount + 1] = m_indexCount + 1;
	m_indexArray[m_indexCount + 2] = m_indexCount + 2;

	m_indexArray[m_indexCount + 3] = m_indexCount + 1;
	m_indexArray[m_indexCount + 4] = m_indexCount + 2;
	m_indexArray[m_indexCount + 5] = m_indexCount + 3;

	m_indexCount += 6;

	m_vertexArray[(m_vertexCount + 0) * m_vertexSize + 0] = -0.5f * size.x + position.x;
	m_vertexArray[(m_vertexCount + 0) * m_vertexSize + 1] = 0.5f * size.y + position.y;

	m_vertexArray[(m_vertexCount + 1) * m_vertexSize + 0] = -0.5f * size.x + position.x;
	m_vertexArray[(m_vertexCount + 1) * m_vertexSize + 1] = -0.5f * size.y + position.y;

	m_vertexArray[(m_vertexCount + 2) * m_vertexSize + 0] = 0.5f * size.x + position.x;
	m_vertexArray[(m_vertexCount + 2) * m_vertexSize + 1] = 0.5f * size.y + position.y;

	m_vertexArray[(m_vertexCount + 3) * m_vertexSize + 0] = 0.5f * size.x + position.x;
	m_vertexArray[(m_vertexCount + 3) * m_vertexSize + 1] = -0.5f * size.y + position.y;

	m_vertexCount += 4;
}

orb::RenderApi &orb::Renderer2D::getApi()
{
	return m_renderApi;
}

orb::Renderer2D::~Renderer2D()
{
	delete m_vao;
}

int orb::Renderer2D::getTotalDrawCalls() const
{
	return (int)m_drawCalls;
}
