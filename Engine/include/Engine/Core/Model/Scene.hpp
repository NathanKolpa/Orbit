#pragma once
#include "LayerStack.hpp"

namespace orb
{
	class Scene
	{
	public:
		bool shouldRun() const;
		void load();
		void unload();

		LayerStack& getLayers();
	private:
		LayerStack m_layerStack;
	};
}