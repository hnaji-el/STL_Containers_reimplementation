
#include "allocator.hpp"

namespace ft
{

/* ---------------------------------------------------------------- */
/*                  Constructors && Destructor						*/
/* ---------------------------------------------------------------- */

template<class T>
allocator<T>::allocator(void) throw()
{
}

template<class T>
allocator<T>::allocator(allocator const & alloc) throw()
{
}

template<class T>
template<class U>
allocator<T>::allocator(allocator<U> const & alloc) throw()
{
}

template<class T>
allocator<T>::~allocator(void) throw()
{
}

/* ---------------------------------------------------------------- */
/*                         	  address								*/
/* ---------------------------------------------------------------- */

template<class T>
allocator<T>::pointer	allocator<T>::address(allocator<T>::reference x) const
{
	return (&x);
}

template<class T>
allocator<T>::const_pointer	allocator<T>::address(allocator<T>::const_reference x) const
{
	return (&x);
}

/* ---------------------------------------------------------------- */
/*                        	 allocate								*/
/* ---------------------------------------------------------------- */

template<class T>
allocator<T>::pointer allocator<T>::allocate(allocator<T>::size_type n, void const * hint=0)
{
	allocator<T>::pointer	ptr;

	ptr = static_cast<allocator<T>::pointer>(::operator new (sizeof(value_type) * n));
	return (ptr);
}

/* ---------------------------------------------------------------- */
/*                        	 deallocate								*/
/* ---------------------------------------------------------------- */

template<class T>
void 	allocator<T>::deallocate(allocator<T>::pointer p, allocator<T>::size_type n)
{
	::operator delete (p);
}

}




























