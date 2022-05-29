
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
	std::vector<int>	a;


//	try
//	{
//		throw std::out_of_range("vector");
//	}
//	catch (std::out_of_range& e)
//	{
//		std::cout << e.what() << std::endl;
//	}

//	for (size_t i = 1; i <= 10; i++) 	{ a.push_back(i); 			}
//	for (size_t i = 0; i < 10; i++)		{ std::cout << a[i] << " "; }
//	std::cout << std::endl << a.size() << " " << a.capacity() << std::endl;
//	// [1 2 3 4 5 6 7 8 9 10]
//
//	a.resize(5);
//	std::cout << a.size() << " " << a.capacity() << std::endl;
//	// [1 2 3 4 5]
//
//	a.resize(8,100);
//	for (size_t i = 0; i < a.size(); i++)	{ std::cout << a[i] << " "; }
//	std::cout << std::endl << a.size() << " " << a.capacity() << std::endl;
//	// [1 2 3 4 5 100 100 100]
//
//	a.resize(12);
//	for (size_t i = 0; i < a.size(); i++)	{ std::cout << a[i] << " "; }
//	std::cout << std::endl << a.size() << " " << a.capacity() << std::endl;
//	// [1 2 3 4 5 100 100 100 0 0 0 0]
//	
//	a.resize(18, 3);
//	for (size_t i = 0; i < a.size(); i++)	{ std::cout << a[i] << " "; }
//	std::cout << std::endl << a.size() << " " << a.capacity() << std::endl;
//	// [1 2 3 4 5 100 100 100 0 0 0 0 3 3 3 3 3 3]

	return (0);
}

/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */

