
#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{

/*----------------------------------------------------------------------------*/
/*---------------------- Constructors && Destructor --------------------------*/
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

template<class T, class Alloc>
vector<T, Alloc>::~vector(void)
{
	for (size_t	i = 0; i < this->_size; i++)
	{
		this->_alloc.destroy(this->_array + i);
	}
	this->_alloc.deallocate(this->_array, this->_capacity);
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
void	vector<T, Alloc>::resize(size_type n, value_type val)
{
	/* CASE#1: n < size */
	if (n < this->_size)
	{
		while (this->_size > n)
		{
			this->_size--;
			this->_alloc.destroy(this->_array + this->_size);
		}
	}
	/* CASE#2: n > _size */
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

template<class T, class Alloc>
void	vector<T, Alloc>::reserve(size_type n)
{
	value_type*		tempPtr = this->_array;

	if (n <= this->_capacity)
		return ;
	if (n > this->max_size())
		throw std::length_error("vector");
	this->_array = this->_alloc.allocate(n);
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_alloc.construct(this->_array + i, *(tempPtr + i));
	}
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_alloc.destroy(tempPtr + i);
	}
	this->_alloc.deallocate(tempPtr, this->_capacity);
	this->_capacity = n;
}

/*----------------------------------------------------------------------------*/
/*----------------------        Element access      --------------------------*/
/*----------------------------------------------------------------------------*/

template<class T, class Alloc>
typename vector<T, Alloc>::reference	vector<T, Alloc>::operator[](size_type n)
{
	return (this->_array[n]);
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const
{
	return (this->_array[n]);
}

template<class T, class Alloc>
typename vector<T, Alloc>::reference	vector<T, Alloc>::at(size_type n)
{
	if (n >= this->_size)
		throw std::out_of_range("vector");
	return (this->_array[n]);
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
{
	if (n >= this->_size)
		throw std::out_of_range("vector");
	return (this->_array[n]);
}

template<class T, class Alloc>
typename vector<T, Alloc>::reference	vector<T, Alloc>::front(void)
{
	return (this->_array[0]);
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::front(void) const
{
	return (this->_array[0]);
}

template<class T, class Alloc>
typename vector<T, Alloc>::reference	vector<T, Alloc>::back(void)
{
	return (this->_array[this->_size - 1]);
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::back(void) const
{
	return (this->_array[this->_size - 1]);
}

}

#endif































