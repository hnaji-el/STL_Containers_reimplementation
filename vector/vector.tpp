
#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{

/*----------------------------------------------------------------------------*/
/*----------------------        Constructors        --------------------------*/
/*----------------------------------------------------------------------------*/

template<class T, class Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc)
	: _array(NULL), _alloc(alloc), _size(0), _capacity(0)
{
}

template<class T, class Alloc>
vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
	: _array(NULL), _alloc(alloc), _size(n), _capacity(n)
{
	this->_array = this->_alloc.allocate(n);
	for (size_t i = 0; i < n; i++)
	{
		this->_alloc.construct(this->_array + i, val);
	}
}

/*----------------------------------------------------------------------------*/
/*----------------------          Capacity          --------------------------*/
/*----------------------------------------------------------------------------*/

template<class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::size(void) const
{
	return (this->_size);
}

template<class T, class Alloc>
typename vector<T, Alloc>::size_type 	vector<T, Alloc>::max_size(void) const
{
	size_type	max_size;

	max_size = this->_alloc.max_size();
	if (sizeof(value_type) == 1)
		return (max_size / 2);
	return (max_size);
}

template<class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity(void) const
{
	return (this->_capacity);
}

template<class T, class Alloc>
bool	vector<T, Alloc>::empty(void) const
{
	if (this->_size == 0)
		return (true);
	return (false);
}

}

#endif































