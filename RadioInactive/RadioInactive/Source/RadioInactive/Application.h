#pragma once
#include "Core.h"

namespace RadioInactive
{
	class RI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

}