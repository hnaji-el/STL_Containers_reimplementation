
#include "vector.hpp"
#include <iostream>
#include <vector>

struct Foo
{
	Foo(void)	{ std::cout << "Ctor" << std::endl; }
	Foo(Foo const &)	{ std::cout << "copy Ctor" << std::endl; }
	~Foo(void)	{ std::cout << "Dtor" << std::endl; }
};

int	main(void)
{
	ft::vector<Foo>	vecOfFoo(10, Foo());

//	std::cout << vecOfFoo.size() << std::endl;
//	std::cout << vecOfFoo.capacity() << std::endl;


	return (0);
}

/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */

