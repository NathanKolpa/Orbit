#include "TestLayer.hpp"

TestLayer::TestLayer(orb::RenderTarget &target) : Layer(target)
{

}

void TestLayer::onNext(orb::KeyboardKeyEvent &event)
{
	if (event.getKey() == orb::KeyboardKey::Space)
		std::cout << "Space";
}
