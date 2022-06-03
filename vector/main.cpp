#include "vector.hpp"
#include <iostream>
#include <vector>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

struct Foo
{
	Foo(void)						{ std::cout << "Ctor" << std::endl; }
	Foo(Foo const &) 				{ std::cout << "Copy Ctor" << std::endl; }
	void	operator=(Foo const &) 	{ std::cout << "Copy assignment" << std::endl; }
	~Foo(void)						{ std::cout << "Dtor" << std::endl; }

	Foo(int) 						{ std::cout << "Int Ctor" << std::endl; }
};

int	main(void)
{
	std::vector<Foo>	a(2, Foo());

	std::cout << a.size() << " " << a.capacity() << std::endl;

	a.resize(1);

	std::cout << a.size() << " " << a.capacity() << std::endl;

	//	std::cout << "TEST#1: std::reserve() VS ft::reserve()" << std::endl;
	//	{
	//		std::vector<Foo>	a(2, Foo(10));
	//		ft::vector<Foo>		b(2, Foo(10));

	//		for (size_t i = 1; i <= 3; i++)
	//		{
	//			a.reserve(i);
	//			b.reserve(i);
	//			if (a.size() == b.size() && a.capacity() == b.capacity())
	//				std::cout << GREEN << "OK" << RESET << std::endl;
	//			else
	//				std::cout << RED << "KO" << RESET << std::endl;
	//		}
	//	}

	return (0);
}

/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */

