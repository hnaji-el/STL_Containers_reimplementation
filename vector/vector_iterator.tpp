
#ifndef VECTOR_ITERATOR_TPP
# define VECTOR_ITERATOR_TPP

namespace ft
{

/*----------------------------------------------------------------------------*/
/*---------------------- Constructors && Destructor --------------------------*/
/*----------------------------------------------------------------------------*/

template<class T>
vector_iterator<T>::vector_iterator(pointer ptr) : _ptr(ptr)
{
}

template<class T>
vector_iterator<T>::vector_iterator(vector_iterator const & src) : _ptr(src._ptr)
{
}

template<class T>
vector_iterator<T>&	vector_iterator<T>::operator=(vector_iterator const & rhs)
{
	this->_ptr = rhs._ptr;
	return (*this);
}

template<class T>
vector_iterator<T>::~vector_iterator(void)
{
}

/*----------------------------------------------------------------------------*/
/*------------------- pre_increment and post_increment -----------------------*/
/*------------------- pre_decrement and post_decrement -----------------------*/
/*----------------------------------------------------------------------------*/

template<class T>
vector_iterator<T>&	vector_iterator<T>::operator++(void)
{
	this->_ptr++;
	return (*this);
}

template<class T>
vector_iterator<T>	vector_iterator<T>::operator++(int)
{
	vector_iterator	current_instance_copy = *this;

	this->_ptr++;
	return (current_instance_copy);
}

template<class T>
vector_iterator<T>&	vector_iterator<T>::operator--(void)
{
	this->_ptr--;
	return (*this);
}

template<class T>
vector_iterator<T>	vector_iterator<T>::operator--(int)
{
	vector_iterator	current_instance_copy = *this;

	this->_ptr--;
	return (current_instance_copy);
}

/*----------------------------------------------------------------------------*/
/*-----------------       equality/inequality comparisons    -----------------*/
/*-----------------         (==, !=, <, >, <= and >=)        -----------------*/
/*-----------------             between iterators            -----------------*/
/*----------------------------------------------------------------------------*/

template<class T>
bool	vector_iterator<T>::operator==(vector_iterator const & rhs) const
{
	return (this->_ptr == rhs._ptr);
}

template<class T>
bool	vector_iterator<T>::operator!=(vector_iterator const & rhs) const
{
	return (this->_ptr != rhs._ptr);
}

template<class T>
bool	vector_iterator<T>::operator<(vector_iterator const & rhs) const
{
	return (this->_ptr < rhs._ptr);
}

template<class T>
bool	vector_iterator<T>::operator>(vector_iterator const & rhs) const
{
	return (this->_ptr > rhs._ptr);
}

template<class T>
bool	vector_iterator<T>::operator<=(vector_iterator const & rhs) const
{
	return (this->_ptr <= rhs._ptr);
}

template<class T>
bool	vector_iterator<T>::operator>=(vector_iterator const & rhs) const
{
	return (this->_ptr >= rhs._ptr);
}

/*----------------------------------------------------------------------------*/
/*------------------       dereferencing operators         -------------------*/
/*------------------              *, [] and &              -------------------*/
/*----------------------------------------------------------------------------*/

template<class T>
typename vector_iterator<T>::reference	vector_iterator<T>::operator*(void) const
{
	return (*this->_ptr);
}

template<class T>
typename vector_iterator<T>::reference	vector_iterator<T>::operator[](difference_type n) const
{
	return (*(this->_ptr + n));
}

template<class T>
typename vector_iterator<T>::pointer	vector_iterator<T>::operator->(void) const
{
	return (this->_ptr);
}

/*----------------------------------------------------------------------------*/
/*------------------           arithmetic operators        -------------------*/
/*------------------                 - and +               -------------------*/
/*----------------------------------------------------------------------------*/

template<class T>
vector_iterator<T>	vector_iterator<T>::operator+(difference_type n) const
{
	return (vector_iterator(this->_ptr + n));
}

template<class T>
vector_iterator<T>	vector_iterator<T>::operator-(difference_type n) const
{
	return (vector_iterator(this->_ptr - n));
}

template<class T>
vector_iterator<T>	operator+(
	typename vector_iterator<T>::difference_type n,
	vector_iterator<T> const & rhs)
{
	return (rhs + n);
}

template<class T>
typename vector_iterator<T>::difference_type	vector_iterator<T>::operator-(
	vector_iterator const & rhs) const
{
	return (this->_ptr - rhs._ptr);
}

/*----------------------------------------------------------------------------*/
/*---------------         compound assignment operators        ---------------*/
/*---------------                  += and -=                   ---------------*/
/*----------------------------------------------------------------------------*/

template<class T>
vector_iterator<T>&	vector_iterator<T>::operator+=(difference_type n)
{
	this->_ptr += n;
	return (*this);
}

template<class T>
vector_iterator<T>&	vector_iterator<T>::operator-=(difference_type n)
{
	this->_ptr -= n;
	return (*this);
}

}

#endif
