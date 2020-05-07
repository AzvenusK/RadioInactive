#pragma once

#include "Source/RadioInactive/Core.h"

#include <string>
#include <functional>

namespace RadioInactive
{
	//Events in RadioInactive are currently blocking, meaning when an event occurs it 
	//immediately gets dispatched and must be dealt with right then and there.
	//For the future, a better strategy might be to buffer events in a n event 
	//bus and process them during the "event" part of the update stage.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};
}