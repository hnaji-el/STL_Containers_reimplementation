
#ifndef SET_ITERATOR_TPP
# define SET_ITERATOR_TPP

namespace ft
{

/*
 * Constructors && Destructor
 */

template<class T, class RbTree>
set_iterator<T, RbTree>::set_iterator(void) : _ptr(), _rb_ptr()
{
}

template<class T, class RbTree>
set_iterator<T, RbTree>::set_iterator(node<T> const * ptr, RbTree const * rb_ptr)
	: _ptr(ptr), _rb_ptr(rb_ptr)
{
}

template<class T, class RbTree>
set_iterator<T, RbTree>::set_iterator(set_iterator const & src)
	: _ptr(src._ptr), _rb_ptr(src._rb_ptr)
{
}

template<class T, class RbTree>
set_iterator<T, RbTree>&	set_iterator<T, RbTree>::operator=(set_iterator const & rhs)
{
	if (this != &rhs)
	{
		this->_ptr = rhs._ptr;
		this->_rb_ptr = rhs._rb_ptr;
	}
	return (*this);
}

template<class T, class RbTree>
set_iterator<T, RbTree>::~set_iterator(void)
{
}

/*
 * increment/decrement operators: [ operator++ && operator-- ]
 */

template<class T, class RbTree>
set_iterator<T, RbTree>&	set_iterator<T, RbTree>::operator++(void)
{
	this->_ptr = this->_rb_ptr->inorder_successor(this->_ptr);
	return (*this);
}

template<class T, class RbTree>
set_iterator<T, RbTree>	set_iterator<T, RbTree>::operator++(int)
{
	set_iterator	copy(*this);
	
	this->_ptr = this->_rb_ptr->inorder_successor(this->_ptr);
	return (copy);
}

template<class T, class RbTree>
set_iterator<T, RbTree>&	set_iterator<T, RbTree>::operator--(void)
{
	this->_ptr = this->_rb_ptr->inorder_predecessor(this->_ptr);
	return (*this);
}

template<class T, class RbTree>
set_iterator<T, RbTree>	set_iterator<T, RbTree>::operator--(int)
{
	set_iterator	copy(*this);
	
	this->_ptr = this->_rb_ptr->inorder_predecessor(this->_ptr);
	return (copy);
}

/*
 * comparison operators: [ operator== && operator!= ]
 */

template<class T, class RbTree>
bool	set_iterator<T, RbTree>::operator==(set_iterator const & rhs) const
{
	return (this->_ptr == rhs._ptr);
}

template<class T, class RbTree>
bool	set_iterator<T, RbTree>::operator!=(set_iterator const & rhs) const
{
	return (this->_ptr != rhs._ptr);
}

/*
 * dereferencing operators: [ operator* && operator-> ]
 */

template<class T, class RbTree>
typename set_iterator<T, RbTree>::reference	set_iterator<T, RbTree>::operator*(void) const
{
	return (this->_ptr->key);
}

template<class T, class RbTree>
typename set_iterator<T, RbTree>::pointer	set_iterator<T, RbTree>::operator->(void) const
{
	return (&(this->_ptr->key));
}

}

#endif
