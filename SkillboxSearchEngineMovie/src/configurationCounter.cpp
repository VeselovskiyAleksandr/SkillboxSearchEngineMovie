#include "configurationCounter.h"

template <class T>

 struct configurationCounter
{
	 configurationCounter()
	{
     ++counter;
	}
	static int getConfigurationCounter()
	{
	 return counter;
	}

private:
	static int counter;
};
