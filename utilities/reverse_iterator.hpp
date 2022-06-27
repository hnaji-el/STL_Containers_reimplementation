
#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

template<class Iterator>
class reverse_iterator
{ 
private:
	Iterator	base_iterator;

public:
	//	Member types
	typedef Iterator												iterator_type;
	typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef	typename iterator_traits<Iterator>::value_type			value_type;
	typedef	typename iterator_traits<Iterator>::pointer				pointer;
	typedef	typename iterator_traits<Iterator>::reference			reference;
	typedef	typename iterator_traits<Iterator>::difference_type		difference_type;

public:
	//	Constructors
	reverse_iterator(void);	
	explicit reverse_iterator(iterator_type it);
	template<class Iter>
		reverse_iterator(reverse_iterator<Iter> const & rev_it); // NOTE: ...

	//	base() Member function
	iterator_type	base(void) const;

	//	Increment && Decrement operators
	reverse_iterator&	operator++(void);
	reverse_iterator	operator++(int);
	reverse_iterator& 	operator--(void);
	reverse_iterator  	operator--(int);

	//	Dereferencing operators
	reference	operator*(void) const;
	reference	operator[](difference_type n) const;
	pointer		operator->(void) const;

	//	Arithmetic operators
	reverse_iterator	operator+(difference_type n) const;
	reverse_iterator	operator-(difference_type n) const;

	//	Compound assignment operators
	reverse_iterator&	operator+=(difference_type n);
	reverse_iterator&	operator-=(difference_type n);
};

}

# include "reverse_iterator.tpp"

#endif
