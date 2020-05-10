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
		orb::BufferElement(2)
	});

	m_vertexArray = m_renderer.get().getApi().createVertexArray();
}
