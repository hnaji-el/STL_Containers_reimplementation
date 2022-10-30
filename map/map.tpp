
#ifndef MAP_TPP
# define MAP_TPP

# include "map.hpp"
# include "../utilities/make_pair.hpp"

namespace ft
{

/*
 * Constructors:
 */

template<class Key, class T, class Comp, class Alloc>
map<Key, T, Comp, Alloc>::map(key_compare const & comp, allocator_type const & alloc)
	: _avl_obj(comp, alloc)
{
}

template<class Key, class T, class Comp, class Alloc>
template <class InputIterator>
map<Key, T, Comp, Alloc>::map(InputIterator first, InputIterator last,
								key_compare const & comp, allocator_type const & alloc)
	: _avl_obj(comp, alloc)
{
    this->insert(first, last);
}

template<class Key, class T, class Comp, class Alloc>
map<Key, T, Comp, Alloc>::map(map const & x)
	: _avl_obj(x.key_comp(), x.get_allocator())
{
    this->insert(x.begin(), x.end());
}

template<class Key, class T, class Comp, class Alloc>
map<Key, T, Comp, Alloc>::~map(void)
{
}

/*
 * copy assignment operator
 */

template<class Key, class T, class Comp, class Alloc>
map<Key, T, Comp, Alloc>&	map<Key, T, Comp, Alloc>::operator=(map const & rhs)
{
	if (this != &rhs)
	{
		this->_avl_obj = rhs._avl_obj;
    	this->insert(rhs.begin(), rhs.end());
	}
    return (*this);
}

/*
 * Modifiers: [ insert ]
 */

template<class Key, class T, class Comp, class Alloc>
pair<typename map<Key, T, Comp, Alloc>::iterator, bool>	map<Key, T, Comp, Alloc>::insert(value_type const & val)
{
    iterator    	iter;
    size_type const	size = this->_avl_obj.size();

	this->_avl_obj.insert(val);
    iter = iterator(&this->_avl_obj, this->_avl_obj.inserted_state);
    if (size == this->_avl_obj.size())
        return (ft::make_pair(iter, false));
    return (ft::make_pair(iter, true));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator	map<Key, T, Comp, Alloc>::insert(iterator, value_type const & val)
{
    return (this->insert(val).first);
}

template<class Key, class T, class Comp, class Alloc>
template<class InputIterator>
void	map<Key, T, Comp, Alloc>::insert(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		this->insert(*first);
		first++;
	}
}

/*
 * Modifiers: [ erase ]
 */

template<class Key, class T, class Comp, class Alloc>
void	map<Key, T, Comp, Alloc>::erase(iterator position)
{
	this->_avl_obj.remove(position->first);
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::size_type	map<Key, T, Comp, Alloc>::erase(key_type const & k)
{
	size_type const		size = this->_avl_obj.size();

	this->_avl_obj.remove(k);
	if (size == this->_avl_obj.size())
		return (0);
	return (1);
}

template<class Key, class T, class Comp, class Alloc>
void    map<Key, T, Comp, Alloc>::erase(iterator first, iterator last)
{
	iterator	save(first);

	while (first != last)
	{
		++save;
		this->erase(first);
		first = save;
	}
}

/*
 * Modifiers: [ clear  && swap ]
 */

template<class Key, class T, class Comp, class Alloc>
void   map<Key, T, Comp, Alloc>::clear(void)
{
	this->_avl_obj.clear_avl();
}

template<class Key, class T, class Comp, class Alloc>
void    map<Key, T, Comp, Alloc>::swap(map& x)
{
	this->_avl_obj.swap(x._avl_obj);
}

template<class Key, class T, class Comp, class Alloc>
void	swap(map<Key, T, Comp, Alloc>& lhs, map<Key, T, Comp, Alloc>& rhs)
{
	lhs.swap(rhs);
}

/*
 * Iterators:
 */

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator	map<Key, T, Comp, Alloc>::begin(void)
{
	if (this->empty())
		return (iterator(&this->_avl_obj, &this->_avl_obj.past_the_last));
	return (iterator(&this->_avl_obj, this->_avl_obj.leftmost_node()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator	map<Key, T, Comp, Alloc>::begin(void) const
{
	if (this->empty())
		return (const_iterator(&this->_avl_obj, &this->_avl_obj.past_the_last));
	return (const_iterator(&this->_avl_obj, this->_avl_obj.leftmost_node()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator	map<Key, T, Comp, Alloc>::end(void)
{
	return (iterator(&this->_avl_obj, &this->_avl_obj.past_the_last));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator	map<Key, T, Comp, Alloc>::end(void) const
{
	return (const_iterator(&this->_avl_obj, &this->_avl_obj.past_the_last));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::reverse_iterator	map<Key, T, Comp, Alloc>::rbegin(void)
{
	return (reverse_iterator(this->end()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_reverse_iterator	map<Key, T, Comp, Alloc>::rbegin(void) const
{
	return (const_reverse_iterator(this->end()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::reverse_iterator	map<Key, T, Comp, Alloc>::rend(void)
{
	return (reverse_iterator(this->begin()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_reverse_iterator	map<Key, T, Comp, Alloc>::rend(void) const
{
	return (const_reverse_iterator(this->begin()));
}

/*
 * Element access: [ operator[] ]
 */

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::mapped_type&		map<Key, T, Comp, Alloc>::operator[](key_type const & k)
{
	ft::pair<iterator, bool>	ret;

	ret = this->insert(ft::make_pair(k, mapped_type()));
	return (ret.first->second);
}

/*
 * Capacity: [ empty && size && max_size ]
 */

template<class Key, class T, class Comp, class Alloc>
bool	map<Key, T, Comp, Alloc>::empty(void) const
{
	return (this->_avl_obj.is_empty());
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::size_type	map<Key, T, Comp, Alloc>::size(void) const
{
	return (this->_avl_obj.size());
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::size_type    map<Key, T, Comp, Alloc>::max_size(void) const
{
    return (this->_alloc.max_size());
}

/*
 * Operations: [ find && count ]
 */

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator		map<Key, T, Comp, Alloc>::find(key_type const & k)
{
	node<value_type>* const		temp = this->_avl_obj.search(k);

	if (temp == NULL)
		return (this->end());
	return (iterator(&this->_avl_obj, temp));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator	map<Key, T, Comp, Alloc>::find(key_type const & k) const
{
	const node<value_type>* const	temp = this->_avl_obj.search(k);

	if (temp == NULL)
		return (this->end());
	return (const_iterator(&this->_avl_obj, temp));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::size_type	map<Key, T, Comp, Alloc>::count(key_type const & k) const
{
	if (this->_avl_obj.search(k) == NULL)
		return (0);
	return (1);
}

/*
 * Operations: [ lower_bound && upper_bound && equal_range ]
 */

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator	map<Key, T, Comp, Alloc>::lower_bound(key_type const & k)
{
	node<value_type>* const		lower_bound = this->_avl_obj.lower_bound(k);

	if (lower_bound == NULL)
		return (this->end());
	return (iterator(&this->_avl_obj, lower_bound));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator	map<Key, T, Comp, Alloc>::lower_bound(key_type const & k) const
{
	const node<value_type>* const	lower_bound = this->_avl_obj.lower_bound(k);

	if (lower_bound == NULL)
		return (this->end());
	return (const_iterator(&this->_avl_obj, lower_bound));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator	map<Key, T, Comp, Alloc>::upper_bound(key_type const & k)
{
	node<value_type>* const		upper_bound = this->_avl_obj.upper_bound(k);

    if (upper_bound == NULL)
        return (this->end());
    return (iterator(&this->_avl_obj, upper_bound));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator	map<Key, T, Comp, Alloc>::upper_bound(key_type const & k) const
{
	const node<value_type>* const	upper_bound = this->_avl_obj.upper_bound(k);

    if (upper_bound == NULL)
        return (this->end());
    return (const_iterator(&this->_avl_obj, upper_bound));
}

template<class Key, class T, class Comp, class Alloc>
ft::pair<typename map<Key, T, Comp, Alloc>::iterator, typename map<Key, T, Comp, Alloc>::iterator>
map<Key, T, Comp, Alloc>::equal_range(key_type const & k)
{
    return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
}

template<class Key, class T, class Comp, class Alloc>
ft::pair<typename map<Key, T, Comp, Alloc>::const_iterator, typename map<Key, T, Comp, Alloc>::const_iterator>
map<Key, T, Comp, Alloc>::equal_range(key_type const & k) const
{
    return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
}

/*
 * Observers:
 */

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::key_compare	map<Key, T, Comp, Alloc>::key_comp(void) const
{
	return (this->_avl_obj.get_key_compare());
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::value_compare	map<Key, T, Comp, Alloc>::value_comp(void) const
{
	return (value_compare(this->key_comp()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::allocator_type	map<Key, T, Comp, Alloc>::get_allocator(void) const
{
	return (this->_avl_obj.get_allocator());
}

/*
 * Relational operators:
 */

template<class Key, class T, class Comp, class Alloc>
bool	operator==(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs)
{
	return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class Key, class T, class Comp, class Alloc>
bool	operator!=(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs)
{
	return (!(lhs == rhs));
}

template<class Key, class T, class Comp, class Alloc>
bool	operator<(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class Key, class T, class Comp, class Alloc>
bool	operator<=(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs)
{
	return (!(rhs < lhs));
}

template<class Key, class T, class Comp, class Alloc>
bool	operator>(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs)
{
	return (rhs < lhs);
}

template<class Key, class T, class Comp, class Alloc>
bool	operator>=(map<Key, T, Comp, Alloc> const & lhs, map<Key, T, Comp, Alloc> const & rhs)
{
	return (!(lhs < rhs));
}

}

#endif

