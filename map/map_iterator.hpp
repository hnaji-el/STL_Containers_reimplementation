
#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <cstddef>
# include "avl_node.hpp"

namespace ft
{

template<class T, class AvlNode, class AvlTree>
class map_iterator
{
private:
	AvlTree*	_avl_ptr;
	AvlNode*	_ptr;

public:
	//	Member types
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;

public:
	//	Constructors && Destructor
	map_iterator(void);
	map_iterator(map_iterator const & src);
	map_iterator&	operator=(map_iterator const & rhs);
	~map_iterator(void);

	map_iterator(AvlTree* avl_ptr, AvlNode* ptr);

	// Conversion function (make iterator convertible to const_iterator)
	operator map_iterator<T const, AvlNode const, AvlTree const>() const;

	//	Increment && Decrement operators
	map_iterator&	operator++(void);
	map_iterator	operator++(int);
	map_iterator&	operator--(void);
	map_iterator	operator--(int);

	//	Comparison operators
	bool	operator==(map_iterator const & rhs) const;
	bool	operator!=(map_iterator const & rhs) const;

	//	Dereferencing operators
	reference	operator*(void) const;
	pointer		operator->(void) const;
};

}

# include "map_iterator.tpp"

#endif
