
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
	: _avl_obj(comp), _comp(comp), _alloc(alloc)
{
}

template<class Key, class T, class Comp, class Alloc>
template <class InputIterator>
map<Key, T, Comp, Alloc>::map(InputIterator first,
                              InputIterator last,
                              key_compare const & comp,
                              allocator_type const & alloc)
	: _avl_obj(comp), _comp(comp), _alloc(alloc)
{
    this->insert(first, last);
}

template<class Key, class T, class Comp, class Alloc>
map<Key, T, Comp, Alloc>::map(map const & x)
	: _avl_obj(x.key_comp()), _comp(x.key_comp()), _alloc(x.get_allocator())
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
map<Key, T, Comp, Alloc>&   map<Key, T, Comp, Alloc>::operator=(map const & rhs)
{
    this->clear();
    this->insert(rhs.begin(), rhs.end());
    this->_comp = this->_avl_obj.comp = rhs.key_comp();
    return (*this);
}

/*
 * Iterators:
 */

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator map<Key, T, Comp, Alloc>::begin(void)
{
    if (this->_avl_obj.root == NULL)
        return (iterator(&(this->_avl_obj), &(this->_avl_obj.past_the_last)));
    return (iterator(&(this->_avl_obj), this->_avl_obj.leftmost_node(this->_avl_obj.root)));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator   map<Key, T, Comp, Alloc>::begin(void) const
{
    if (this->_avl_obj.root == NULL)
        return (const_iterator(&(this->_avl_obj), &(this->_avl_obj.past_the_last)));
    return (const_iterator(&(this->_avl_obj), this->_avl_obj.leftmost_node(this->_avl_obj.root)));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator map<Key, T, Comp, Alloc>::end(void)
{
    return (iterator(&(this->_avl_obj), &(this->_avl_obj.past_the_last)));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_iterator   map<Key, T, Comp, Alloc>::end(void) const
{
    return (const_iterator(&(this->_avl_obj), &(this->_avl_obj.past_the_last)));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::reverse_iterator map<Key, T, Comp, Alloc>::rbegin(void)
{
    return (reverse_iterator(this->end()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_reverse_iterator   map<Key, T, Comp, Alloc>::rbegin(void) const
{
    return (const_reverse_iterator(this->end()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::reverse_iterator map<Key, T, Comp, Alloc>::rend(void)
{
    return (reverse_iterator(this->begin()));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::const_reverse_iterator   map<Key, T, Comp, Alloc>::rend(void) const
{
    return (const_reverse_iterator(this->begin()));
}

/*
 * Modifiers: [ insert ]
 */

template<class Key, class T, class Comp, class Alloc>
pair<typename map<Key, T, Comp, Alloc>::iterator, bool>	map<Key, T, Comp, Alloc>::insert(value_type const & val)
{
    size_type   size = this->_avl_obj.size;
    iterator    iter;

	this->_avl_obj.root = this->_avl_obj.insert(this->_avl_obj.root, val);
    iter = iterator(&(this->_avl_obj), this->_avl_obj.inserted_state);
    if (size == this->_avl_obj.size)
        return (ft::make_pair(iter, false));
    return (ft::make_pair(iter, true));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::iterator	map<Key, T, Comp, Alloc>::insert(iterator position, value_type const & val)
{
    if (position->first == val.first)
        return (position);
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
void    map<Key, T, Comp, Alloc>::erase(iterator position)
{
    this->_avl_obj.root = this->_avl_obj.remove(this->_avl_obj.root, position->first);
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::size_type   map<Key, T, Comp, Alloc>::erase(key_type const & k)
{
    size_type const size = this->_avl_obj.size;

    this->_avl_obj.root = this->_avl_obj.remove(this->_avl_obj.root, k);
    if (size == this->_avl_obj.size)
        return (0);
    return (1);
}

template<class Key, class T, class Comp, class Alloc>
void    map<Key, T, Comp, Alloc>::erase(iterator first, iterator last)
{
    typedef typename allocator_type::template rebind<key_type>::other   key_type_alloc;

    key_type_alloc  key_alloc;
    key_type*   ptr;
    size_t  num_of_element = 0;

    for (iterator it = first; it != last; it++)
        num_of_element++;

    ptr = key_alloc.allocate(num_of_element);
    for (size_t i = 0; first != last; i++, first++)
        key_alloc.construct(ptr + i, first->first);

    for (size_t i = 0; i < num_of_element; i++)
    {
        this->erase(ptr[i]);
        key_alloc.destroy(ptr + i);
    }
    key_alloc.deallocate(ptr, num_of_element);
}

/*
 * Modifiers: [ clear  && swap ]
 */

template<class Key, class T, class Comp, class Alloc>
void   map<Key, T, Comp, Alloc>::clear(void)
{
    this->_avl_obj.root = this->_avl_obj.clear_avl(this->_avl_obj.root);
}

template<class Key, class T, class Comp, class Alloc>
void    map<Key, T, Comp, Alloc>::swap(map& x)
{
    std::swap(this->_comp, x._comp);
    std::swap(this->_alloc, x._alloc);
    std::swap(this->_avl_obj.root, x._avl_obj.root);
    std::swap(this->_avl_obj.size, x._avl_obj.size);
    std::swap(this->_avl_obj.comp, x._avl_obj.comp);
    std::swap(this->_avl_obj.alloc, x._avl_obj.alloc);
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
 * Capacity: [ empty && size && max_size ]
 */

template<class Key, class T, class Comp, class Alloc>
bool    map<Key, T, Comp, Alloc>::empty(void) const
{
    return (this->_avl_obj.size == 0);
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::size_type    map<Key, T, Comp, Alloc>::size(void) const
{
    return (this->_avl_obj.size);
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

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::key_compare	map<Key, T, Comp, Alloc>::key_comp(void) const
{
	return (this->_comp);
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::value_compare	map<Key, T, Comp, Alloc>::value_comp(void) const
{
    return (value_compare(this->_comp));
}

template<class Key, class T, class Comp, class Alloc>
typename map<Key, T, Comp, Alloc>::allocator_type	map<Key, T, Comp, Alloc>::get_allocator(void) const
{
	return (this->_alloc);
}

template< class Key, class T, class Compare, class Alloc >
void    swap(map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs )
{
    lhs.swap(rhs);
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

