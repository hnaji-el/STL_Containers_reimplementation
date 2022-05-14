
#include "allocator.hpp"
#include <iostream>
#include <unistd.h>

int	main(void)
{
	ft::allocator<int>			allocInt;
	ft::allocator<int>::pointer	ptr;

	ptr = allocInt.allocate(2);
	ptr = allocInt.allocate(2);


	return (0);
}

