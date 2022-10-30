
#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include "node.hpp"
# include <algorithm>
# include <iostream>

namespace ft
{

// T: pair<key_type const, mapped_type>
// Compare: std::less<key_type>
// Alloc: allocator type for node<T>

template<class T, class Compare, class NodeAlloc>
class avl_tree
{
private:
	node<T>*	root;
	size_t		_size;
	Compare		comp;
	NodeAlloc	alloc;
public:
	node<T>		past_the_last;
	node<T>*	inserted_state;

public:
	// Constructors && Destructor
	avl_tree(Compare const & comp);
	~avl_tree(void);
	avl_tree&	operator=(avl_tree const & rhs);
	
	// insert && remove && search && clear_avl && swap
	void		insert(T const & data);
	void		remove(typename T::first_type const & key);
	node<T>*	search(typename T::first_type const & key) const;
	void		clear_avl(void);
	void		swap(avl_tree& x);

	// size && is_empty
	size_t	size(void) const;
	bool	is_empty(void) const;
	
	// height && balance factor
	int		get_height(node<T>* node) const;
	int		height_of_node(node<T>* node) const;
	int 	get_balance_factor(node<T>* node) const;
	bool	is_equal(T const & a, T const & b) const;
	
	// inorder successor && inorder predecessor
	node<T>*	inorder_successor(node<T> const * node) const;
	node<T>*	inorder_predecessor(node<T> const * node) const;

	// leftmost && rightmost node of tree
	node<T>*	leftmost_node(void) const;
	node<T>*	rightmost_node(void) const;

	// lower_bound && upper_bound
	node<T>*	lower_bound(typename T::first_type const & key) const;
	node<T>*	upper_bound(typename T::first_type const & key) const;
	
private:
	// overloaded versions of [ search && insert && remove && clear_rb ]
	node<T>*	search(node<T>* root, typename T::first_type const & key) const;
	node<T>*	insert(node<T>* root, T const & data);
	node<T>*	remove(node<T>* root, typename T::first_type const & key);
	void		clear_avl(node<T> * root);

	// 2 ELEMENTARY OPERATIONS: [ left rotation && right rotation ]
	node<T>*	ll_rotation(node<T>* root);
	node<T>*	rr_rotation(node<T>* root);
	node<T>*	lr_rotation(node<T>* root);
	node<T>*	rl_rotation(node<T>* root);
	

	// leftmost && rightmost node of a node
	node<T>*	leftmost_node(node<T>* root) const;
	node<T>*	rightmost_node(node<T>* root) const;
};

}

# include "avl_tree.tpp"

#endif
