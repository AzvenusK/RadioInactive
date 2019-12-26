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

int main()
{
	RetDabba* retDabba = new RetDabba();
	retDabba->Run();
	delete retDabba;
}