
#ifndef SET_TPP
# define SET_TPP

# include "set.hpp"
# include "../utilities/make_pair.hpp"

namespace ft
{

/*
 * Constructors
 */

template<class T, class Comp, class Alloc>
set<T, Comp, Alloc>::set(key_compare const & comp, allocator_type const & alloc)
	: _rb_obj(comp, alloc)
{
}

template<class T, class Comp, class Alloc>
template <class InputIterator>
set<T, Comp, Alloc>::set(InputIterator first, InputIterator last,
						key_compare const & comp, allocator_type const & alloc)
	: _rb_obj(comp, alloc)
{
	this->insert(first, last);
}

template<class T, class Comp, class Alloc>
set<T, Comp, Alloc>::set(set const & x)
	: _rb_obj(x._rb_obj)
{
    this->insert(x.begin(), x.end());
}

template<class T, class Comp, class Alloc>
set<T, Comp, Alloc>::~set(void)
{
}

/*
 * copy assignment operator
 */

template<class T, class Comp, class Alloc>
set<T, Comp, Alloc>&	set<T, Comp, Alloc>::operator=(set const & rhs)
{
	if (this != &rhs)
	{
		this->_rb_obj = rhs._rb_obj;
    	this->insert(rhs.begin(), rhs.end());
	}
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
	iter = iterator(this->_rb_obj._inserted_state, &this->_rb_obj);
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

	this->_rb_obj.remove(val);
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
		return (iterator(&(this->_rb_obj._past_the_last), &this->_rb_obj));
	return (iterator(this->_rb_obj.leftmost_node(), &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::begin(void) const
{
	if (this->empty())
		return (const_iterator(&(this->_rb_obj._past_the_last), &this->_rb_obj));
	return (const_iterator(this->_rb_obj.leftmost_node(), &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::end(void)
{
	return (iterator(&(this->_rb_obj._past_the_last), &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::end(void) const
{
	return (const_iterator(&(this->_rb_obj._past_the_last), &this->_rb_obj));
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
	node<value_type>* const		lower_bound = this->_rb_obj.lower_bound(val);

	if (lower_bound == NULL)
		return (this->end());
	return (iterator(lower_bound, &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::lower_bound(value_type const & val) const
{
	const node<value_type>* const	lower_bound = this->_rb_obj.lower_bound(val);

	if (lower_bound == NULL)
		return (this->end());
	return (const_iterator(lower_bound, &this->_rb_obj));
}


template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::upper_bound(value_type const & val)
{
	node<value_type>* const		upper_bound = this->_rb_obj.upper_bound(val);

	if (upper_bound == NULL)
		return (this->end());
	return (iterator(upper_bound, &this->_rb_obj));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::upper_bound(value_type const & val) const
{
	const node<value_type>* const	upper_bound = this->_rb_obj.upper_bound(val);

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

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::key_compare	set<T, Comp, Alloc>::key_comp(void) const
{
	return (this->_rb_obj.get_key_compare());
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::value_compare	set<T, Comp, Alloc>::value_comp(void) const
{
	return (this->key_comp());
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::allocator_type	set<T, Comp, Alloc>::get_allocator(void) const
{
	return (this->_rb_obj.get_allocator());
}

/*
 * Relational operators:
 */

template<class T, class Comp, class Alloc>
bool	operator==(set<T, Comp, Alloc> const & lhs, set<T, Comp, Alloc> const & rhs)
{
	return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class T, class Comp, class Alloc>
bool	operator!=(set<T, Comp, Alloc> const & lhs, set<T, Comp, Alloc> const & rhs)
{
	return (!(lhs == rhs));
}

template<class T, class Comp, class Alloc>
bool	operator<(set<T, Comp, Alloc> const & lhs, set<T, Comp, Alloc> const & rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class T, class Comp, class Alloc>
bool	operator<=(set<T, Comp, Alloc> const & lhs, set<T, Comp, Alloc> const & rhs)
{
	return (!(rhs < lhs));
}

template<class T, class Comp, class Alloc>
bool	operator>(set<T, Comp, Alloc> const & lhs, set<T, Comp, Alloc> const & rhs)
{
	return (rhs < lhs);
}

template<class T, class Comp, class Alloc>
bool	operator>=(set<T, Comp, Alloc> const & lhs, set<T, Comp, Alloc> const & rhs)
{
	return (!(lhs < rhs));
}

}

#endif
