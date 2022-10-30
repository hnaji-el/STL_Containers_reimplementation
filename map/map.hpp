
#ifndef MAP_HPP
# define MAP_HPP

# include "avl_tree.hpp"
# include "node.hpp"
# include "map_iterator.hpp"
# include "../utilities/iterator_traits.hpp"
# include "../utilities/reverse_iterator.hpp"
# include "../utilities/pair.hpp"
# include "../utilities/make_pair.hpp"
# include "../utilities/lexicographical_compare.hpp"
# include "../utilities/equal.hpp"
# include <iostream>
# include <algorithm>
# include <functional>

namespace ft
{

template<class Key,                                          // map::key_type
         class T,                                            // map::mapped_type
         class Compare = std::less<Key>,                     // map::key_compare
         class Alloc = std::allocator<pair<Key const, T> >   // map::allocator_type
         >
class map
{
public:
	// Member types:
	typedef Key		key_type;
	typedef T		mapped_type;
	typedef Compare	key_compare;
	typedef Alloc	allocator_type;
	typedef pair<key_type const, mapped_type>			value_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
private:
	typedef typename allocator_type::template rebind<node<value_type> >::other	node_allocator;
	typedef avl_tree<value_type, key_compare,  node_allocator> avl_tree;
public:
	typedef ft::map_iterator<value_type, node<value_type>, avl_tree>    iterator;
	typedef ft::map_iterator<value_type const, node<value_type> const, avl_tree const>  const_iterator;
	typedef ft::reverse_iterator<iterator>      reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef size_t	size_type;
	////
	class value_compare : std::binary_function<value_type, value_type, bool>
	{
		friend class map;
	protected:
		Compare	comp;
	
		value_compare(Compare c) : comp(c) { } // constructed with map's comparison object
	public:
		bool	operator()(value_type const & x, value_type const & y) const
		{
			return (comp(x.first, y.first));
		}
	};
	////
	
public:
	// Constructors:
	explicit map(key_compare const & comp = key_compare(),
				allocator_type const & alloc = allocator_type());
	
	template <class InputIterator>
	map(InputIterator first,
		InputIterator last,
		key_compare const & comp = key_compare(),
		allocator_type const & alloc = allocator_type());
	
	map(map const & x);
	~map(void);
	
	// Copy assignment operator
	map&    operator=(map const & rhs);
	
	// Iterators:
	iterator		begin(void);
	const_iterator	begin(void) const;
	iterator		end(void);
	const_iterator	end(void) const;
	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;
	
	// Modifiers: [ insert ]
	ft::pair<iterator, bool>	insert(value_type const & val); // single element
	iterator	insert(iterator position, value_type const & val); // with hint
	template<class InputIterator>
		void	insert(InputIterator first, InputIterator last); // range

	// Modifiers: [ erase ]
	void		erase(iterator position);
	size_type	erase(key_type const & k);
	void		erase(iterator first, iterator last);

	// Modifiers: [ clear  && swap]
	void	clear(void);
	void	swap(map& x);

	// Element access:
	mapped_type&	operator[](key_type const & k);
	
	// Capacity: [ empty && size && max_size ]
	bool		empty(void) const;
	size_type	size(void) const;
	size_type	max_size(void) const;

	// Operations: [ find && count && lower_bound && upper_bound ]
	iterator		find(key_type const & k);
	const_iterator	find(key_type const & k) const;
	size_type		count(key_type const & k) const;
	iterator		lower_bound(key_type const & k);
	const_iterator	lower_bound(key_type const & k) const;
	iterator		upper_bound(key_type const & k);
	const_iterator	upper_bound(key_type const & k) const;
	ft::pair<iterator, iterator>				equal_range(key_type const & k);
	ft::pair<const_iterator, const_iterator>	equal_range(key_type const & k) const;

	// Observers:
	key_compare		key_comp(void) const;
	value_compare	value_comp(void) const;
	allocator_type	get_allocator(void) const;

private:
	// Data members:
	avl_tree		_avl_obj;
	key_compare		_comp;
	allocator_type	_alloc;
};

// swap
template<class Key, class T, class Compare, class Alloc>
void	swap(map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs);

// Relational comparison:

template<class Key, class T, class Comp, class Alloc>
bool	operator==(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs);

template<class Key, class T, class Comp, class Alloc>
bool	operator!=(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs);

template<class Key, class T, class Comp, class Alloc>
bool	operator<(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs);

template<class Key, class T, class Comp, class Alloc>
bool	operator<=(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs);

template<class Key, class T, class Comp, class Alloc>
bool	operator>(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs);

template<class Key, class T, class Comp, class Alloc>
bool	operator>=(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs);

}

# include "map.tpp"

#endif
