#pragma once

#include <Engine/Core/Model/RenderTarget.hpp>
#include <Engine/Core/Model/Window/GameWindow.hpp>
#include <Engine/Core/Model/Events/EventEmitter.hpp>
#include <Engine/Core/Model/Input/KeyboardKeyEvent.hpp>
#include <Engine/Core/Model/Input/MouseMoveEvent.hpp>
#include "GlfwKeyMapper.hpp"
#include "GlfwInputTypeMapper.hpp"

struct GLFWwindow;

namespace orb
{
	class GlfwGameWindow : public GameWindow, public RenderTarget
	{
	public:
		static GlfwGameWindow createGlfwWindow(int width, int height, const char* title);
		static void initLibrary();
		static void destroyLibrary();
	public:
		~GlfwGameWindow();
	public:
		void pollEvents() override;
		bool isOpen() override;
		void display() override;

		void clear() override;
		void bindContext() override;
		void unbindContext() override;

		int getWidth() override;
		int getHeight() override;

		Observable<KeyboardKeyEvent>& getKeyboardKeyObservable();
		Observable<MouseMoveEvent>& getMouseMoveObservable();
	private:
		GlfwGameWindow(GLFWwindow* window, int width, int height, const char* title);
	private:
		GLFWwindow* m_window;
		int m_width, m_height;
		std::string m_title;

		EventEmitter<KeyboardKeyEvent> m_keyboardKeyEmitter;
		EventEmitter<MouseMoveEvent> m_mouseMoveEmitter;

		GlfwKeyMapper m_keyMapper;
		GlfwInputTypeMapper m_inputTypeMapper;
	};
}