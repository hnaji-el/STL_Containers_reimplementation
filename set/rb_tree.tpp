
#ifndef RB_TREE_TPP
# define RB_TREE_TPP

namespace ft
{

/*
 * constructors && destructor
 */

template<class T, class Comp, class NodeAlloc>
rb_tree<T, Comp, NodeAlloc>::rb_tree(Comp const & comp)
	: root(), size(), comp(comp), alloc(), past_the_last(), inserted_state()
{
}

template<class T, class Comp, class NodeAlloc>
rb_tree<T, Comp, NodeAlloc>::~rb_tree(void)
{
    this->root = this->clear_rb(this->root);
}

/*
 * search && clear_rb && insert && remove
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::search(node<T>* root, T const & key) const
{
    if (root == NULL)
        return (root);
    else if (this->comp(key, root->key) == true)
        return (search(root->left, key));
    else if (this->comp(root->key, key) == true)
        return (search(root->right, key));
    return (root);
}

template<class T, class Comp, class NodeAlloc>
node<T>*    rb_tree<T, Comp, NodeAlloc>::clear_rb(node<T>* root)
{
    if (root == NULL)
        return (NULL);
    clear_avl(root->left);
    clear_avl(root->right);
    this->alloc.destroy(root); this->alloc.deallocate(root, 1);
    this->size--;
    return (NULL);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::insert(node<T>* root, T const & key)
{
	// insert node
	if (root == NULL)
	{
		root = this->alloc.allocate(1); this->alloc.construct(root, node<T>(key));
		this->inserted_state = root;
		this->size++;
		return (root);
	}
	else if (this->comp(data.first, root->data.first) == true)
		root->left = insert(root->left, data);
	else if (this->comp(root->data.first, data.first) == true)
		root->right = insert(root->right, data);
	else
	{
		this->inserted_state = root;
		return (root);
	}

	// balance Red-Black tree if unbalanced
	if (!is_red(root->left) && is_red(root->right))
		root = left_rotation(root);
	if (is_red(root->left) && is_red(root->left->left))
		root = right_rotation(root);
	if (is_red(root->left) && is_red(root->right))
		color_flip(root);

	return (root);
}

template<class T, class Comp, class NodeAlloc>
void	rb_tree<T, Comp, NodeAlloc>::remove(T const & key)
{
	this->root = this->remove(this->root, key);
	if (this->size > 0)
		this->root->color = BLACK;
}

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::remove(node<T>* root, T const & key)
{
	if (root == NULL)
		return (NULL);

	if (this->comp(key, root->key) == true) // move to left
	{
		if (root->left && !is_red(root->left) && !is_red(root->left->left))
			root = move_red_to_left(root);
		root->left = this->remove(root->left, key);
	}
	else if (this->comp(root->key, key) == true) // move to right
	{
		if (root->right && !is_red(root->right) && !is_red(root->right->left))
			root = move_red_to_right(root);
		root->right = this->remove(root->right, key);
	}
	else
	{
		if (root->left == NULL && root->right == NULL) // leaf node
		{
			this->alloc.destroy(root); this->alloc.deallocate(root, 1);
			this->size--;
			return (NULL);
		}
		else if (root->left != NULL && root->right == NULL) // node has one child on the left-subtree
		{
			root = this->right_rotation(root);
			root->right = this->remove(root->right, key);
		}
		else if (root->left != NULL && root->right != NULL) // internal node
		{
			root->key = this->inorder_successor(root)->key; // ATT: if root->key is const ...
			if (!is_red(root->right) && !is_red(root->right->left))
				root = move_red_to_right(root);
			root->right = this->remove(root->right, root->key);
		}
	}
	// transformations on the way-up the search path.
	return (fix_up(root));
}

/*
 * 3 ELEMENTARY OPERATIONS: [ right_rotation && left_rotation && color_flip ]
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::left_rotation(node<T>* node)
{
	node<T>* rptr = node->right;

	node->right = rptr->left;
	rptr->left = node;

	// recoloring (node, rptr)
	rptr->color = node->color;
	node->color = RED;

	return (rptr);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::right_rotation(node<T>* node)
{
	node<T>* lptr = node->left;

	node->left = lptr->right;
	lptr->right = node;

	// recoloring (node, lptr)
	lptr->color = node->color;
	node->color = RED;

	return (lptr);
}

template<class T, class Comp, class NodeAlloc>
void	rb_tree<T, Comp, NodeAlloc>::color_flip(node<T>* node)
{
	node->color = !node->color;
	node->left->color = !node->left->color;
	node->right->color = !node->right->color;
}

/*
 * is_red
 */

template<class T, class Comp, class NodeAlloc>
bool	rb_tree<T, Comp, NodeAlloc>::is_red(node<T>* node)
{
	if (node == NULL)
		return (false); // NULL links are black
	return (node->color == RED);
}

/*
 * Helper member functions for remove operation
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::move_red_to_left(node<T>* node)
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

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::move_red_to_right(node<T>* node)
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

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::fix_up(node<T>* node)
{
	if (!is_red(node->left) && is_red(node->right))
		node = left_rotation(node);
	if (node->left && is_red(node->left) && is_red(node->left->left))
		node = right_rotation(node);
	if (is_red(node->left) && is_red(node->right))
		color_flip(node);
	return (node);
}

/*
 * inorder_successor && inorder_predecessor
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::inorder_successor(node<T> const * root, node<T> const * node) const
{
	node<T>*	ancestor = (node<T>*)root;
	node<T>*	successor = NULL;

	if (node == NULL || node == &(this->past_the_last))
		return (NULL);
	// case1: node has right-subtree
	if (node->right != NULL)
	{
		successor = node->right;
		while (successor->left != NULL)
			successor = successor->left;
		return (successor);
	}
	// case2: no right-subtree
	while (ancestor != node)
	{
		if (this->comp(node->data.first, ancestor->data.first) == true)
		{
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else
			ancestor = ancestor->right;
	}
	return ((successor == NULL) ? (node<T>*)(&past_the_last) : successor);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::inorder_predecessor(node<T> const * root, node<T> const * node) const
{
	node<T>*	ancestor = (node<T>*)root;
	node<T>*	predecessor = NULL;

	if (node == NULL)
		return (NULL);
    if (node == &(past_the_last))
        return (rightmost_node(ancestor));
	// case1: node has left-subtree
	if (node->left != NULL)
	{
		predecessor = node->left;
		while (predecessor->right != NULL)
			predecessor = predecessor->right;
		return (predecessor);
	}
	// case2: no left-subtree
	while (ancestor != node)
	{
		if (this->comp(ancestor->data.first, node->data.first) == true)
		{
			predecessor = ancestor;
			ancestor = ancestor->right;
		}
		else
			ancestor = ancestor->left;
	}
	return (predecessor);
}

/*
 * leftmost_node && rightmost_node
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::leftmost_node(node<T>* root) const
{
    if (root == NULL)
        return (NULL);
    while (root->left != NULL)
        root = root->left;
    return (root);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	rb_tree<T, Comp, NodeAlloc>::rightmost_node(node<T>* root) const
{
   if (root == NULL)
       return (NULL);
   while (root->right != NULL)
       root = root->right;
   return (root);
}

}

#endif
