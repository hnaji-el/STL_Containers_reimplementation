
#include "Classes.hpp"
#include "Classes.tpp"
#include <iostream>

int	main(void)
{
	Temp<int>	a;
	int	b = 10;
	std::cout << a.test(&b) << std::endl;
	return (0);
}

