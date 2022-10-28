
#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template<class T1, class T2>
struct pair
{
	// Data members:
	T1	first; // The first value in the pair
	T2	second; // The second value in the pair

	// Member types:
	typedef T1	first_type;
	typedef T2	second_type;

	// Member functions:
	pair(void);
	template<class U, class V>
		pair(pair<U, V> const & pr);
	pair(first_type const & a, second_type const & b);
	pair& operator=(pair const & pr);

};

}

# include "pair.tpp"

#endif
