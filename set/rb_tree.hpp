
#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "node.hpp"
# include <algorithm>
# include <iostream>

namespace ft
{

template<class T, class Compare, class NodeAlloc>
class rb_tree
{
public:
	node<T>*	root;
	size_t		size;
	Compare		comp;
	NodeAlloc	alloc;
	node<T>		past_the_last; // valid address for end-iterator
	node<T>*	inserted_state;

public:
	// Constructors && Destructor
	rb_tree(Compare const & comp);
	~rb_tree(void);
	
	// search, insert and remove operations
	node<T>*	search(node<T>* root, T const & key) const;
	node<T>*	insert(node<T>* root, T const & key);
	void		remove(void);
	node<T>*	remove(node<T>* root);
	node<T>*	clear_rb(node<T>* root);
	
	// Helper member functions for remove operation
	node<T>*	move_red_to_left(node<T>* node);
	node<T>*	move_red_to_right(node<T>* node);
	node<T>*	fix_up(node<T>* node);
	
	// 3 ELEMENTARY OPERATIONS: [ left rotation && right rotation && color flip ]
	avl_node<T>*	left_rotation(node<T>* node);
	avl_node<T>*	right_rotation(node<T>* node);
	void	color_flip(node<T>* node);
	
	// check if red
	bool	is_red(node<T>* node);
	
	// inorder successor && inorder predecessor of a node
	node<T>*	inorder_successor(node<T> const * root, node<T> const * node) const;
	node<T>*	inorder_predecessor(node<T> const * root, node<T> const * node) const;
	
	// leftmost && rightmost node of red-black-tree
	node<T>*	leftmost_node(node<T>* root) const;
	node<T>*	rightmost_node(node<T>* root) const;
};

}

# include "rb_tree.tpp"

#endif
