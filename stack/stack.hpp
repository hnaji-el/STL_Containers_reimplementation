
#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"
# include <cstddef>

namespace ft
{

template<class T, class Container = ft::vector<T> >
class stack
{
protected:
	Container	_base_ctnr;

public:
	// Member types
	typedef T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;

	// Constructor && Destructor
	explicit stack(container_type const & ctnr = container_type()) : _base_ctnr(ctnr) { }

	bool	empty(void) const
	{
		return (_base_ctnr.empty());
	}

	size_type	size(void) const
	{
		return (_base_ctnr.size());
	}

	value_type&	top(void)
	{
		return (_base_ctnr.back());
	}

	const value_type&	top(void) const
	{
		return (_base_ctnr.back());
	}

	void	push(const value_type& val)
	{
		_base_ctnr.push_back(val);
	}

	void	pop(void)
	{
		_base_ctnr.pop_back();
	}

	template< class U, class Ctnr >
	friend bool	operator==(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs);

	template< class U, class Ctnr >
	friend bool operator!=( const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs );

	template< class U, class Ctnr >
	friend bool operator<( const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs );

	template< class U, class Ctnr >
	friend bool operator<=( const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs );

	template< class U, class Ctnr >
	friend bool operator>( const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs );

	template< class U, class Ctnr >
	friend bool operator>=( const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs );

};

template < class T, class Container >
bool operator== (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs._base_ctnr == rhs._base_ctnr);
}

template < class T, class Container >
bool operator!= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs._base_ctnr != rhs._base_ctnr);
}

template < class T, class Container >
bool operator< (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs._base_ctnr < rhs._base_ctnr);
}

template < class T, class Container >
bool operator<= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs._base_ctnr <= rhs._base_ctnr);
}

template < class T, class Container >
bool operator> (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs._base_ctnr > rhs._base_ctnr);
}

template < class T, class Container >
bool operator>= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs._base_ctnr >= rhs._base_ctnr);
}

}

#endif

