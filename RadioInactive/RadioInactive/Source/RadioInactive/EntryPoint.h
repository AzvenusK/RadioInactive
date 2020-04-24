#pragma once

#ifdef RI_PLATFORM_WINDOWS 

extern RadioInactive::Application* RadioInactive::CreateApplication();

int main(int argc, char** argv)
{
	RadioInactive::Log::Init();
	RI_CORE_WARN("Initializing...");
	int a = 100;
	RI_INFO("Progress {0}%",a);

	
	printf("Activated RadioInactive!");
	auto app = RadioInactive::CreateApplication();
	app->Run();
	delete app;
}

#endif
