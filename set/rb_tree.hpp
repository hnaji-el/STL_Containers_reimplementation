
#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "node.hpp"
# include <algorithm>
# include <iostream>
# include <functional>
# include <memory>

namespace ft
{

template<class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class rb_tree
{
private:
	node<T>*	_root;
	size_t		_size;
	Compare		_comp;
	Alloc		_alloc;
	node<T>		_past_the_last; // valid address for end-iterator
	node<T>*	_inserted_state;

	typedef typename Alloc::template rebind< node<T> >::other	NodeAlloc;
	NodeAlloc	_node_alloc;


public:
	// Constructors && Destructor
	rb_tree(Compare const & comp = Compare(), Alloc const & alloc = Alloc());
	~rb_tree(void);
	
	// search, insert and remove operations of red-black tree
	node<T>*	search(T const & key) const;
	void		insert(T const & key);
	void		remove(T const & key);
	void		clear_rb(void);

	// size && is_empty
	size_t	size(void) const;
	bool	is_empty(void) const;
	
	// inorder successor && inorder predecessor of a node
	node<T>*	inorder_successor(node<T> const * node) const;
	node<T>*	inorder_predecessor(node<T> const * node) const;

private:
	// overloaded versions of [ search && insert && remove && clear_rb ]
	node<T>*	search(node<T>* root, T const & key) const;
	node<T>*	insert(node<T>* root, T const & key);
	node<T>*	remove(node<T>* root, T const & key);
	void		clear_rb(node<T>* root);

	// 3 ELEMENTARY OPERATIONS: [ left rotation && right rotation && color flip ]
	node<T>*	left_rotation(node<T>* node);
	node<T>*	right_rotation(node<T>* node);
	void		color_flip(node<T>* node);
	node<T>*	fix_up(node<T>* node);

	// Helper member functions for remove operation
	node<T>*	move_red_to_left(node<T>* node);
	node<T>*	move_red_to_right(node<T>* node);
	bool		is_red(node<T>* node) const;

	// leftmost && rightmost node of a node
	node<T>*	leftmost_node(node<T>* node) const;
	node<T>*	rightmost_node(node<T>* node) const;

};

}

# include "rb_tree.tpp"

#endif
