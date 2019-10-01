#pragma once

#ifdef RI_PLATFORM_WINDOWS

extern RadioInactive::Application* RadioInactive::CreateApplication();

int main(int argc, char** argv)
{
	
	retDabba->Run();

	delete retDabba;
}

#endif