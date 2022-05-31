
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <cstddef>
# include <limits>
# include <exception>
# include <stdexcept>

namespace ft
{

template< class T, class Alloc = std::allocator<T> >
class vector
{
private:
	T*		_array;
	Alloc	_alloc;
	size_t	_size;
	size_t	_capacity;

public:
	// 	member types
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

public:
	// 	Constructors
	explicit vector(const allocator_type& alloc = allocator_type());
	explicit vector(size_type n,
					const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()
					); /* Throw exception [std::bad_alloc] */
	~vector(void);

	//	Capacity:
	size_type	size(void) const;
	size_type 	max_size(void) const;
	// void 		resize(size_type n, value_type val = value_type());
	size_type 	capacity(void) const;
	bool 		empty(void) const;
	void 		reserve(size_type n);

	// 	Element access:
	reference 		operator[](size_type n);
	const_reference operator[](size_type n) const;
	reference 		at(size_type n);
	const_reference at(size_type n) const;
	reference		front(void);
	const_reference	front(void) const;
	reference 		back(void);
	const_reference	back(void) const;

	//	Modifiers:

};

}

# include "vector.tpp"

#endif


















