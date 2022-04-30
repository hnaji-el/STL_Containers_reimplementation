
#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <memory>

namespace ft
{

template< class T, class Alloc = std::allocator<T> >
class vector
{
private:
	T*		_array;
	Alloc	_alloc;		// ATT: Why type is Alloc  ?
	size_t	size;		// ATT: Why type is size_t ?
	size_t	capacity; 	// ATT: Why type is size_t ?


public:
	// typedefs ...
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference 	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer 		const_pointer;
	typedef size_t										size_type;// ?
	// iterators + difference_type + size_type
	// ...
	
	// constructors ...
	explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _array(NULL)
	{
		;
	}

	explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

	template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

	vector(const vector& x);

};

}

#endif




























