
#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Bar
{
private:
	int		_a;
public:
	Bar(void) : _a(0)				{ std::cout << "Default ctor [Bar]" << std::endl; }
	Bar(Bar const &)				{ std::cout << "Copy ctor [Bar]" << std::endl; }
	void	operator=(Bar const &)	{ std::cout << "Copy assignment [Bar]" << std::endl; }
	~Bar(void)						{ std::cout << "Dtor [Bar]" << std::endl; }
	Bar(int a)	: _a(a)				{ std::cout << "Int ctor [Bar]" << std::endl; }
	Bar	operator+(ptrdiff_t n) const
	{
		return (Bar(this->_a + n));
	}
};

int	main(void)
{
	ft::vector<char>				vec(4);

	std::cout << PTRDIFF_MAX << std::endl;
	std::cout << vec.max_size() << std::endl;

	return (0);
}

















































/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */



















// #define RESET   "\033[0m"
// #define RED     "\033[31m"
// #define GREEN   "\033[32m"
// 
// struct Foo
// {
// 	Foo(void)						{ std::cout << "Ctor" << std::endl; }
// 	Foo(Foo const &) 				{ std::cout << "Copy Ctor" << std::endl; }
// 	void	operator=(Foo const &) 	{ std::cout << "Copy assignment" << std::endl; }
// 	~Foo(void)						{ std::cout << "Dtor" << std::endl; }
// 
// 	Foo(int) 						{ std::cout << "Int Ctor" << std::endl; }
// };


//	std::vector<int>			vec(4);
//	std::vector<int>::iterator	it = vec.begin();
//
//	*it = 10;
//	std::cout << *it << std::endl;
//
//	it = vec.begin();

//	for (it = vec.begin(); it != vec.end(); it++)
//	{
//		*it = 10;
//		std::cout << *it << std::endl;
//	}
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
