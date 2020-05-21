#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace RadioInactive
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			RI_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			RI_TRACE(e);
		}

		while (true);
	}
}