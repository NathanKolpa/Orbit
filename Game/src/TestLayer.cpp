#include "TestLayer.hpp"

void TestLayer::onNext(orb::MouseMoveEvent& event)
{
	std::cout << "yeet";
}

TestLayer::TestLayer(orb::RenderTarget &target) : Layer(target)
{

}
