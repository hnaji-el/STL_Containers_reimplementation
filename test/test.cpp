
#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include "Test1.hpp"
#include "Test2.hpp"

//	namespace name
//	{
//	entities(classes, objects, functions)
//	}

void	foo(int& x)					{ std::cout << "int&" << std::endl; 		}
void	foo(int const & x)			{ std::cout << "int const &" << std::endl; 	}

template<class T>
class Alloc
{
private:
	T	a;

public:
	Alloc(void) 					{ std::cout << "Ctor called" << std::endl; 		}
	Alloc(Alloc<T> const & alloc) 	{ std::cout << "P Ctor called" << std::endl; 	}
	
	template<class U>
	Alloc(Alloc<U> const & alloc)	{ std::cout << "PT Ctor called" << std::endl; 	}

//	template<class Type>
//	class rebind
//	{
//	public:
//		typedef alloc<Type>	other;
//	};

};

class Foo {
private:
	int const	_a;
public:
	Foo(int const a) : _a(a) 	{ std::cout << "Ctor called" << std::endl; }
	~Foo(void) 			{ std::cout << "Dtor called" << std::endl; }

};

struct Bar
{
private:
	typedef	int	Integer;

public:
	Bar(void) 	{ std::cout << "Ctor <Bar>" << std::endl; }
	~Bar(void) 	{ std::cout << "Dtor <Bar>" << std::endl; }
	Integer		foo(Integer x);
};

Bar::Integer	Bar::foo(Bar::Integer x)
{
	std::cout << "foo" << std::endl;
	Bar::Integer	z = x;
	return (z);
}

int	main(void)
{
	std::allocator<int>				allocInt;
	std::allocator<int>::pointer	ptr;

	ptr = allocInt.allocate(4);
	allocInt.deallocate(ptr, 1);
	ptr = allocInt.allocate(4);
	system("leaks a.out");


//	std::allocator<int>				allocInt;
//	std::allocator<int>::pointer	ptr;
//	std::allocator<int>::size_type	sz;
//
//	try
//	{
//		ptr = allocInt.allocate(161168601273);
//	}
//	catch (std::exception& e)
//	{
//		std::cout << e.what() << std::endl;
//	}

//	system("leaks a.out");

//	int*	a = new int;// default initialized (gv)
//	Foo*	b = new Foo;// default initialized (default constructor)
//
//	int*	c = new int[2];// default initialized (gv, gv)
//	Foo*	d = new Foo[2];// default initialized (dc, dc)
//
//	int*	e = new int();// direct(value) initialized (zero initialized)
//	Foo*	f = new Foo();// direct(value) initialized (dc)
//	
//	int*	j = new int[2]();// direct(value) initialized (zero initialized)
//	Foo*	k = new Foo[2]();// direct(value) initialized (dc)

	return (0);
}

