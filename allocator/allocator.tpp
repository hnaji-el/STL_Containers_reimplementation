
#ifndef	ALLOCATOR_TPP
# define ALLOCATOR_TPP

namespace ft
{

/* ---------------------------------------------------------------- */
/*					Constructors && Destructor						*/
/* ---------------------------------------------------------------- */

template<class T>
allocator<T>::allocator(void) throw()
{
}

template<class T>
allocator<T>::allocator(allocator<T> const &) throw()
{
}

template<class T>
template<class U>
allocator<T>::allocator(allocator<U> const &) throw()
{
}

template<class T>
allocator<T>::~allocator(void) throw()
{
}

/* ---------------------------------------------------------------- */
/*								address								*/
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
/*							allocate								*/
/* ---------------------------------------------------------------- */

template<class T>
typename allocator<T>::pointer	allocator<T>::allocate(size_type n, void const *)
{
	return (static_cast<pointer>(::operator new (sizeof(value_type) * n)));
}

/* ---------------------------------------------------------------- */
/*							deallocate								*/
/* ---------------------------------------------------------------- */

template<class T>
void 	allocator<T>::deallocate(pointer p, size_type)
{
	::operator delete (p);
}

/* ---------------------------------------------------------------- */
/*							construct								*/
/* ---------------------------------------------------------------- */

template<class T>
void	allocator<T>::construct(pointer p, const_reference val)
{
	new (p) value_type(val);
}

/* ---------------------------------------------------------------- */
/*								destroy								*/
/* ---------------------------------------------------------------- */

template<class T>
void	allocator<T>::destroy(pointer p)
{
	p->~value_type();
}

}

#endif

