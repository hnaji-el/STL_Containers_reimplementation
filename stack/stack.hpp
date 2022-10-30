
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
	// Data members
	Container	_base_ctnr;

public:
	// Member types
	typedef T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;
	
public:
	// constructor
	explicit stack(container_type const & ctnr = container_type());
	
	// member functions
	bool	empty(void) const;
	size_t	size(void) const;
	T&		top(void);
	T const &	top(void) const;
	void	push(const value_type& val);
	void	pop(void);
	
	// friend declaration
	template<class U, class Ctnr>
		friend bool	operator==(stack<U, Ctnr> const & lhs, stack<U, Ctnr> const & rhs);
	template<class U, class Ctnr>
		friend bool operator!=(stack<U, Ctnr> const & lhs, stack<U, Ctnr> const & rhs);
	template<class U, class Ctnr>
		friend bool operator<(stack<U, Ctnr> const & lhs, stack<U, Ctnr> const & rhs);
	template<class U, class Ctnr>
		friend bool operator<=(stack<U, Ctnr> const & lhs, stack<U, Ctnr> const & rhs);
	template<class U, class Ctnr>
		friend bool operator>(stack<U, Ctnr> const & lhs, stack<U, Ctnr> const & rhs);
	template<class U, class Ctnr>
		friend bool operator>=(stack<U,Ctnr> const & lhs, stack<U, Ctnr> const & rhs);
};

}

# include "stack.tpp"

#endif
