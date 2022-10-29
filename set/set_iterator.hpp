
#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

# include "rb_tree.hpp"
# include "node.hpp"
# include <cstddef>

namespace ft
{

template<class T, class Node, class RbTree>
class set_iterator
{
private:

public:
	Node*	_ptr; // the address of a node that the iterator points to.
	RbTree*	_rb_ptr; // pointer to rb_tree object in order to reach to its root (updated root).
	//	Member types
	typedef T								value_type;
	typedef T const *						pointer;
	typedef T const &						reference;
	typedef ptrdiff_t						difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;

public:
	//	Constructors && Destructor
	set_iterator(void);
	template<class U, class E, class F>
	set_iterator(set_iterator<U, E, F> const & src);
	set_iterator&	operator=(set_iterator const & rhs);
	~set_iterator(void);

	set_iterator(Node* ptr, RbTree* rb_ptr);

	// Conversion function (make iterator convertible to const_iterator)
	// operator set_iterator<T const, Node const, RbTree const>() const;

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
