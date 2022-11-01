
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
	Container	c;

public:
	// Member types
	typedef Container	container_type;
	typedef typename Container::value_type	value_type;
	typedef typename Container::size_type	size_type;
	typedef typename Container::reference	reference;
	typedef typename Container::const_reference	const_reference;
	
public:
	// Constructors && Destructor && Copy assignment operator
	explicit stack(container_type const & cont = container_type());
	stack(stack const & other);
	stack&	operator=(stack const & other);
	~stack(void);

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
