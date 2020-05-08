#pragma once
#include <Engine/Core/pch.hpp>
#include "Layer.hpp"
#include "Events/Observer.hpp"
#include "Input/MouseMoveEvent.hpp"

namespace orb
{
	class LayerStack : public Observer<MouseMoveEvent>
	{
	public:
		void pushLayer(Layer& layer);
		void popLayer();

		void onNext(MouseMoveEvent &event) override;
	public:
		typedef typename std::vector<std::reference_wrapper<Layer>>::iterator iterator;
		typedef typename std::vector<std::reference_wrapper<Layer>>::const_iterator const_iterator;

		iterator begin() {return m_stack.begin();}
		[[nodiscard]] const_iterator begin() const {return m_stack.begin();}
		[[nodiscard]] const_iterator cbegin() const {return m_stack.cbegin();}
		iterator end() {return m_stack.end();}
		[[nodiscard]] const_iterator end() const {return m_stack.end();}
		[[nodiscard]] const_iterator cend() const {return m_stack.cend();}

	private:
		template<typename T>
		void passEvent(T& event)
		{
			for (int i = m_stack.size() - 1; i >= 0; --i)
			{
				m_stack[i].get().onNext(event);

				if(event.isConsumed())
				{
					break;
				}
			}
		}
	private:
		std::vector<std::reference_wrapper<Layer>> m_stack;
	};
}
