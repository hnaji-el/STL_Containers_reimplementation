
#include "vector.hpp"
#include <iostream>
#include <vector>

struct Foo
{
	Foo(void)						{ std::cout << "Ctor" << std::endl; }
	Foo(Foo const &) 				{ std::cout << "Copy Ctor" << std::endl; }
	void	operator=(Foo const &) 	{ std::cout << "Copy assignment" << std::endl; }
	~Foo(void)						{ std::cout << "Dtor" << std::endl; }
};

int	main(void)
{
	std::vector<int>	*a = new std::vector<int>();

	a[0] = 100;
//	Foo		obj;
//
//	std::cout << "-----------" << std::endl;
//	ft::vector<Foo>	a(5, obj);
//	std::cout << a.size() << std::endl;
//	std::cout << a.capacity() << std::endl;
//	std::cout << "-----------" << std::endl;
//	a.resize(3);
//	std::cout << "-----------" << std::endl;
//	std::cout << a.size() << std::endl;
//	std::cout << a.capacity() << std::endl;
//	std::cout << "-----------" << std::endl;

	return (0);
}

/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */

