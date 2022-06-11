
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

	// ++a; pre_increment
	// a++; post_increment
	typename vector_iterator::pointer	operator++(void);
	typename vector_iterator::pointer	operator++(int);
};

}

# include "vector_iterator.tpp"

#endif

