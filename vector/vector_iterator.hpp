
#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>

namespace ft
{

template<class Vector>
class vector_iterator : public std::iterator<std::random_access_iterator_tag, Vector::value_type>
{
private:
	pointer		_ptr;

public:
	vector_iterator(void);
	vector_iterator(vector_iterator const & src);
	vector_iterator&	operator=(vector_iterator const & rhs);
	~vector_iterator(void);

	vector_iterator(pointer ptr);
}

}

# include "vector_iterator.tpp"

#endif
