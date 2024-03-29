
#ifndef MAP_ITERATOR_TPP
# define MAP_ITERATOR_TPP

namespace ft
{

/*----------------------------------------------------------------------------*/
/*-                      Constructors && Destructor                          -*/
/*----------------------------------------------------------------------------*/

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>::map_iterator(void) : _avl_ptr(), _ptr()
{
}

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>::map_iterator(AvlTree* avl_ptr, Node* ptr)
	: _avl_ptr(avl_ptr), _ptr(ptr)
{
}

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>::map_iterator(map_iterator const & src)
	: _avl_ptr(src._avl_ptr), _ptr(src._ptr)
{
}

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>&	map_iterator<T, Node, AvlTree>::operator=(map_iterator const & rhs)
{
	this->_avl_ptr = rhs._avl_ptr;
	this->_ptr = rhs._ptr;
	return (*this);
}

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>::~map_iterator(void)
{
}

/*----------------------------------------------------------------------------*/
/*-             one way conversion: iterator -> const_iterator               -*/
/*----------------------------------------------------------------------------*/

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>::operator map_iterator<T const, Node const, AvlTree const>() const
{
	return (map_iterator<T const, Node const, AvlTree const>(this->_avl_ptr, this->_ptr));
}

/*----------------------------------------------------------------------------*/
/*-                   pre_increment and post_increment                       -*/
/*-                   pre_decrement and post_decrement                       -*/
/*----------------------------------------------------------------------------*/

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>&	map_iterator<T, Node, AvlTree>::operator++(void)
{
	this->_ptr = this->_avl_ptr->inorder_successor(this->_ptr);
	return (*this);
}

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>	map_iterator<T, Node, AvlTree>::operator++(int)
{
	map_iterator	copy = *this;

	this->_ptr = this->_avl_ptr->inorder_successor(this->_ptr);
	return (copy);
}

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>&	map_iterator<T, Node, AvlTree>::operator--(void)
{
	this->_ptr = this->_avl_ptr->inorder_predecessor(this->_ptr);
	return (*this);
}

template<class T, class Node, class AvlTree>
map_iterator<T, Node, AvlTree>	map_iterator<T, Node, AvlTree>::operator--(int)
{
	map_iterator	copy = *this;

	this->_ptr = this->_avl_ptr->inorder_predecessor(this->_ptr);
	return (copy);
}

/*----------------------------------------------------------------------------*/
/*-----------------       equality/inequality comparisons    -----------------*/
/*-----------------                 (==, !=)                 -----------------*/
/*-----------------             between iterators            -----------------*/
/*----------------------------------------------------------------------------*/

template<class T, class Node, class AvlTree>
bool	map_iterator<T, Node, AvlTree>::operator==(map_iterator const & rhs) const
{
	return (this->_ptr == rhs._ptr);
}

template<class T, class Node, class AvlTree>
bool	map_iterator<T, Node, AvlTree>::operator!=(map_iterator const & rhs) const
{
	return (this->_ptr != rhs._ptr);
}

/*----------------------------------------------------------------------------*/
/*------------------       dereferencing operators         -------------------*/
/*------------------              * and &                  -------------------*/
/*----------------------------------------------------------------------------*/

template<class T, class Node, class AvlTree>
typename map_iterator<T, Node, AvlTree>::reference	map_iterator<T, Node, AvlTree>::operator*(void) const
{
	return (this->_ptr->data);
}

template<class T, class Node, class AvlTree>
typename map_iterator<T, Node, AvlTree>::pointer	map_iterator<T, Node, AvlTree>::operator->(void) const
{
	return (&(this->_ptr->data));
}

}

#endif
