
#ifndef PAIR_TPP
# define PAIR_TPP

namespace ft
{

/*
 * Constructors
 */

template<class T1, class T2>
pair<T1, T2>::pair(void) : first(), second()
{
}

template<class T1, class T2>
template<class U, class V>
pair<T1, T2>::pair(pair<U, V> const & pr) : first(pr.first), second(pr.second)
{
}

template<class T1, class T2>
pair<T1, T2>::pair(first_type const & a, second_type const & b) : first(a), second(b)
{
}

/*
 * Copy assignment operator
 */

template<class T1, class T2>
pair<T1, T2>&	pair<T1, T2>::operator=(pair const & pr)
{
	this->first = pr.first;
	this->second = pr.second;
	return (*this);
}

/*
 * Relational comparison operators
 */

template<class T1, class T2>
bool	operator==(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template<class T1, class T2>
bool	operator!=(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (!(lhs == rhs));
}

template<class T1, class T2>
bool	operator<(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	return (!(rhs.first < lhs.first) && (lhs.second < rhs.second));
}

template<class T1, class T2>
bool	operator<=(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (!(rhs < lhs));
}

template<class T1, class T2>
bool	operator>(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (rhs < lhs);
}

template<class T1, class T2>
bool	operator>=(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (!(lhs < rhs));
}

}

#endif
