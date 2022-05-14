
#include "RAIIptr.hpp"
#include "Resource.hpp"
#include <iostream>

int	main(void)
{
	{
		int*	a = new int;
	}
	try
	{
		RAIIptr<Resource>	obj(new Resource);
		obj.getPtr()->unsafeFunction();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

