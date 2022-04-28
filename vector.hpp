
#ifndef VECTOR_H
# define VECTOR_H

# include <memory>

namespace ft
{

template< class T, class Alloc = std::allocator<T> >
class vector
{
private:
	T*	_array;

public:
	// typedefs ...
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference 	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer 		const_pointer;
	// iterators + difference_type + size_type ...

};

}

#endif
