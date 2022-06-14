
#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>

namespace ft
{

template<class Vector>
class vector_iterator :
	public std::iterator<std::random_access_iterator_tag, typename Vector::value_type>
{
private:
	typename vector_iterator::pointer	_ptr;

public:
	vector_iterator(void);
	vector_iterator(vector_iterator const & src);
	vector_iterator&	operator=(vector_iterator const & rhs);
	~vector_iterator(void);

	vector_iterator(typename vector_iterator::pointer ptr);

	typename vector_iterator::pointer	operator++(void);
	typename vector_iterator::pointer	operator++(int);

	bool	operator==(vector_iterator const & rhs) const;
	bool	operator!=(vector_iterator const & rhs) const;

	// *a         rvalue OK
	// a->m		  rvalue ...
	// *a = t	  lvalue OK
	// *a++ = t   lvalue OK
	typename vector_iterator::reference	operator*(void);
	typename vector_iterator::reference	operator->(void);
};

}

# include "vector_iterator.tpp"

#endif

