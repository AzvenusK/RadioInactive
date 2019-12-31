#include <RadioInactive.h>

class RetDabba : public RadioInactive::Application
{
public:
	RetDabba()
	{

	}

	~RetDabba()
	{

	}
};

RadioInactive::Application* RadioInactive::CreateApplication()
{
	return new RetDabba();
}