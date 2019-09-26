#pragma once

#include "Core.h"

namespace RadioInactive
{
	class __declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};
}
