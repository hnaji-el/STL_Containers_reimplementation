
#ifndef ALLOCATOR_H
# define ALLOCATOR_H

#include <iostream>

namespace ft
{

template<class T>
class allocator
{
public:
	// Member types ...
	typedef T			value_type;
	typedef T*			pointer;
	typedef T const *	const_pointer;
	typedef T&			reference;
	typedef T const &	const_reference;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;
	template<class Type>
		struct rebind
		{
			typedef allocator<Type>	other;
		}

public:
	// Constructors
	allocator(void) throw();
	allocator(allocator const & alloc) throw();
	template<class U>
		allocator(allocator<U> const & alloc) throw();
	// Destructor
	~allocator(void) throw();
	// Address
	pointer			address(reference x) 		const;
	const_pointer	address(const_reference x) 	const;
	// allocate
	pointer allocate(size_type n, void const * hint = 0);// Throw std::bad_alloc
	// deallocate
	void 	deallocate(pointer p, size_type n);

	
	
};

}

#endif

