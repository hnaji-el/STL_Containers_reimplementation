
#ifndef SET_ITERATOR_TPP
# define SET_ITERATOR_TPP

namespace ft
{

/*
 * Constructors && Destructor
 */

template<class T, class Node, class RbTree>
set_iterator<T, Node, RbTree>::set_iterator(void)
	: _ptr(), _rb_ptr()
{
}

template<class T, class Node, class RbTree>
set_iterator<T, Node, RbTree>::set_iterator(Node* ptr, RbTree* rb_ptr)
	: _ptr(ptr), _rb_ptr(rb_ptr)
{
}

template<class T, class Node, class RbTree>
template<class U, class E, class F>
set_iterator<T, Node, RbTree>::set_iterator(set_iterator<U, E, F> const & src)
	: _ptr((Node*)src._ptr), _rb_ptr((RbTree*)src._rb_ptr)
{
}

template<class T, class Node, class RbTree>
set_iterator<T, Node, RbTree>&	set_iterator<T, Node, RbTree>::operator=(set_iterator const & rhs)
{
	if (this != &rhs)
	{
		this->_ptr = rhs._ptr;
		this->_rb_ptr = rhs._rb_ptr;
	}
	return (*this);
}

template<class T, class Node, class RbTree>
set_iterator<T, Node, RbTree>::~set_iterator(void)
{
}

/*
 * One way conversion: iterator ---> const_iterator
 */

// template<class T, class Node, class RbTree>
// set_iterator<T, Node, RbTree>::operator set_iterator<T const, Node const, RbTree const>() const
// {
// 	return (set_iterator<T const, Node const, RbTree const>(this->_ptr, this->_rb_ptr));
// }

/*
 * increment/decrement operators: [ operator++ && operator-- ]
 */

template<class T, class Node, class RbTree>
set_iterator<T, Node, RbTree>&	set_iterator<T, Node, RbTree>::operator++(void)
{
	this->_ptr = this->_rb_ptr->inorder_successor(this->_ptr);
	return (*this);
}

template<class T, class Node, class RbTree>
set_iterator<T, Node, RbTree>	set_iterator<T, Node, RbTree>::operator++(int)
{
	set_iterator	copy(*this);
	
	this->_ptr = this->_rb_ptr->inorder_successor(this->_ptr);
	return (copy);
}

template<class T, class Node, class RbTree>
set_iterator<T, Node, RbTree>&	set_iterator<T, Node, RbTree>::operator--(void)
{
	this->_ptr = this->_rb_ptr->inorder_predecessor(this->_ptr);
	return (*this);
}

template<class T, class Node, class RbTree>
set_iterator<T, Node, RbTree>	set_iterator<T, Node, RbTree>::operator--(int)
{
	set_iterator	copy(*this);
	
	this->_ptr = this->_rb_ptr->inorder_predecessor(this->_ptr);
	return (copy);
}

/*
 * comparison operators: [ operator== && operator!= ]
 */

template<class T, class Node, class RbTree>
bool	set_iterator<T, Node, RbTree>::operator==(set_iterator const & rhs) const
{
	return (this->_ptr == rhs._ptr);
}

template<class T, class Node, class RbTree>
bool	set_iterator<T, Node, RbTree>::operator!=(set_iterator const & rhs) const
{
	return (this->_ptr != rhs._ptr);
}

/*
 * dereferencing operators: [ operator* && operator-> ]
 */

template<class T, class Node, class RbTree>
typename set_iterator<T, Node, RbTree>::reference	set_iterator<T, Node, RbTree>::operator*(void) const
{
	return (this->_ptr->key);
}

template<class T, class Node, class RbTree>
typename set_iterator<T, Node, RbTree>::pointer	set_iterator<T, Node, RbTree>::operator->(void) const
{
	return (&(this->_ptr->key));
}

}

#endif
