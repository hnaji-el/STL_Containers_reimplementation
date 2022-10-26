
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
 * Element access: [ operator[] ]
 */

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::mapped_type&    map<Key, T, Comp, Alloc>::operator[](key_type const & k)
{
    ft::pair<iterator, bool>    ret;

    ret = this->insert(ft::make_pair(k, mapped_type()));
    return (ret.first->second);
}

/*
 * Iterators:
 */

template<class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator map<Key, T, Comp, Alloc>::begin(void)
{
    if (this->_rb_obj.root == NULL)
        return (iterator(&(this->_avl_obj), &(this->_avl_obj.past_the_last)));
    return (iterator(&(this->_avl_obj), this->_avl_obj.leftmost_node(this->_avl_obj.root)));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::begin(void) const
{
	if (this->_avl_obj.root == NULL)
		return (const_iterator(&(this->_avl_obj), &(this->_avl_obj.past_the_last)));
	return (const_iterator(&(this->_avl_obj), this->_avl_obj.leftmost_node(this->_avl_obj.root)));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::iterator	set<T, Comp, Alloc>::end(void)
{
	return (iterator(&(this->_avl_obj), &(this->_avl_obj.past_the_last)));
}

template<class T, class Comp, class Alloc>
typename set<T, Comp, Alloc>::const_iterator	set<T, Comp, Alloc>::end(void) const
{
	return (const_iterator(&(this->_avl_obj), &(this->_avl_obj.past_the_last)));
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
template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator        map<Key, T, Comp, Alloc>::find(key_type const & k)
{
    avl_node<value_type>*   temp;

    temp = this->_avl_obj.search(this->_avl_obj.root, k);
    if (temp == NULL)
        return (this->end());
    return (iterator(&(this->_avl_obj), temp));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator  map<Key, T, Comp, Alloc>::find(key_type const & k) const
{
    const avl_node<value_type>* const   temp = this->_avl_obj.search(this->_avl_obj.root, k);

    if (temp == NULL)
        return (this->end());
    return (const_iterator(&(this->_avl_obj), temp));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::size_type    map<Key, T, Comp, Alloc>::count(key_type const & k) const
{
    if (this->_avl_obj.search(this->_avl_obj.root, k) == NULL)
        return (0);
    return (1);
}

/*
 * Operations: [ lower_bound && upper_bound && equal_range ]
 */

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator map<Key, T, Comp, Alloc>::lower_bound(key_type const & k)
{
    avl_node<value_type> const *    temp = this->_avl_obj.root;
    avl_node<value_type> const *    lower_bound = NULL;

    while (temp != NULL)
    {
        if (!this->_comp(temp->data.first, k) && !this->_comp(k, temp->data.first))
        {
            lower_bound = temp;
            break ;
        }
        if (this->_comp(k, temp->data.first) == true)
        {
            lower_bound = temp;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    if (lower_bound == NULL)
        return (this->end());
    return (iterator(&(this->_avl_obj), (avl_node<value_type>*)lower_bound));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator   map<Key, T, Comp, Alloc>::lower_bound(key_type const & k) const
{
    avl_node<value_type> const *    temp = this->_avl_obj.root;
    avl_node<value_type> const *    lower_bound = NULL;

    while (temp != NULL)
    {
        if (!this->_comp(temp->data.first, k) && !this->_comp(k, temp->data.first))
        {
            lower_bound = temp;
            break ;
        }
        if (this->_comp(k, temp->data.first) == true)
        {
            lower_bound = temp;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    if (lower_bound == NULL)
        return (this->end());
    return (const_iterator(&(this->_avl_obj), lower_bound));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator map<Key, T, Comp, Alloc>::upper_bound(key_type const & k)
{
    avl_node<value_type> const *    temp = this->_avl_obj.root;
    avl_node<value_type> const *    upper_bound = NULL;

    while (temp != NULL)
    {
        if (this->_comp(k, temp->data.first) == true)
        {
            upper_bound = temp;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    if (upper_bound == NULL)
        return (this->end());
    return (iterator(&(this->_avl_obj), (avl_node<value_type>*)upper_bound));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator   map<Key, T, Comp, Alloc>::upper_bound(key_type const & k) const
{
    avl_node<value_type> const *    temp = this->_avl_obj.root;
    avl_node<value_type> const *    upper_bound = NULL;

    while (temp != NULL)
    {
        if (this->_comp(k, temp->data.first) == true)
        {
            upper_bound = temp;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    if (upper_bound == NULL)
        return (this->end());
    return (const_iterator(&(this->_avl_obj), upper_bound));
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

template<class T, class Compare, class Alloc>
Compare	set<T, Comp, Alloc>::key_comp(void) const
{
	return (this->_rb_obj.get_key_compare());
}

template<class T, class Compare, class Alloc>
Compare	set<T, Comp, Alloc>::value_comp(void) const
{
	return (this->_rb_obj.get_key_compare());
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

