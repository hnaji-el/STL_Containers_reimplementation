
#ifndef ITERATOR_TRAITS_HPP
# define  ITERATOR_TRAITS_HPP

# include <cstddef>
# include <iterator>

namespace ft
{

template<class Iterator>
struct iterator_traits
{
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::iterator_category	iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	typedef std::random_access_iterator_tag	iterator_category;
};

template<class T>
struct iterator_traits<T const *>
{
	typedef T								value_type;
	typedef T const *						pointer;
	typedef T const &						reference;
	typedef ptrdiff_t						difference_type;
	typedef std::random_access_iterator_tag	iterator_category;
};

}

#endif

