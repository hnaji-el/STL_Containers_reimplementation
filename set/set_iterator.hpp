
#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

# include "rb_tree.hpp"
# include "node.hpp"
# include <cstddef>

namespace ft
{

template<class T, class RbTree>
class set_iterator
{
private:
	node<T> const *	_ptr; // the address of a node that the iterator points to.
	RbTree const *	_rb_ptr; // pointer to rb_tree object in order to reach to its root (updated root).

public:
	//	Member types
	typedef T								value_type;
	typedef T const *						pointer;
	typedef T const &						reference;
	typedef ptrdiff_t						difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;

public:
	//	Constructors && Destructor
	set_iterator(void);
	set_iterator(set_iterator const & src);
	set_iterator&	operator=(set_iterator const & rhs);
	~set_iterator(void);

	set_iterator(node<T> const * ptr, RbTree const * rb_ptr);

	//	Increment && Decrement operators
	set_iterator&	operator++(void);
	set_iterator	operator++(int);
	set_iterator&	operator--(void);
	set_iterator	operator--(int);

	//	Comparison operators
	bool	operator==(set_iterator const & rhs) const;
	bool	operator!=(set_iterator const & rhs) const;

	//	Dereferencing operators
	reference	operator*(void) const;
	pointer		operator->(void) const;
};

}

# include "set_iterator.tpp"

#endif
