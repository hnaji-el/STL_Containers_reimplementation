
#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include "avl_node.hpp"
# include <algorithm>
# include <iostream>

namespace ft
{

// T: pair<key_type const, mapped_type>
// Compare: std::less<key_type>
// Alloc: allocator type for avl_node<T>

template<class T, class Compare, class AvlNodeAlloc>
class avl_tree
{
public:
	avl_node<T>*	root;
	size_t	size;
	Compare	comp;
    AvlNodeAlloc    alloc;
    avl_node<T>     past_the_last;
    avl_node<T>*    inserted_state;

public:
	// Constructors && Destructor
	avl_tree(Compare const & comp);
	~avl_tree(void);

	// insert, remove, search and clear_avl
	avl_node<T>*	insert(avl_node<T>* root, T const & data);
	avl_node<T>*	remove(avl_node<T>* root, typename T::first_type const & key);
	avl_node<T>*	search(avl_node<T>* root, typename T::first_type const & key) const;
    avl_node<T>*    clear_avl(avl_node<T>* root);

	// Rotations for insertion and deletion
	avl_node<T>*	ll_rotation(avl_node<T>* root);
	avl_node<T>*	rr_rotation(avl_node<T>* root);
	avl_node<T>*	lr_rotation(avl_node<T>* root);
	avl_node<T>*	rl_rotation(avl_node<T>* root);

	// height && balance factor
	int	get_height(avl_node<T>* node) const;
	int	height_of_node(avl_node<T>* node) const;
	int get_balance_factor(avl_node<T>* node) const;
	bool	is_equal(T const & a, T const & b) const;

	// inorder successor && inorder predecessor
	avl_node<T>*	inorder_successor(avl_node<T> const * root, avl_node<T> const * node) const;
	avl_node<T>*	inorder_predecessor(avl_node<T> const * root, avl_node<T> const * node) const;

    // leftmost && rightmost node of avl-tree
    avl_node<T>*	leftmost_node(avl_node<T>* root) const;
    avl_node<T>*	rightmost_node(avl_node<T>* root) const;
};

}

# include "avl_tree.tpp"

#endif
