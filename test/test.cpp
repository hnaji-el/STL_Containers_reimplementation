
#include <iostream>
#include <vector>
#include "Test1.hpp"
#include "Test2.hpp"

//	namespace name
//	{
//	entities(classes, objects, functions)
//	}

//namespace
//{
//	int		a;
//}
//
//namespace
//{
//	int		b;
//}

int	main(void)
{
	std::vector<int>	a(2);

	std::cout << a.size() << " " << a.capacity() << std::endl;

	a.isert(3);

	std::cout << a.size() << " " << a.capacity() << std::endl;

	return (0);
}
