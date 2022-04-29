
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
	std::vector<int>	a;

	std::cout << a.size() << " " << a.capacity() << std::endl;


	return (0);
}
