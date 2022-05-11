
#include "allocator.hpp"
#include <iostream>

int	main(void)
{
	ft::allocator<int>			allocInt;
	ft::allocator<int>::pointer	ptr;
	
	ptr = allocInt.allocate(2);
	allocInt.construct(ptr, 10);
	allocInt.construct(ptr + 1, 20);
	std::cout << ptr[0] << std::endl;
	std::cout << ptr[1] << std::endl;
	allocInt.destroy(ptr);
	return (0);
}

