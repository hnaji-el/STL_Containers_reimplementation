
#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP

namespace ft
{

/*----------------------------------------------------------------------------*/
/*-------------------           Constructors           -----------------------*/
/*----------------------------------------------------------------------------*/

template<class Iterator>
reverse_iterator<Iterator>::reverse_iterator(void)
	: base_iterator()
{
}

template<class Iterator>
reverse_iterator<Iterator>::reverse_iterator(iterator_type it)
	: base_iterator(it)
{
}

template<class Iterator>
template<class Iter>
reverse_iterator<Iterator>::reverse_iterator(reverse_iterator<Iter> const & rev_it)
	: base_iterator(rev_it.base())
{
}

/*----------------------------------------------------------------------------*/
/*-------------------               base()             -----------------------*/
/*----------------------------------------------------------------------------*/

template<class Iterator>
typename reverse_iterator<Iterator>::iterator_type	reverse_iterator<Iterator>::base(void) const
{
	return (this->base_iterator);
}

/*----------------------------------------------------------------------------*/
/*------------------- pre_increment and post_increment -----------------------*/
/*------------------- pre_decrement and post_decrement -----------------------*/
/*----------------------------------------------------------------------------*/

template<class Iterator>
reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator++(void)
{
	--this->base_iterator;
	return (*this);
}

template<class Iterator>
reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator++(int)
{
	reverse_iterator	temp = *this;

	--this->base_iterator;
	return (temp);
}

template<class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--(void)
{
	++this->base_iterator;
	return (*this);
}

template<class Iterator>
reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator--(int)
{
	reverse_iterator	temp = *this;

	++this->base_iterator;
	return (temp);
}

/*----------------------------------------------------------------------------*/
/*------------------       dereferencing operators         -------------------*/
/*------------------              *, [] and &              -------------------*/
/*----------------------------------------------------------------------------*/

template<class Iterator>
typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator*(void) const
{
	iterator_type	logical_position = this->base_iterator;

	return (*(--logical_position));
}

template<class Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](
	difference_type n) const
{
	iterator_type	logical_position = this->base_iterator - 1;

	return (logical_position[-n]);
}

template<class Iterator>
typename reverse_iterator<Iterator>::pointer	reverse_iterator<Iterator>::operator->(void) const
{
	return (&(this->operator*()));
}

/*----------------------------------------------------------------------------*/
/*------------------           arithmetic operators        -------------------*/
/*------------------                 - and +               -------------------*/
/*----------------------------------------------------------------------------*/

template<class Iterator>
reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator+(difference_type n) const
{
	return (reverse_iterator(this->base_iterator - n));
}

template<class Iterator>
reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator-(difference_type n) const
{
	return (reverse_iterator(this->base_iterator + n));
}

template<class Iterator>
reverse_iterator<Iterator>	operator+(
	typename reverse_iterator<Iterator>::difference_type n,
	reverse_iterator<Iterator> const & rev_it)
{
	return (rev_it + n);
}

template<class Iterator>
typename reverse_iterator<Iterator>::difference_type	operator-(
	reverse_iterator<Iterator> const & lhs,
	reverse_iterator<Iterator> const & rhs)
{
	return (rhs.base() - lhs.base());
}

/*----------------------------------------------------------------------------*/
/*---------------         compound assignment operators        ---------------*/
/*---------------                  += and -=                   ---------------*/
/*----------------------------------------------------------------------------*/

template<class Iterator>
reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator+=(difference_type n)
{
	this->base_iterator -= n;
	return (*this);
}

template<class Iterator>
reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator-=(difference_type n)
{
	this->base_iterator += n;
	return (*this);
}

/*----------------------------------------------------------------------------*/
/*---------------              Relational operators            ---------------*/
/*---------------              ==, !=, >, <, >=, <=            ---------------*/
/*----------------------------------------------------------------------------*/

template<class Iterator>
bool	operator==(
	reverse_iterator<Iterator> const & lhs,
	reverse_iterator<Iterator> const & rhs)
{
	return (lhs.base() == rhs.base());
}

template<class Iterator>
bool	operator!=(
	reverse_iterator<Iterator> const & lhs,
	reverse_iterator<Iterator> const & rhs)
{
	return (lhs.base() != rhs.base());
}

template<class Iterator>
bool	operator>(
	reverse_iterator<Iterator> const & lhs,
	reverse_iterator<Iterator> const & rhs)
{
	return (lhs.base() < rhs.base());
}

template<class Iterator>
bool	operator>=(
	reverse_iterator<Iterator> const & lhs,
	reverse_iterator<Iterator> const & rhs)
{
	return (lhs.base() <= rhs.base());
}

template<class Iterator>
bool	operator<(
	reverse_iterator<Iterator> const & lhs,
	reverse_iterator<Iterator> const & rhs)
{
	return (lhs.base() > rhs.base());
}

template<class Iterator>
bool	operator<=(
	reverse_iterator<Iterator> const & lhs,
	reverse_iterator<Iterator> const & rhs)
{
	return (lhs.base() >= rhs.base());
}

}

#endif
