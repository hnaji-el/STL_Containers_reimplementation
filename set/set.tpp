
#ifndef SET_TPP
# define SET_TPP

# include "set.hpp"
# include "../utilities/make_pair.hpp"

namespace ft
{

/*
 * Constructors:
 */

template<class T, class Compare, class Alloc>
set<T, Compare, Alloc>::set(key_compare const & comp, allocator_type const & alloc)
	: _rb_obj(comp)
{
}

template<class T, class Compare, class Alloc>
template <class InputIterator>
set<T, Compare, Alloc>::set(InputIterator first,
                              InputIterator last,
                              key_compare const & comp,
                              allocator_type const & alloc)
	: _rb_obj(comp)
{
    this->insert(first, last);
}

template<class T, class Compare, class Alloc>
set<T, Compare, Alloc>::set(set const & x)
	: _rb_obj(x.key_comp())
{
    this->insert(x.begin(), x.end());
}

template<class T, class Compare, class Alloc>
set<T, Compare, Alloc>::~set(void)
{
}

/*
 * copy assignment operator
 */

template<class Key, class T, class Comp, class Alloc>
map<Key, T, Comp, Alloc>&   map<Key, T, Comp, Alloc>::operator=(map const & rhs)
{
    this->clear();
    this->insert(rhs.begin(), rhs.end());
    this->_comp = this->_avl_obj.comp = rhs.key_comp();
    return (*this);
}


/*
 * Modifiers: [ insert ]
 */

template<class T, class Comp, class Alloc>
pair<typename set<T, Comp, Alloc>::iterator, bool>	set<T, Comp, Alloc>::insert(value_type const & val)
{
	iterator		iter;
	size_type const	old_size = this->_rb_obj.size();

	this->_rb_obj.insert(val);
	iter = iterator(&this->_rb_obj, this->_rb_obj._inserted_state);
	if (old_size == this->_rb_obj.size())
	    return (ft::make_pair(iter, false));
	return (ft::make_pair(iter, true));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::insert(iterator, value_type const & val)
{
	return (this->insert(val).first);
}

template<class T, class Comp, class Alloc>
template<class InputIterator>
void	set<T, Comp, Alloc>::insert(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}

/*
 * Modifiers: [ erase ]
 */

template<class T, class Comp, class Alloc>
void	set<T, Comp, Alloc>::erase(iterator position)
{
	this->_rb_obj.remove(*position);
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::size_type	set<T, Comp, Alloc>::erase(value_type const & val)
{
	size_type const		old_size = this->_rb_obj.size();

	this->_rb_obj.remove(k);
	if (old_size == this->_rb_obj.size())
		return (0);
	return (1);
}

template<class T, class Comp, class Alloc>
void	set<T, Comp, Alloc>::erase(iterator first, iterator last)
{
	iterator	save = first;
	
	while (first != last)
	{
		save++;
		this->erase(*first);
		first = save;
	}
}

/*
 * Modifiers: [ clear  && swap ]
 */

template<class T, class Comp, class Alloc>
void	set<T, Comp, Alloc>::clear(void)
{
	this->_rb_obj.clear_rb();
}

template<class T, class Comp, class Alloc>
void	set<T, Comp, Alloc>::swap(set& x)
{
	this->_rb_obj.swap(x._rb_obj);
}

template<class T, class Comp, class Alloc>
void	swap(set<T, Comp, Alloc>& x, set<T, Comp, Alloc>& y)
{
	x.swap(y);
}

/*
 * Iterators:
 */

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::begin(void)
{
	if (this->empty())
		return (iterator(&(this->_rb_obj.past_the_last), &this->_rb_obj));
	return (iterator(this->_rb_obj.leftmost_node(), &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::begin(void) const
{
	if (this->empty())
		return (const_iterator(&(this->_rb_obj.past_the_last), &this->_rb_obj));
	return (const_iterator(this->_rb_obj.leftmost_node(), &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::end(void)
{
	return (iterator(&(this->_rb_obj.past_the_last), &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::end(void) const
{
	return (const_iterator(&(this->_rb_obj.past_the_last), &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::reverse_iterator	set<T, Comp, Alloc>::rbegin(void)
{
	return (reverse_iterator(this->end()));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_reverse_iterator	set<T, Comp, Alloc>::rbegin(void) const
{
	return (const_reverse_iterator(this->end()));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::reverse_iterator	set<T, Comp, Alloc>::rend(void)
{
	return (reverse_iterator(this->begin()));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_reverse_iterator	set<T, Comp, Alloc>::rend(void) const
{
	return (const_reverse_iterator(this->begin()));
}

/*
 * Capacity: [ empty && size && max_size ]
 */

template<class T, class Comp, class Alloc>
bool	set<T, Comp, Alloc>::empty(void) const
{
	return (this->_rb_obj.is_empty());
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::size_type	set<T, Comp, Alloc>::size(void) const
{
    return (this->_rb_obj.size());
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::size_type	set<T, Comp, Alloc>::max_size(void) const
{
    return (this->_rb_obj.max_size());
}

/*
 * Operations: [ find && count ]
 */

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::find(value_type const & val)
{
	node<value_type>* const		temp = this->_rb_obj.search(val);

	if (temp == NULL)
		return (this->end());
	return (iterator(temp, &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::find(value_type const & val) const
{
	const node<value_type>* const	temp = this->_rb_obj.search(val);
	
	if (temp == NULL)
		return (this->end());
	return (const_iterator(temp, &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::size_type	set<T, Comp, Alloc>::count(value_type const & val) const
{
	if (this->_rb_obj.search(val) == NULL)
		return (0);
	return (1);
}

/*
 * Operations: [ lower_bound && upper_bound && equal_range ]
 */

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::lower_bound(value_type const & val)
{
	node<value_type>* const		lower_bound = this->_rb.obj.lower_bound(val);

	if (lower_bound == NULL)
		return (this->end());
	return (iterator(lower_bound, &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::lower_bound(value_type const & val) const
{
	const node<value_type>* const	lower_bound = this->_rb.obj.lower_bound(val);

	if (lower_bound == NULL)
		return (this->end());
	return (const_iterator(lower_bound, &this->_rb_obj));
}


template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::upper_bound(value_type const & val)
{
	node<value_type>* const		upper_bound = this->_rb.obj.upper_bound(val);

	if (upper_bound == NULL)
		return (this->end());
	return (iterator(upper_bound, &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::upper_bound(value_type const & val) const
{
	const node<value_type>* const	upper_bound = this->_rb.obj.upper_bound(val);

	if (upper_bound == NULL)
		return (this->end());
	return (const_iterator(upper_bound, &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
ft::pair<typename set<T, Comp, Alloc>::iterator, typename set<T, Comp, Alloc>::iterator>
set<T, Comp, Alloc>::equal_range(value_type const & val)
{
    return (ft::make_pair(this->lower_bound(val), this->upper_bound(val)));
}

template<class T, class Comp, class Alloc>
ft::pair<typename set<T, Comp, Alloc>::const_iterator, typename set<T, Comp, Alloc>::const_iterator>
set<T, Comp, Alloc>::equal_range(value_type const & val) const
{
    return (ft::make_pair(this->lower_bound(val), this->upper_bound(val)));
}

/*
 * Observers:
 */

template<class T, class Compare, class Alloc>
typename set<T, Compate, Alloc>::key_compare	set<T, Comp, Alloc>::key_comp(void) const
{
	return (this->_rb_obj.get_key_compare());
}

template<class T, class Compare, class Alloc>
typename set<T, Compare, Alloc>::value_compare	set<T, Comp, Alloc>::value_comp(void) const
{
	return (this->key_comp());
}

template<class T, class Compare, class Alloc>
Alloc	set<T, Comp, Alloc>::get_allocator(void) const
{
	return (this->_rb_obj.get_allocator());
}

/*
 * Relational operators:
 */

template < class Key, class T, class Comp, class Alloc >
bool    operator==(const map<Key, T, Comp, Alloc> &lhs, const map<Key, T, Comp, Alloc> &rhs)
{
    return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template < class Key, class T, class Comp, class Alloc >
bool    operator!=(const map<Key, T, Comp, Alloc> &lhs, const map<Key, T, Comp, Alloc> &rhs)
{
    return !(lhs == rhs);
}

template < class Key, class T, class Comp, class Alloc >
bool    operator< (const map<Key, T, Comp, Alloc> &lhs, const map<Key, T, Comp, Alloc> &rhs)
{
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template < class Key, class T, class Comp, class Alloc >
bool    operator<= (const map<Key, T, Comp, Alloc> &lhs, const map<Key, T, Comp, Alloc> &rhs)
{
    return (!(rhs < lhs));
}

template < class Key, class T, class Comp, class Alloc >
bool    operator> (const map<Key, T, Comp, Alloc> &lhs, const map<Key, T, Comp, Alloc> &rhs)
{
    return (rhs < lhs);
}

template < class Key, class T, class Comp, class Alloc >
bool    operator>= (const map<Key, T, Comp, Alloc> &lhs, const map<Key, T, Comp, Alloc> &rhs)
{
    return (!(lhs < rhs));
}

}

#endif
