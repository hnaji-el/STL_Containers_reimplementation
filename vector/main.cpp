
//#include "vector.hpp"
#include <iostream>

struct Bar
{
	Bar(void)						{ std::cout << "default Ctor [Bar]   " << std::endl; }
	Bar(int)						{ std::cout << "int Ctor [Bar]       " << std::endl; }
	Bar(Bar const &) 				{ std::cout << "copy Ctor [Bar]      " << std::endl; }
	void	operator=(Bar const &)	{ std::cout << "copy assignment [Bar]" << std::endl; }
	~Bar(void)						{ std::cout << "Dtor [Bar]           " << std::endl; }
};

struct Foo
{
	Bar		_obj;

	Foo(void) : _obj()
	{
		std::cout << "default Ctor [Foo]" << std::endl;
	}
	Foo(int) : _obj(100)
	{
		std::cout << "int Ctor [Foo]" << std::endl;
	}
	Foo(Bar const & obj = Bar()) : _obj(obj)
	{
		std::cout << "Bar Ctor [Foo]" << std::endl;
	}
	Foo(Foo const &)
	{
		std::cout << "copy Ctor [Foo]" << std::endl;
	}
	~Foo(void)
	{
		std::cout << "Dtor [Foo]" << std::endl;
	}
};

int	main(void)
{
	std::cout << "#################################" << std::endl;
	Bar		b;
	std::cout << "#################################" << std::endl;
	Foo		a(b);
	std::cout << "#################################" << std::endl;

	return (0);
}

/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */
