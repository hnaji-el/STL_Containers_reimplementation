
#ifndef	ALLOCATOR_TPP
# define ALLOCATOR_TPP

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
allocator<T>::allocator(allocator<T> const & alloc) throw()
{
	(void)alloc;
}

template<class T>
template<class U>
allocator<T>::allocator(allocator<U> const & alloc) throw()
{
	(void)alloc;
}

template<class T>
allocator<T>::~allocator(void) throw()
{
}

/* ---------------------------------------------------------------- */
/*                         	  address								*/
/* ---------------------------------------------------------------- */

template<class T>
typename allocator<T>::pointer	allocator<T>::address(reference x) const
{
	return (&x);
}

template<class T>
typename allocator<T>::const_pointer	allocator<T>::address(const_reference x) const
{
	return (&x);
}

/* ---------------------------------------------------------------- */
/*                        	 allocate								*/
/* ---------------------------------------------------------------- */

template<class T>
typename allocator<T>::pointer	allocator<T>::allocate(size_type n, void const * hint)
{
	(void)hint;
	return (static_cast<pointer>(::operator new (sizeof(value_type) * n)));
}

/* ---------------------------------------------------------------- */
/*                        	 deallocate								*/
/* ---------------------------------------------------------------- */

template<class T>
void 	allocator<T>::deallocate(pointer p, size_type n)
{
	(void)n;
	::operator delete (p);
}

/* ---------------------------------------------------------------- */
/*                        	 construct								*/
/* ---------------------------------------------------------------- */

template<class T>
void	allocator<T>::construct(pointer p, const_reference val)
{
	new (p) value_type(val);
}

/* ---------------------------------------------------------------- */
/*                        	 destroy								*/
/* ---------------------------------------------------------------- */

template<class T>
void	allocator<T>::destroy(pointer p)
{
	p->~value_type();
}

}

#endif

