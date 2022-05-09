
#include "allocator.hpp"
#include "allocator.tpp"
#include <iostream>

struct Foo
{
	int		_nb;

	Foo(int nb) : _nb(nb) 	{ std::cout << "Ctor" << std::endl; }
	~Foo(void)				{ std::cout << "Dtor" << std::endl; }
};

int	main(void)
{
	ft::allocator<int>			allocInt;
	ft::allocator<int>::pointer	ptr;

	ptr = allocInt.allocate(2);
//	allocInt.deallocate(ptr, 2);
	ptr = allocInt.allocate(2);
	ptr = allocInt.allocate(2);

	system("leaks a.out");
	return (0);
}

