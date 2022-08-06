
#include "vector.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

typedef std::vector<int>::iterator					Iterator;
typedef std::vector<int>::const_iterator			CIterator;
typedef std::vector<int>::reverse_iterator			RIterator;
typedef std::vector<int>::const_reverse_iterator	CRIterator;

typedef ft::vector<int>::iterator					Iteratorr;
typedef ft::vector<int>::const_iterator				CIteratorr;
typedef ft::vector<int>::reverse_iterator			RIteratorr;
typedef ft::vector<int>::const_reverse_iterator		CRIteratorr;

int	main(void)
{
	int*	ptr = new int;
	ft::vector<int>		vec(4);
	Iteratorr			it = ptr;
	return (0);
}


class Outer
{
public:
	class Inner
	{
	public:
		Inner(void)							{ std::cout << "Default ctor [Inner]" << std::endl; }
		Inner(Inner const &)				{ std::cout << "Copy ctor [Inner]" << std::endl; }
		void	operator=(Inner const &)	{ std::cout << "Copy assignment operator [Inner]" << std::endl; }
		~Inner(void)						{ std::cout << "Dtor [Inner]" << std::endl; }
	private:
		void	display(void)				{ std::cout << "The message from the Inner class" << std::endl; }
	};

public:
	Outer(void)							{ std::cout << "Default ctor [Outer]" << std::endl; }
	Outer(Outer const &)				{ std::cout << "Copy ctor [Outer]" << std::endl; }
	void	operator=(Outer const &)	{ std::cout << "Copy assignment operator [Outer]" << std::endl; }
	~Outer(void)						{ std::cout << "Dtor [Outer]" << std::endl; }

	void	display(void)				{ std::cout << "The message from the Outer class" << std::endl; }
};

/*
 * vector_iterator<T>(void);   -------> public
 * vector_iterator<T>(T* ptr); -------> private
 */

// int	main(void)
// {

#if 0
	std::vector<int>	vec(4);

	CRIterator	a(vec.begin());
	RIterator	b(vec.begin());
	RIterator	b = a;
	RIterator	c(a);

	b = a;
#endif

#if 0
	std::vector<int>	vec(4);

	RIterator	a(vec.begin());
	CRIterator	b = a;
	CRIterator	c(a);

	c = a;
#endif

#if 0
	std::vector<int>	vec(4);

	CIterator	a = vec.begin();
	Iterator	b = a; // no viable conversion
	Iterator	c(a);  // no viable conversion

	c = a;		       // no viable conversion
#endif

#if 0
	std::vector<int>	vec(4);

	Iterator	a = vec.begin();
	CIterator	b = a;
	CIterator	c(a);

	c = a;
#endif

// 	return (0);
// }

/*
 * 			  iterator
 * 1/ Constructors:
 * iterator <----------- void
 * iterator <----------- pointer
 * iterator <----------- iterator
 *
 * 2/ Copy Assignment operator:
 * iterator <----------- iterator
 */
/*
 * 			  const_iterator
 * 1/ Constructors:
 * const_iterator <----------- void
 * const_iterator <----------- pointer
 * const_iterator <----------- const_iterator
 * const_iterator <----------- iterator // NOTE: ...
 *
 * 2/ Copy Assignment operator:
 * const_iterator <----------- const_iterator
 * const_iterator <----------- iterator // NOTE: ...
 */


/*
 *        reverse_iterator
 * 1/ Constructors:
 * reverse_iterator <-------- void
 * reverse_iterator <-------- iterator [explicitly]
 * reverse_iterator <-------- reverse_iterator
 * reverse_iterator <-------- reverse_iterator...
 *
 * 2/ Copy assignment operator:
 * reverse_iterator <-------- reverse_iterator
 * reverse_iterator <-------- reverse_iterator...
 */



#if 0

template<class T>
class Foo
{
private:
	T*	_ptr;

public:
	Foo(T* ptr = NULL) : _ptr(ptr)		{ std::cout << "Default ctor [Foo]" << std::endl; }
	Foo(Foo<T> const &)					{ std::cout << "Copy ctor [Foo]" << std::endl; }
	void	operator=(Foo<T> const &) 	{ std::cout << "Copy assignment operator [Foo]" << std::endl; }
	~Foo(void)							{ std::cout << "Dtor [Foo]" << std::endl; }
};

class Bar
{
private:
	int		_a;
public:
	/*         Coplien form         */
	Bar(void) : _a(0)				{ std::cout << "Default ctor [Bar]" << std::endl; }		// non-converting constructor
	Bar(Bar const &)				{ std::cout << "Copy ctor [Bar]" << std::endl; }		// converting constructor
	// Bar(Test const &)				{ std::cout << "converting constructor [Bar]" << std::endl; }		// converting constructor
	void	operator=(Bar const &)	{ std::cout << "Copy assignment [Bar]" << std::endl; }
	~Bar(void)						{ std::cout << "Dtor [Bar]" << std::endl; }
	/* ---------------------------- */

	Bar(int a)	: _a(a)				{ std::cout << "Int ctor [Bar]" << std::endl; }			// converting constructor
};


#endif

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
