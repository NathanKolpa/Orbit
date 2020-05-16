#ifdef ORB_DEBUG
#include <imgui.h>
#endif

#include "TestLayer.hpp"

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
	m_renderer.get().beginScene();

	m_renderer.get().drawQuad({ m_xOffset, m_yOffset }, {1, 1});

	m_renderer.get().endScene();

#ifdef ORB_DEBUG
	ImGui::Begin("Test");

	ImGui::SliderFloat("X offset", &m_xOffset, -1, 1);
	ImGui::SliderFloat("Y offset", &m_yOffset, -1, 1);

	ImGui::End();

	ImGui::ShowMetricsWindow();
#endif
}

void TestLayer::unload()
{
//	delete m_vertexArray;
}

void TestLayer::load()
{
//	orb::BufferLayout layout({ orb::BufferElement(0, 2) });
//
//	m_vertexArray = m_renderer.get().getApi().createVertexArray();
//
//	m_vertexArray->bind();
//	m_vertexBuffer = m_vertexArray->addVertexBuffer(layout, nullptr, 4);
//	m_indexBuffer = m_vertexArray->setIndexBuffer(indices, 6);
//	m_vertexArray->unBind();
}
