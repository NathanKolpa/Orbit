#include <Engine/Engine.hpp>

int main()
{
	orb::Application app;

	orb::Scene scene;
	app.getLoop().runScene(scene);
}