
#ifndef STACK_TPP
# define STACK_TPP

namespace ft
{

template<class T, class Ctnr>
stack<T, Ctnr>::stack(container_type const & ctnr) : _base_ctnr(ctnr)
{
}
	
template<class T, class Ctnr>
bool	stack<T, Ctnr>::empty(void) const
{
	return (this->_base_ctnr.empty());
}
	
template<class T, class Ctnr>
size_t	stack<T, Ctnr>::size(void) const
{
	return (this->_base_ctnr.size());
}
	
template<class T, class Ctnr>
T&	stack<T, Ctnr>::top(void)
{
	return (this->_base_ctnr.back());
}
	
template<class T, class Ctnr>
T const &	stack<T, Ctnr>::top(void) const
{
	return (this->_base_ctnr.back());
}
	
template<class T, class Ctnr>
void	stack<T, Ctnr>::push(value_type const & val)
{
	this->_base_ctnr.push_back(val);
}

template<class T, class Ctnr>
void	stack<T, Ctnr>::pop(void)
{
	this->_base_ctnr.pop_back();
}

template<class T, class Ctnr>
bool	operator==(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs._base_ctnr == rhs._base_ctnr);
}

template<class T, class Ctnr>
bool	operator!=(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs._base_ctnr != rhs._base_ctnr);
}

template<class T, class Ctnr>
bool	operator<(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs._base_ctnr < rhs._base_ctnr);
}

template<class T, class Ctnr>
bool	operator<=(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs._base_ctnr <= rhs._base_ctnr);
}

template<class T, class Ctnr>
bool	operator>(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs._base_ctnr > rhs._base_ctnr);
}

template<class T, class Ctnr>
bool	operator>=(stack<T, Ctnr> const & lhs, stack<T, Ctnr> const & rhs)
{
	return (lhs._base_ctnr >= rhs._base_ctnr);
}

}

#endif
