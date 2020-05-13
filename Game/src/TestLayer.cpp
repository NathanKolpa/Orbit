#include "TestLayer.hpp"

float data[] = {
		-0.5f, 0.5f,
		-0.5f, -0.5f,
		0.5f, 0.5f
};


void TestLayer::onNext(orb::KeyboardKeyEvent &event)
{
	if (event.getKey() == orb::KeyboardKey::Space)
		std::cout << "Space";
}

TestLayer::TestLayer(orb::Renderer2D &renderer)
	:m_renderer(renderer)
{
}

void TestLayer::render()
{

	m_vertexBuffer->bind();
	m_vertexBuffer->setData(data, sizeof(data));
	m_vertexBuffer->unBind();

	m_vertexArray->bind();
	m_vertexArray->draw(3);
	m_vertexArray->unBind();

	m_renderer.get().beginScene();

	m_renderer.get().endScene();
}

void TestLayer::unload()
{
	delete m_vertexArray;
}

void TestLayer::load()
{
	orb::BufferLayout layout({
		orb::BufferElement(0, 2)
	});

	m_vertexArray = m_renderer.get().getApi().createVertexArray();

	m_vertexArray->bind();
	m_vertexBuffer = m_vertexArray->addVertexBuffer(layout, nullptr, 3);
	m_vertexArray->unBind();
}
