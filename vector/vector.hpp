
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "vector_iterator.hpp"
# include "../utilities/reverse_iterator.hpp"
# include "../utilities/equal.hpp"
# include "../utilities/lexicographical_compare.hpp"
# include "../utilities/is_integral.hpp"
# include "../utilities/enable_if.hpp"
# include <iostream>
# include <memory>
# include <cstddef>
# include <algorithm>
# include <limits>
# include <exception>
# include <stdexcept>
# include <iterator>

namespace ft
{

template<class T, class Alloc = std::allocator<T> >
class vector
{
private:
	//	Data members
	T*		_array;
	Alloc	_alloc;
	size_t	_size;
	size_t	_capacity;

public:
	// 	Member types
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;
	typedef ft::vector_iterator<T>					iterator;
	typedef ft::vector_iterator<T const>			const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

public:
	// 	Constructors && Destructor
	explicit vector(const allocator_type& alloc = allocator_type());
	explicit vector(size_type n,
					value_type const & val = value_type(),
					allocator_type const & alloc = allocator_type());
	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
			allocator_type const & alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL);
	vector(vector const & x);
	~vector(void);

    // Copy assignment operator
	vector&	operator=(vector const & x);
	
	//	Iterators:
	iterator 		begin(void);
	const_iterator	begin(void) const;
	iterator		end(void);
	const_iterator	end(void) const;
	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;

	// Modifiers: [ assign ]
	template<class InputIterator>
	void	assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL);
	void	assign(size_type n, value_type const & val);
	
	// Modifiers: [ insert ]
	iterator	insert(iterator position, value_type const & val);
	void		insert(iterator position, size_type n, value_type const & val);
	template<class InputIterator>
	void		insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL);
	
	// Modifiers: [ erase ]
	iterator	erase(iterator position);
	iterator	erase(iterator first, iterator last);

	// Modifiers: [ push_back && pop_back ]
	void	push_back(value_type const & val);
	void	pop_back(void);

	// Modifiers: [ swap && clear ]
	void	swap(vector& x);
	void	clear(void);

	//	Capacity:
	size_type	size(void) const;
	size_type	max_size(void) const;
	size_type	capacity(void) const;
	bool	empty(void) const;
	void	resize(size_type n, value_type val = value_type());
	void	reserve(size_type n); /* Throw exception [std::length_error, std::bad_alloc] */

	// 	Element access:
	reference		operator[](size_type n);
	const_reference	operator[](size_type n) const;
	reference		at(size_type n); // Throw exception [std::out_of_range, std::bad_alloc]
	const_reference	at(size_type n) const; // Throw exception [std::out_of_range, std::bad_alloc]
	reference		front(void);
	const_reference	front(void) const;
	reference		back(void);
	const_reference	back(void) const;

	// Allocator:
	allocator_type	get_allocator(void) const;

private:
	// Helper member functions:
	iterator	insert_def_(iterator position, size_type n, value_type const & val);
	iterator	erase_def_(size_type const pos_index, size_type n);
	size_type	get_new_capacity(size_type n);
};

// Non-member function: swap
template<class T, class Alloc>
void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y);

// Non-member functions: Relational operators
template<class T, class Alloc>
bool	operator==(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs);
template<class T, class Alloc>
bool	operator!=(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs);
template<class T, class Alloc>
bool	operator<(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs);
template<class T, class Alloc>
bool	operator<=(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs);
template<class T, class Alloc>
bool	operator>(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs);
template<class T, class Alloc>
bool	operator>=(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs);

}

# include "vector.tpp"

#endif
