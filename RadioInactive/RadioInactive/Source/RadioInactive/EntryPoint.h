#pragma once

#ifdef RI_PLATFORM_WINDOWS 

extern RadioInactive::Application* RadioInactive::CreateApplication();

int main(int argc, char** argv)
{
	printf("Activated RadioInactive!");
	auto app = RadioInactive::CreateApplication();
	app->Run();
	delete app;
}

#endif
