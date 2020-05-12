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
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type)		static	EventType	GetStsaticType()					{return EvnetType::##type;}\
									virtual EventType	GetEventType()		const override	{return GetStaticType();}\
									virtual	const char*	GetName()			const override	{return #type;}

#define EVENT_CATEGORY(CATEGORY)	virtual	int			GetCategoryFlags()	const override	{return category;}

	class RI_API Event
	{
		friend class EventDispatcher;
	public:
		virtual	EventType	GetEventType()		const = 0;
		virtual const char* GetName()			const = 0;
		virtual	int			GetCategoryFlags()	const = 0;
		virtual	std::string	ToString()			const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	
	};
}