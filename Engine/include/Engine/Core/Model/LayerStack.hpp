#pragma once
#include <Engine/Core/pch.hpp>
#include "Layer.hpp"

namespace orb
{
	class LayerStack
	{
	public:
		Layer& pushLayer(RenderTarget& target);
		void popLayer();
	public:
		typedef typename std::vector<Layer>::iterator iterator;
		typedef typename std::vector<Layer>::const_iterator const_iterator;

		iterator begin() {return m_stack.begin();}
		[[nodiscard]] const_iterator begin() const {return m_stack.begin();}
		[[nodiscard]] const_iterator cbegin() const {return m_stack.cbegin();}
		iterator end() {return m_stack.end();}
		[[nodiscard]] const_iterator end() const {return m_stack.end();}
		[[nodiscard]] const_iterator cend() const {return m_stack.cend();}
	private:
		std::vector<Layer> m_stack;
	};
}
