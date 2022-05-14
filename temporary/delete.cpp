
#include <iostream>
#include <exception>
#include <cstdlib>
#include <new>

class Foo {
public:
	int	const	_nb;
public:
	Foo(void) : _nb(10)			{ std::cout << "Ctor called" << std::endl;		}
	Foo(int const nb) : _nb(nb)	{ std::cout << "Int ctor called" << std::endl; 	}
	~Foo(void) 					{ std::cout << "Dtor called" << std::endl; 		}
	void	operator delete (void* ptr) throw()
	{
		std::cout << "member deallocation function(1)" << std::endl;
	}
};

class Bar {
public:
	int		_nb;
public:
	Bar(void) : _nb(10)
	{
		std::cout << "Ctor called" << std::endl;
		if (this->_nb == 10)
			throw std::exception();
	}
	Bar(int const nb) : _nb(nb)
	{
		std::cout << "Int ctor called" << std::endl;
		if (this->_nb == 100)
			throw std::exception();
	}
	~Bar(void)
	{
		std::cout << "Dtor called" << std::endl;
	}

	void	operator delete (void* ptr) throw()
	{
		std::cout << "Member deallocation function(1)" << std::endl;
	}

	void	operator delete (void* ptr, std::nothrow_t const & nothrow_constant) throw()
	{
		std::cout << "Member deallocation function(2)" << std::endl;
	}
};

//void	operator delete (void* ptr) throw()
//{
//	std::cout << "Global deallocation function(1)" << std::endl;
//}
//
//void	operator delete (void* ptr, std::nothrow_t const & nothrow_constant) throw()
//{
//	std::cout << "Global deallocation function(2)" << std::endl;
//}

int	main(void)
{
	int*	a = (int*) operator new (sizeof(int));

	operator delete (a, NULL);
	operator delete (a, NULL);
	a = (int*) operator new (sizeof(int));
	system("leaks a.out");
//	try
//	{
//		Bar*	a = ::new Bar;
//	}
//	catch (std::exception& e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//	std::cout << " ---------------------------------------- " << std::endl;
//	try
//	{
//		Bar*	a = new (std::nothrow) Bar;
//	}
//	catch (std::exception& e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//	std::cout << " ----------------------------------------- " << std::endl;
//	try
//	{
//		Bar		a;
//		new (&a) Bar(100);
//	}
//	catch (std::exception& e)
//	{
//		std::cout << e.what() << std::endl;
//	}

	return (0);
}
















