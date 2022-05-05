
#include <iostream>

template<class T>
class allocator
{
private:
	

public:
	// Member types ...
	typedef T			value_type;
	typedef T*			pointer;
	typedef const T*	const_pointer;
	typedef T&			reference;
	typedef const T*	const_reference;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;
	template<class Type>
		struct rebind
		{
			typedef allocator<Type>	other;
		}

public:
	// Constructors ...
	allocator(void) throw();
	allocator(allocator const & alloc) throw();
	template<class U>
		allocator(allocator<U> const & alloc) throw();
	
};
