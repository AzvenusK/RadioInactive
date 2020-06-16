#include "RIPCH.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

#include "include/GLFW/glfw3.h"

namespace RadioInactive
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create()); 
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		RI_CORE_INFO("{0}", e);
	}

	void Application::Run()
	{
		
		//WindowResizeEvent e(1280, 720);
		//if (e.IsInCategory(EventCategoryApplication))
		//{
		//	RI_TRACE(e);
		//}
		//if (e.IsInCategory(EventCategoryInput))
		//{
		//	RI_TRACE(e);
		//}

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT); 
			m_Window->OnUpdate();
		}
	}
}