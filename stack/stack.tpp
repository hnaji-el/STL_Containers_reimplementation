
#ifndef STACK_TPP
# define STACK_TPP

namespace ft
{

/*
 * Constructors && Copy assignment operator && Destructor
 */

template<class T, class Ctnr>
stack<T, Ctnr>::stack(container_type const & cont) : c(cont)
{
}

template<class T, class Ctnr>
stack<T, Ctnr>::stack(stack const & other) : c(other.c)
{
}

template<class T, class Ctnr>
stack<T, Ctnr>&		stack<T, Ctnr>::operator=(stack const & other)
{
	this->c = other.c;
	return (*this);
}

template<class T, class Ctnr>
stack<T, Ctnr>::~stack(void)
{
}

/*
 * empty && size && top && push && pop
 */

template<class T, class Ctnr>
bool	stack<T, Ctnr>::empty(void) const
{
	return (this->c.empty());
}
	
template<class T, class Ctnr>
size_t	stack<T, Ctnr>::size(void) const
{
	return (this->c.size());
}
	
template<class T, class Ctnr>
T&	stack<T, Ctnr>::top(void)
{
	return (this->c.back());
}
	
template<class T, class Ctnr>
T const &	stack<T, Ctnr>::top(void) const
{
	return (this->c.back());
}
	
template<class T, class Ctnr>
void	stack<T, Ctnr>::push(value_type const & val)
{
	this->c.push_back(val);
}

template<class T, class Ctnr>
void	stack<T, Ctnr>::pop(void)
{
	this->c.pop_back();
}

template<class T, class Ctnr>
bool	operator==(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs.c == rhs.c);
}

template<class T, class Ctnr>
bool	operator!=(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs.c != rhs.c);
}

template<class T, class Ctnr>
bool	operator<(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs.c < rhs.c);
}

template<class T, class Ctnr>
bool	operator<=(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs.c <= rhs.c);
}

template<class T, class Ctnr>
bool	operator>(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs.c > rhs.c);
}

template<class T, class Ctnr>
bool	operator>=(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs.c >= rhs.c);
}

}

#endif
