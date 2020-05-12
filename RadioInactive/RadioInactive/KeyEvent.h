#pragma once

#include "Event.h"

#include <sstream>

namespace RadioInactive
{
	class RI_API KeyEvent : public Event
	{
	public:
		inline int GetKeyode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int KeyCode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class RI_API KeyPressedEvent : public KeyEvent
	{
	public:

	};
}