#include "Application.h"

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
		while (true);
	}

	// To be defined in CLIENT.
	Application* CreateApplication();
}