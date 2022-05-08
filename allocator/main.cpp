
//#include "allocator.hpp"
//#include "allocator.tpp"
#include <iostream>
#include <memory>

struct Foo
{
	int		_nb;

	Foo(int nb) : _nb(nb) 	{ std::cout << "Ctor" << std::endl; }
	~Foo(void)				{ std::cout << "Dtor" << std::endl; }
};

int	main(void)
{
	std::allocator<Foo>				allocFoo;
	std::allocator<Foo>::pointer	ptr;

	ptr = allocFoo.allocate(1);
	(*ptr).~Foo();
//	allocInt.construct(ptr, 10);
//	allocInt.construct(10);

	return (0);
}

