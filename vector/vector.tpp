
#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{

/*
 * Constructors && Destructor
 */

template<class T, class Alloc>
vector<T, Alloc>::vector(allocator_type const & alloc)
	: _array(), _alloc(alloc), _size(), _capacity()
{
}

template<class T, class Alloc>
vector<T, Alloc>::vector(size_type n, value_type const & val, const allocator_type& alloc)
	: _array(), _alloc(alloc), _size(n), _capacity(n)
{
	this->_array = this->_alloc.allocate(n);
	for (size_type i = 0; i < n; i++) {
		this->_alloc.construct(this->_array + i, val);
	}
}

template<class T, class Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(InputIterator first, InputIterator last,
						allocator_type const & alloc,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	: _array(), _alloc(alloc), _size(), _capacity()
{
	this->_size = this->_capacity = std::distance(first, last);

	this->_array = this->_alloc.allocate(this->_capacity);
	for (size_type i = 0; first != last; ++first, ++i) {
		this->_alloc.construct(this->_array + i, *first);
	}
}

template<class T, class Alloc>
vector<T, Alloc>::vector(vector const & x)
	: _array(), _alloc(x._alloc), _size(x._size), _capacity(x._size)
{
	this->_array = this->_alloc.allocate(this->_size);
	for (size_type i = 0; i < this->_size; i++) {
		this->_alloc.construct(this->_array + i, *(x._array + i));
	}
}

template<class T, class Alloc>
vector<T, Alloc>::~vector(void)
{
	for (size_type	i = 0; i < this->_size; i++)
		this->_alloc.destroy(this->_array + i);
	this->_alloc.deallocate(this->_array, this->_capacity);
}

/*
 * Copy assignment operator:
 */

template<class T, class Alloc>
vector<T, Alloc>&	vector<T, Alloc>::operator=(vector const & x)
{
	this->clear();
	this->_alloc.deallocate(this->_array, this->_capacity);

	this->_size = this->_capacity = x._size;
	this->_array = this->_alloc.allocate(this->_size);

	for (size_type i = 0; i < this->_size; i++) {
		this->_alloc.construct(this->_array + i, *(x._array + i));
	}

	return (*this);
}

/*
 * Iterators:
 */

template<class T, class Alloc>
typename vector<T, Alloc>::iterator		vector<T, Alloc>::begin(void)
{
	return (iterator(this->_array));
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::begin(void) const
{
	return (const_iterator(this->_array));
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator		vector<T, Alloc>::end(void)
{
	return (iterator(this->_array + this->_size));
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::end(void) const
{
	return (const_iterator(this->_array + this->_size));
}

template<class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin(void)
{
    return (reverse_iterator(this->end()));
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator   vector<T, Alloc>::rbegin(void) const
{
    return (const_reverse_iterator(this->end()));
}

template<class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend(void)
{
    return (reverse_iterator(this->begin()));
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator   vector<T, Alloc>::rend(void) const
{
    return (const_reverse_iterator(this->begin()));
}

/*
 * Modifiers: [ assign ]
 */

template<class T, class Alloc>
void	vector<T, Alloc>::prepare_array_for_assign(const size_type n)
{
	for (size_type i = 0; i < this->_size; i++) {
		this->_alloc.destroy(this->_array + i);
	}

	if (n > this->_capacity) {
		this->_alloc.deallocate(this->_array, this->_capacity);
		this->_size = this->_capacity = n;
		this->_array = this->_alloc.allocate(n);
	}
	else {
		this->_size = n;
	}
}

template<class T, class Alloc>
template<class InputIterator>
void	vector<T, Alloc>::assign(InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
	const size_type		new_size = std::distance(first, last);

	prepare_array_for_assign(new_size);
	for (size_type i = 0; first != last; ++i, ++first) {
		this->_alloc.construct(this->_array + i, *first);
	}
}

template<class T, class Alloc>
void	vector<T, Alloc>::assign(size_type n, value_type const & val)
{
	prepare_array_for_assign(n);
	for (size_type i = 0; i < this->_size; ++i) {
		this->_alloc.construct(this->_array + i, val);
	}
}

/*
 * Modifiers: [ insert ]
 */

template<class T, class Alloc>
void	vector<T, Alloc>::make_places_to_new_elements(const size_type pos_index, const size_type n)
{
	// case1: without reallocation
	if ((this->_capacity - this->_size) >= n)
	{
	    for(long index = this->_size - 1; index >= (long)pos_index; index--)
		{
	    	this->_alloc.construct(this->_array + index + n, *(this->_array + index));
	    	this->_alloc.destroy(this->_array + index);
	    }
	}
	// case2: with reallocation
	else
	{
		size_type	new_capacity = this->get_new_capacity(this->_size + n);
		pointer		new_array = this->_alloc.allocate(new_capacity);
		
		for (size_type i = 0; i < pos_index; i++)
		{
			this->_alloc.construct(new_array + i, *(this->_array + i));
			this->_alloc.destroy(this->_array + i);
		}
		for(size_type i = pos_index; i < this->_size; i++)
		{
			this->_alloc.construct(new_array + i + n, *(this->_array + i));
			this->_alloc.destroy(this->_array + i);
		}
		this->_alloc.deallocate(this->_array, this->_capacity);
		this->_array = new_array;
		this->_capacity = new_capacity;
	}
	this->_size += n;
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, value_type const & val)
{
	const size_type		pos_index = position - this->begin();

	this->make_places_to_new_elements(pos_index, 1);
	this->_alloc.construct(this->_array + pos_index, val);
	return (this->begin() + pos_index);
}

template<class T, class Alloc>
void	vector<T, Alloc>::insert(iterator position, size_type n, value_type const & val)
{
	const size_type		pos_index = position - this->begin();

	this->make_places_to_new_elements(pos_index, n);
	for(size_type i = 0; i < n; i++) {
		this->_alloc.construct(this->_array + pos_index + i, val);
	}
}

template<class T, class Alloc>
template <class InputIterator>
void	vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
	const size_type		pos_index = position - this->begin();
	const size_type		n = std::distance(first, last);

	this->make_places_to_new_elements(pos_index, n);
	for(size_type i = 0; i < n; ++i, ++first) {
		this->_alloc.construct(this->_array + pos_index + i, *first);
	}
}

/*
 * Modifiers: [ erase ]
 */

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase_def_(const size_type pos_index, const size_type n)
{
	for (size_type index = pos_index; index < this->_size; ++index)
	{
		this->_alloc.destroy(this->_array + index);
		if (index + n < this->_size)
			this->_alloc.construct(this->_array + index, *(this->_array + index + n));
	}
	this->_size -= n;
	return (iterator(this->_array + pos_index));
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator position)
{
	const size_type		pos_index = position - this->begin();
	
	return (erase_def_(pos_index, 1));
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
{
	const size_type		n = last - first;
	const size_type		pos_index = first - this->begin();

	return (erase_def_(pos_index, n));
}

/*
 * Modifiers: [ push_back && pop_back ]
 */

template<class T, class Alloc>
void	vector<T, Alloc>::push_back(value_type const & val)
{
	if (this->_array == NULL)
	{
		this->_size = this->_capacity = 1;
		this->_array = this->_alloc.allocate(this->_size);
		this->_alloc.construct(this->_array, val);
	}
	else
		this->insert(this->end(), val);

}

template<class T, class Alloc>
void	vector<T, Alloc>::pop_back(void)
{
	if (this->_size == 0)
		return ;
	this->_size--;
	this->_alloc.destroy(this->_array + this->_size);
}

/*
 * Modifiers: [ swap && clear ]
 */

template<class T, class Alloc>
void    vector<T, Alloc>::swap(vector& x)
{
	std::swap(this->_array, x._array);
	std::swap(this->_alloc, x._alloc);
	std::swap(this->_size, x._size);
	std::swap(this->_capacity, x._capacity);
}

template<class T, class Alloc>
void	vector<T, Alloc>::clear(void)
{
	while (this->_size > 0)
	{
	    this->_size--;
	    this->_alloc.destroy(this->_array + this->_size);
	}
}

/*
 * Capacity: [ size && capacity && max_size && empty ]
 */

template<class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::size(void) const
{
	return (this->_size);
}

template<class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity(void) const
{
    return (this->_capacity);
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
bool	vector<T, Alloc>::empty(void) const
{
    if (this->_size == 0)
        return (true);
    return (false);
}

template<class T, class Alloc>
void	vector<T, Alloc>::resize(size_type n, value_type val)
{
	if (n == this->_size)
		return ;

	if (n < this->_size)
	{
		for (; n < this->_size; this->_size--)
			this->_alloc.destroy(this->_array + this->_size - 1);
		return ;
	}
	
	if (n <= this->_capacity)
	{
		for (; n > this->_size; this->_size++)
			this->_alloc.construct(this->_array + this->_size, val);
	}
	else
		this->insert(iterator(this->_array + this->_size), n - this->_size, val);
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
	for (size_type i = 0; i < this->_size; i++)
	{
		this->_alloc.construct(this->_array + i, *(tempPtr + i));
		this->_alloc.destroy(tempPtr + i);
	}
	this->_alloc.deallocate(tempPtr, this->_capacity);
	this->_capacity = n;
}

/*
 * Element access: [ operator[] && at && front && back ]
 */

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

/*
 * Allocator:
 */

template<class T, class Alloc>
typename vector<T, Alloc>::allocator_type   vector<T, Alloc>::get_allocator(void) const
{
    return (this->_alloc);
}

/*
 * Helper member functions: [ get_new_capacity ]
 */

template<class T, class Alloc>
typename vector<T, Alloc>::size_type    vector<T, Alloc>::get_new_capacity(size_type n)
{
	size_type const	new_capacity = this->_capacity * 2;
	
	if (new_capacity < n)
		return (n);
	return (new_capacity);
}

/*
 * Non-member function overloads:
 */

template<class T, class Alloc>
bool	operator==(vector<T, Alloc> const & lhs, vector<T, Alloc> const & rhs)
{
	return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class T, class Alloc>
bool	operator!=(vector<T, Alloc> const & lhs, vector<T, Alloc> const & rhs)
{
	return (!(lhs == rhs));
}

template<class T, class Alloc>
bool	operator<(vector<T, Alloc> const & lhs, vector<T, Alloc> const & rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class T, class Alloc>
bool	operator<=(vector<T, Alloc> const & lhs, vector<T, Alloc> const &rhs)
{
	return (!(rhs < lhs));
}

template<class T, class Alloc>
bool	operator>(vector<T, Alloc> const & lhs, vector<T, Alloc> const & rhs)
{
	return (rhs < lhs);
}

template<class T, class Alloc>
bool	operator>=(vector<T, Alloc> const & lhs, vector<T, Alloc> const & rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

}

#endif
