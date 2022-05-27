
#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{

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

template<class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::size(void) const
{
	return (this->_size);
}

}

template<class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity(void) const
{
	return (this->_capacity);
}

}

#endif































