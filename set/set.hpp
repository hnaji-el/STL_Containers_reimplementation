
#ifndef SET_HPP
# define SET_HPP

# include "node.hpp"
# include "rb_tree.hpp"
# include "set_iterator.hpp"
# include "../utilities/iterator_traits.hpp"
# include "../utilities/reverse_iterator.hpp"
# include "../utilities/pair.hpp"
# include "../utilities/make_pair.hpp"
# include "../utilities/lexicographical_compare.hpp"
# include "../utilities/equal.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include <memory>

namespace ft
{

template<class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set
{	
private:
	// Data members:
	typedef rb_tree<T, Compare, Alloc>	rb_tree_t;
	rb_tree_t	_rb_obj;

public:
	// Member types:
	typedef T								key_type;
	typedef T								value_type;
	typedef Compare							key_compare;
	typedef Compare							value_compare;
	typedef Alloc							allocator_type;
	typedef typename Alloc::reference		reference;
	typedef typename Alloc::const_reference	const_reference;
	typedef typename Alloc::pointer			pointer;
	typedef typename Alloc::const_pointer	const_pointer;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef size_t	size_type;
	// iterators:
	typedef ft::map_iterator<value_type      , node<value_type>      , rb_tree_t      >	iterator;
	typedef ft::map_iterator<value_type const, node<value_type> const, rb_tree_t const>	const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	
public:
	// Constructors
	explicit set(key_compare const & comp = key_compare(),
				allocator_type const & alloc = allocator_type());
	
	template <class InputIterator>
	set(InputIterator first,
		InputIterator last,
		key_compare const & comp = key_compare(),
		allocator_type const & alloc = allocator_type());
	
	set(set const & x);
	~set(void);
	
	// Copy assignment operator
	map&    operator=(map const & rhs);
	
	// Modifiers: [ insert ]
	ft::pair<iterator, bool>	insert(value_type const & val); // single element
	iterator	insert(iterator position, value_type const & val); // with hint
	template<class InputIterator>
		void	insert(InputIterator first, InputIterator last); // range
	
	// Modifiers: [ erase ]
	void		erase(iterator position);
	size_type	erase(value_type const & val);
	void		erase(iterator first, iterator last);
	
	// Modifiers: [ clear  && swap]
	void	clear(void);
	void	swap(set& x);
	
	// Iterators:
	iterator			begin(void);
	const_iterator		begin(void) const;
	iterator			end(void);
	const_iterator		end(void) const;
	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;
	
	// Capacity: [ empty && size && max_size ]
	size_type	size(void) const;
	size_type	max_size(void) const;
	bool		empty(void) const;

	// Operations: [ find && count && lower_bound && upper_bound ]
	iterator		find(value_type const & val);
	const_iterator	find(value_type const & val) const;
	size_type		count(value_type const & val) const;
	iterator		lower_bound(value_type const & val);
	const_iterator	lower_bound(value_type const & val) const;
	iterator		upper_bound(value_type const & val);
	const_iterator	upper_bound(value_type const & val) const;
	ft::pair<iterator, iterator>				equal_range(value_type const & val);
	ft::pair<const_iterator, const_iterator>	equal_range(value_type const & val) const;
	
	// Observers:
	key_compare		key_comp(void) const;
	value_compare	value_comp(void) const;
	allocator_type	get_allocator(void) const;
};


// swap
template<class T, class Compare, class Alloc>
void	swap(set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y);

// relational comparison
template<class T, class Compare, class Alloc>
bool	operator==(set<T, Compare, Alloc> const & lhs, set<T, Compare, Alloc> const & rhs);

template<class T, class Compare, class Alloc>
bool	operator!=(set<T, Compare, Alloc> const & lhs, set<T, Compare, Alloc> const & rhs);

template<class T, class Compare, class Alloc>
bool	operator<(set<T, Compare, Alloc> const & lhs, set<T, Compare, Alloc> const & rhs);

template<class T, class Compare, class Alloc>
bool	operator<=(set<T, Compare, Alloc> const & lhs, set<T, Compare, Alloc> const & rhs);

template<class T, class Compare, class Alloc>
bool	operator>(set<T, Compare, Alloc> const & lhs, set<T, Compare, Alloc> const & rhs);

template<class T, class Compare, class Alloc>
bool	operator>=(set<T, Compare, Alloc> const & lhs, set<T, Compare, Alloc> const & rhs);

}

# include "set.tpp"

#endif
