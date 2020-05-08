#pragma once

#include <Engine/Engine.hpp>

class TestLayer : public orb::Layer
{
public:
	TestLayer(orb::RenderTarget& target);
public:
	void onNext(orb::MouseMoveEvent& event) override;
};


