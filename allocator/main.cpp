
#include "allocator.hpp"
#include <iostream>

struct Foo
{
	int		nb;

	Foo(void) : nb(10)
	{
		std::cout << "Ctor" << std::endl;
	}
	Foo(int const n) : nb(n)
	{
		std::cout << "Int Ctor" << std::endl;
	}
	Foo(Foo const & src) : nb(src.nb)
	{
		std::cout << "Copy ctor" << std::endl;
	}
	~Foo(void)
	{
		std::cout << "Dtor" << std::endl;
	}
};

int	main(void)
{
	ft::allocator<Foo>			allocFoo;
	ft::allocator<Foo>::pointer	ptr;

	std::cout << "------------------------------------" << std::endl;
	ptr = allocFoo.allocate(1);
	std::cout << ptr->nb << std::endl;

	std::cout << "------------------------------------" << std::endl;
	allocFoo.construct(ptr, Foo());
	std::cout << ptr->nb << std::endl;
  
	std::cout << "------------------------------------" << std::endl;
	allocFoo.destroy(ptr);

	std::cout << "------------------------------------" << std::endl;
	allocFoo.deallocate(ptr, 1);

	return (0);
}

