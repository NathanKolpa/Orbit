#include <imgui.h>
#include "TestLayer.hpp"

float data[] = {
		-0.5f, 0.5f,
		-0.5f, -0.5f,
		0.5f, 0.5f,
		0.5f, -0.5f
};

unsigned int indices[] = {
		0, 1, 2,
		1, 2, 3
};

void TestLayer::onNext(orb::KeyboardKeyEvent &event)
{
	if (event.getKey() == orb::KeyboardKey::Space)
		std::cout << "Space" << std::endl;
}

TestLayer::TestLayer(orb::Renderer2D &renderer)
		: m_renderer(renderer)
{
}

void TestLayer::render()
{
	m_vertexArray->bind();
	m_vertexArray->draw(6);
	m_vertexArray->unBind();

	m_renderer.get().beginScene();

	m_renderer.get().endScene();

	ImGui::ShowDemoWindow();
}

void TestLayer::unload()
{
	delete m_vertexArray;
}

void TestLayer::load()
{
	orb::BufferLayout layout({ orb::BufferElement(0, 2) });

	m_vertexArray = m_renderer.get().getApi().createVertexArray();

	m_vertexArray->bind();
	m_vertexBuffer = m_vertexArray->addVertexBuffer(layout, data, 4);
	m_vertexArray->setIndexBuffer(indices, 6);
	m_vertexArray->unBind();
}
