
#ifndef VECTOR_ITERATOR_TPP
# define VECTOR_ITERATOR_TPP

namespace ft
{

template<class Vector>
vector_iterator<Vector>::vector_iterator(void) : _ptr(NULL)
{
}

template<class Vector>
vector_iterator<Vector>::vector_iterator(pointer ptr) : _ptr(ptr)
{
}

template<class Vector>
vector_iterator<Vector>::vector_iterator(vector_iterator const & src)
	: _ptr(src._ptr)
{
}

template<class Vector>
vector_iterator<Vector>::vector_iterator&	operator=(vector_iterator const & rhs)
{
	this->_ptr = rhs._ptr;
}

template<class Vector>
vector_iterator<Vector>::~vector_iterator(void)
{
}

}

#endif
