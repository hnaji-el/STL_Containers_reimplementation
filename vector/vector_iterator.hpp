
#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>
# include <cstddef>

namespace ft
{

template<class T>
class vector_iterator
{
private:
	T*	_ptr;

public:
	//	Member types
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	typedef std::random_access_iterator_tag	iterator_category;

private:
	//	Constructor
	vector_iterator(pointer ptr);

public:
	//	Constructors && Destructor
	vector_iterator(void);
	vector_iterator(vector_iterator const & src);
	vector_iterator&	operator=(vector_iterator const & rhs);
	~vector_iterator(void);

	// Conversion function (make iterator convertible to const_iterator)
	operator vector_iterator<T const>() const;

	//	Increment && Decrement operators
	vector_iterator&	operator++(void);
	vector_iterator		operator++(int);
	vector_iterator&	operator--(void);
	vector_iterator		operator--(int);

	//	Comparison operators
	bool	operator==(vector_iterator const & rhs) const;
	bool	operator!=(vector_iterator const & rhs) const;
	bool	operator<(vector_iterator const & rhs) const;
	bool	operator>(vector_iterator const & rhs) const;
	bool	operator<=(vector_iterator const & rhs) const;
	bool	operator>=(vector_iterator const & rhs) const;

	//	Dereferencing operators
	reference	operator*(void) const;
	reference	operator[](difference_type n) const;
	pointer		operator->(void) const;

	//	Arithmetic operators
	vector_iterator	operator+(difference_type n) const;
	vector_iterator	operator-(difference_type n) const;
	difference_type	operator-(vector_iterator const & rhs) const;

	//	Compound assignment operators
	vector_iterator&	operator+=(difference_type n);
	vector_iterator&	operator-=(difference_type n);
};

}

# include "vector_iterator.tpp"

#endif
