
#ifndef RB_TREE_TPP
# define RB_TREE_TPP

namespace ft
{

/*
 * constructors && destructor
 */

template<class T, class Comp, class Alloc>
rb_tree<T, Comp, Alloc>::rb_tree(Comp const & comp, Alloc const & alloc)
	: _root(), _size(), _comp(comp), _alloc(alloc), _past_the_last(), _inserted_state(), _node_alloc()
{
}

template<class T, class Comp, class Alloc>
rb_tree<T, Comp, Alloc>::~rb_tree(void)
{
    this->clear_rb();
}

/*
 * search && clear_rb && insert && remove
 */

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::search(T const & key) const
{
	return (this->search(this->_root, key));
}

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::search(node<T>* root, T const & key) const
{
    if (root == NULL)
        return (root);
    else if (this->_comp(key, root->key) == true) // move to left
        return (search(root->left, key));
    else if (this->_comp(root->key, key) == true) // move to right
        return (search(root->right, key));
    return (root);
}

template<class T, class Comp, class Alloc>
void	rb_tree<T, Comp, Alloc>::clear_rb(void)
{
	this->clear_rb(this->_root);
	this->_root = NULL;
	this->_size = 0;
}

template<class T, class Comp, class Alloc>
void	rb_tree<T, Comp, Alloc>::clear_rb(node<T>* root)
{
    if (root == NULL)
        return ;
    clear_rb(root->left);
    clear_rb(root->right);
    this->_node_alloc.destroy(root); this->_node_alloc.deallocate(root, 1);
}

template<class T, class Comp, class Alloc>
void	rb_tree<T, Comp, Alloc>::insert(T const & key)
{
	this->_root = this->insert(this->_root, key);
	if (this->_root != NULL)
		this->_root->color = BLACK;
}

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::insert(node<T>* root, T const & key)
{
	if (root == NULL) // insert the node
	{
		root = this->_node_alloc.allocate(1); this->_node_alloc.construct(root, node<T>(key));
		this->_size++;
		this->_inserted_state = root;
		return (root);
	}
	else if (this->_comp(key, root->key) == true) // move to left
		root->left = insert(root->left, key);
	else if (this->_comp(root->key, key) == true) // move to right
		root->right = insert(root->right, key);
	else
	{
		this->_inserted_state = root;
		return (root);
	}

	// transformations on the way-up the search path to maintain invariants.
	return (fix_up(root));
}

template<class T, class Comp, class Alloc>
void	rb_tree<T, Comp, Alloc>::remove(T const & key)
{
	this->_root = this->remove(this->_root, key);
	if (this->_root != NULL)
		this->_root->color = BLACK;
}

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::remove(node<T>* root, T const & key)
{
	if (root == NULL)
		return (NULL);

	if (this->_comp(key, root->key) == true) // move to left
	{
		if (root->left && !is_red(root->left) && !is_red(root->left->left))
			root = move_red_to_left(root);
		root->left = this->remove(root->left, key);
	}
	else if (this->_comp(root->key, key) == true) // move to right
	{
		if (root->right && !is_red(root->right) && !is_red(root->right->left))
			root = move_red_to_right(root);
		root->right = this->remove(root->right, key);
	}
	else
	{
		if (root->left == NULL && root->right == NULL) // leaf node
		{
			this->_node_alloc.destroy(root); this->_node_alloc.deallocate(root, 1);
			this->_size--;
			return (NULL);
		}
		else if (root->left != NULL && root->right == NULL) // node has one child on the left-subtree
		{
			root = this->right_rotation(root);
			root->right = this->remove(root->right, key);
		}
		else if (root->left != NULL && root->right != NULL) // internal node
		{
			this->_alloc.destroy(&root->key);
			this->_alloc.construct(&root->key, this->inorder_successor(root)->key);

			if (!is_red(root->right) && !is_red(root->right->left))
				root = move_red_to_right(root);
			root->right = this->remove(root->right, root->key);
		}
	}
	// transformations on the way-up the search path to maintain invariants.
	return (fix_up(root));
}


/*
 * Helper member functions for remove operation
 */

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::move_red_to_left(node<T>* node)
{
	// if left-child of a node is a 2-node: node->left && node->left->left are blacks.
	color_flip(node);
	if (is_red(node->right->left))
	{
		node->right = right_rotation(node->right);
		node = left_rotation(node);
		color_flip(node);
	}
	return (node);
}

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::move_red_to_right(node<T>* node)
{
	// if right-child of a node is a 2-node: node->right && node->right->left are blacks.
	color_flip(node);
	if (is_red(node->left->left))
	{
		node = right_rotation(node);
		color_flip(node);
	}
	return (node);
}

/*
 * 3 ELEMENTARY OPERATIONS: [ right_rotation && left_rotation && color_flip ]
 */

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::fix_up(node<T>* node)
{
	if (!is_red(node->left) && is_red(node->right))
		node = left_rotation(node);
	if (node->left && is_red(node->left) && is_red(node->left->left))
		node = right_rotation(node);
	if (is_red(node->left) && is_red(node->right))
		color_flip(node);
	return (node);
}

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::left_rotation(node<T>* node)
{
	ft::node<T>*	rptr = node->right;

	node->right = rptr->left;
	rptr->left = node;

	// recoloring (node, rptr)
	rptr->color = node->color;
	node->color = RED;

	return (rptr);
}

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::right_rotation(node<T>* node)
{
	ft::node<T>* lptr = node->left;

	node->left = lptr->right;
	lptr->right = node;

	// recoloring (node, lptr)
	lptr->color = node->color;
	node->color = RED;

	return (lptr);
}

template<class T, class Comp, class Alloc>
void	rb_tree<T, Comp, Alloc>::color_flip(node<T>* node)
{
	node->color = !node->color;
	node->left->color = !node->left->color;
	node->right->color = !node->right->color;
}

/*
 * is_red && size && is_empty
 */


template<class T, class Comp, class Alloc>
bool	rb_tree<T, Comp, Alloc>::is_red(node<T>* node) const
{
	if (node == NULL)
		return (false); // NULL links are black
	return (node->color == RED);
}

template<class T, class Comp, class Alloc>
size_t	rb_tree<T, Comp, Alloc>::size(void) const
{
	return (this->_size);
}

template<class T, class Comp, class Alloc>
bool	rb_tree<T, Comp, Alloc>::is_empty(void) const
{
	return (this->_size == 0);
}

/*
 * inorder_successor && inorder_predecessor
 */

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::inorder_successor(node<T> const * node) const
{
	ft::node<T>*	ancestor = this->_root;
	ft::node<T>*	successor = NULL;
	
	if (this->_root == NULL || node == NULL || node == &this->_past_the_last)
		return (NULL);

	// case1: node has right-subtree
	if (node->right != NULL)
		return (leftmost_node(node->right));
	// case2: no right-subtree
	while (ancestor != node)
	{
		if (this->_comp(node->key, ancestor->key) == true) // move to left
		{
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else // move to right
			ancestor = ancestor->right;
	}
	return ((successor == NULL) ? (ft::node<T>*)(&this->_past_the_last) : successor);
}

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::inorder_predecessor(node<T> const * node) const
{
	ft::node<T>*	ancestor = this->_root;
	ft::node<T>*	predecessor = NULL;
	
	if (this->_root == NULL || node == NULL)
		return (NULL);
	if (node == &this->_past_the_last)
	    return (rightmost_node(ancestor));

	// case1: node has left-subtree
	if (node->left != NULL)
		return (this->rightmost_node(node->left));
	// case2: no left-subtree
	while (ancestor != node)
	{
		if (this->_comp(ancestor->key, node->key) == true) // move to right
		{
			predecessor = ancestor;
			ancestor = ancestor->right;
		}
		else // move to left
			ancestor = ancestor->left;
	}
	return (predecessor);
}

/*
 * leftmost_node && rightmost_node
 */

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::leftmost_node(node<T>* node) const
{
    if (node == NULL)
        return (NULL);

    while (node->left != NULL)
        node = node->left;
    return (node);
}

template<class T, class Comp, class Alloc>
node<T>*	rb_tree<T, Comp, Alloc>::rightmost_node(node<T>* node) const
{
   if (node == NULL)
       return (NULL);

   while (node->right != NULL)
       node = node->right;
   return (node);
}

}

#endif
