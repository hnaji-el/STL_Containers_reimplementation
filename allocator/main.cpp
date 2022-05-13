
//#include "allocator.hpp"
#include <iostream>
#include <unistd.h>

//template<class T>
//void	destroy(T* ptr)
//{
//	ptr->~T();
//}
//

class Foo
{
public:
	Foo(void) 	{ std::cout << "Ctor <Foo>" << std::endl; }
	Foo(int nb) { std::cout << "Ptor <Foo>" << std::endl; }
	~Foo(void) 	{ std::cout << "Dtor <Foo>" << std::endl; }
};

template<class T>
class Bar
{
public:
	typedef	T		value_type;
	typedef T*		pointer;
	typedef size_t	size_type;
public:
	Bar(void) 	{ std::cout << "Ctor <Bar>" << std::endl; }
	~Bar(void) 	{ std::cout << "Dtor <Bar>" << std::endl; }
	pointer	allocate(size_type n);
	void	deallocate(pointer p);
};

template<class T>
typename Bar<T>::pointer	Bar<T>::allocate(size_type n)
{
	return (static_cast<pointer>(::operator new (sizeof(value_type) * n)));
}

template<class T>
void	Bar<T>::deallocate(pointer p)
{
	::operator delete (p);
}

template<class T>
T*	allocate(size_t n)
{
	return (static_cast<T*>(::operator new (sizeof(T) * n)));
}

class Sample
{
public:
	int*	ptr;
public:
	Sample(void)	{ std::cout << "Ctor <Sample>" << std::endl; }
	~Sample(void)	{ std::cout << "Ctor <Sample>" << std::endl; }
};

int	main(void)
{
	Sample	obj;

	obj.ptr = new int[2];
	obj.ptr = new int[2];
	obj.ptr = new int[2];
	obj.ptr = new int[2];
	obj.ptr = new int[2];

	system("leaks a.out");
	return (0);
}

