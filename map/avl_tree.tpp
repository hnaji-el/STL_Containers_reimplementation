
#ifndef AVL_TREE_TPP
# define AVL_TREE_TPP

namespace ft
{

/*
 * constructors && destructor
 */

template<class T, class Compare, class AvlNodeAlloc>
avl_tree<T, Compare, AvlNodeAlloc>::avl_tree(Compare const & comp)
    : root(), size(), comp(comp), alloc(), past_the_last(), inserted_state()
{
}

template<class T, class Compare, class AvlNodeAlloc>
avl_tree<T, Compare, AvlNodeAlloc>::~avl_tree(void)
{
    this->root = this->clear_avl(this->root);
}

/*
 * search && clear_avl && insert && remove
 */

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::search(avl_node<T>* root, typename T::first_type const & key) const
{
    if (root == NULL)
        return (root);
    else if (this->comp(key, root->data.first) == true)
        return (search(root->left, key));
    else if (this->comp(root->data.first, key) == true)
        return (search(root->right, key));
    return (root);
}

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*    avl_tree<T, Compare, AvlNodeAlloc>::clear_avl(avl_node<T>* root)
{
    if (root == NULL)
        return (NULL);
    clear_avl(root->left);
    clear_avl(root->right);
    this->alloc.destroy(root); this->alloc.deallocate(root, 1);
    this->size--;
    return (NULL);
}

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::insert(avl_node<T>* root, T const & data)
{
	int	balance_factor;

    if (root == NULL)
	{
		root = this->alloc.allocate(1); this->alloc.construct(root, avl_node<T>(data));
		this->inserted_state = root;
		this->size++;
		return (root);
	}
    else if (this->comp(data.first, root->data.first) == true)
		root->left = insert(root->left, data);
    else if (this->comp(root->data.first, data.first) == true)
		root->right = insert(root->right, data);
    else if (is_equal(data, root->data) == true)
    {
        this->inserted_state = root;
        return (root);
    }

	// update height && balance_factor
	root->height = height_of_node(root);
	balance_factor = get_balance_factor(root);

	// check if balance or imbalance then balance it if imbalance.
	if (balance_factor == 2 && get_balance_factor(root->left) == 1)
		root = ll_rotation(root);
	else if (balance_factor == 2 && get_balance_factor(root->left) == -1)
		root = lr_rotation(root);
	else if (balance_factor == -2 && get_balance_factor(root->right) == 1)
		root = rl_rotation(root);
	else if (balance_factor == -2 && get_balance_factor(root->right) == -1)
		root = rr_rotation(root);

	return (root);
}

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::remove(avl_node<T>* root, typename T::first_type const & key)
{
	int	balance_factor;

	if (root == NULL)
		return (NULL);
	else if (this->comp(key, root->data.first) == true)
		root->left = remove(root->left, key);
	else if (this->comp(root->data.first, key) == true)
		root->right = remove(root->right, key);
	// case#1: leaf node
	else if (root->left == NULL && root->right == NULL)
	{
		this->alloc.destroy(root); this->alloc.deallocate(root, 1);
		this->size--;
		return (NULL);
	}
	// case#2: node with 1 Children
	else if (root->left == NULL)
	{
		avl_node<T>*	rptr = root->right;
		this->alloc.destroy(root); this->alloc.deallocate(root, 1);
		this->size--;
		root = rptr;
	}
	else if (root->right == NULL)
	{
		avl_node<T>*	lptr = root->left;
		this->alloc.destroy(root); this->alloc.deallocate(root, 1);
		this->size--;
		root = lptr;
	}
	// case#2: node with 2 Children
	else if (root->left != NULL && root->right != NULL)
	{
		avl_node<T>*	succ_node = this->inorder_successor(root, root);
		avl_node<T>*	temp = root;

		root = this->alloc.allocate(1); this->alloc.construct(root, *succ_node);

		root->left = temp->left;
		root->right = temp->right;
		root->height = temp->height;

		this->alloc.destroy(temp); this->alloc.deallocate(temp, 1);
		root->right = remove(root->right, root->data.first);
	}

	// update height && balance_factor
	root->height = height_of_node(root);
	balance_factor = get_balance_factor(root);

	// check if balance or impalance then balance it if impalance.
	if (balance_factor == 2 && get_balance_factor(root->left) >= 0)
		root = ll_rotation(root);
	else if (balance_factor == 2 && get_balance_factor(root->left) == -1)
		root = lr_rotation(root);
	else if (balance_factor == -2 && get_balance_factor(root->right) <= 0)
		root = rr_rotation(root);
	else if (balance_factor == -2 && get_balance_factor(root->right) == 1)
		root = rl_rotation(root);

	return (root);
}

/*
 * Rotations for insertion and deletion
 */

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::ll_rotation(avl_node<T>* root)
{
	avl_node<T>* lptr = root->left;

	root->left = lptr->right;
	lptr->right = root;

	// update height of (root, lptr)
	root->height = height_of_node(root);
	lptr->height = height_of_node(lptr);

	return (lptr);
}

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::rr_rotation(avl_node<T>* root)
{
	avl_node<T>* rptr = root->right;

	root->right = rptr->left;
	rptr->left = root;

	// update height of (root, rptr)
	root->height = height_of_node(root);
	rptr->height = height_of_node(rptr);

	return (rptr);
}

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::lr_rotation(avl_node<T>* root)
{
	avl_node<T>*	lptr = root->left;
	avl_node<T>*	lrptr = lptr->right;

	root->left = lrptr->right;
	lptr->right = lrptr->left;
	lrptr->right = root;
	lrptr->left = lptr;

	// update height of (root, lptr, lrptr)
	root->height = height_of_node(root);
	lptr->height = height_of_node(lptr);
	lrptr->height = height_of_node(lrptr);

	return (lrptr);
}

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::rl_rotation(avl_node<T>* root)
{
	avl_node<T>*	rptr = root->right;
	avl_node<T>*	rlptr = rptr->left;

	root->right = rlptr->left;
	rptr->left = rlptr->right;
	rlptr->left = root;
	rlptr->right = rptr;

	// update height of (root, rptr, rlptr)
	root->height = height_of_node(root);
	rptr->height = height_of_node(rptr);
	rlptr->height = height_of_node(rlptr);

	return (rlptr);
}

/*
 * height && balance factor
 */

template<class T, class Compare, class AvlNodeAlloc>
int	avl_tree<T, Compare, AvlNodeAlloc>::get_height(avl_node<T>* node) const
{
	if (node == NULL)
    	return (-1);
	return (node->height);
}

template<class T, class Compare, class AvlNodeAlloc>
int	avl_tree<T, Compare, AvlNodeAlloc>::height_of_node(avl_node<T>* node) const
{
	int const	left_height = get_height(node->left);
	int const	right_height = get_height(node->right);

	return (std::max(left_height, right_height) + 1);
}

template<class T, class Compare, class AvlNodeAlloc>
int avl_tree<T, Compare, AvlNodeAlloc>::get_balance_factor(avl_node<T>* node) const
{
	int const	left_height = get_height(node->left);
	int const	right_height = get_height(node->right);

	return (left_height - right_height);
}

template<class T, class Compare, class AvlNodeAlloc>
bool	avl_tree<T, Compare, AvlNodeAlloc>::is_equal(T const & a, T const & b) const
{
	return (!this->comp(a.first, b.first) && !this->comp(b.first, a.first));
}

/*
 * inorder_successor && inorder_predecessor
 */

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::inorder_successor(avl_node<T> const * root, avl_node<T> const * node) const
{
	avl_node<T>*	ancestor = (avl_node<T>*)root;
	avl_node<T>*	successor = NULL;

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
	return ((successor == NULL) ? (avl_node<T>*)(&past_the_last) : successor);
}

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::inorder_predecessor(avl_node<T> const * root, avl_node<T> const * node) const
{
	avl_node<T>*	ancestor = (avl_node<T>*)root;
	avl_node<T>*	predecessor = NULL;

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
 * leftmost && rightmost node of avl-tree
 */

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::rightmost_node(avl_node<T>* root) const
{
   if (root == NULL)
       return (NULL);
   while (root->right != NULL)
       root = root->right;
   return (root);
}

template<class T, class Compare, class AvlNodeAlloc>
avl_node<T>*	avl_tree<T, Compare, AvlNodeAlloc>::leftmost_node(avl_node<T>* root) const
{
    if (root == NULL)
        return (NULL);
    while (root->left != NULL)
        root = root->left;
    return (root);
}

}

#endif
