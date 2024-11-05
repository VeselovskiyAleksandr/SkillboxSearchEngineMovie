#include "Counter.h"

template <class T>

 struct Counter
{
 	Counter()
	{
     ++counter;
	}
	static int getCounter()
	{
	 return counter;
	}

private:
	static int counter;
};
