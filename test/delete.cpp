
#include <iostream>
#include <cstdlib>
#include <new>

class Foo {
public:
	int	const	_nb;
public:
	Foo(void) : _nb(10)			{ std::cout << "Ctor called" << std::endl;	}
	Foo(int const nb) : _nb(nb)	{ std::cout << "Int ctor called" << std::endl; }
	~Foo(void) 					{ std::cout << "Dtor called" << std::endl; 	}
};

int	main(void)
{
	/*
	 * 1. ORDINARY DELETE
	 * void	operator delete	  (void* ptr) throw();
	 * void	operator delete[] (void* ptr) throw();
	 */
	Foo*	ptr = (Foo*)malloc(sizeof(Foo) * 3);
	operator delete (ptr, std::nothrow);
	ptr = (Foo*)malloc(sizeof(Foo) * 3);

	system("leaks a.out");

	return (0);
}

