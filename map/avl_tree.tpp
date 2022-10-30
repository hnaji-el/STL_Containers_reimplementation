
#ifndef AVL_TREE_TPP
# define AVL_TREE_TPP

namespace ft
{

/*
 * constructors && destructor
 */

template<class T, class Comp, class NodeAlloc>
avl_tree<T, Comp, NodeAlloc>::avl_tree(Comp const & comp)
	: root(), _size(), comp(comp), alloc(), past_the_last(), inserted_state()
{
}

template<class T, class Comp, class NodeAlloc>
avl_tree<T, Comp, NodeAlloc>::~avl_tree(void)
{
	this->clear_avl();
}

template<class T, class Comp, class NodeAlloc>
avl_tree<T, Comp, NodeAlloc>&	avl_tree<T, Comp, NodeAlloc>::operator=(avl_tree const & rhs)
{
	if (this != &rhs)
	{
		this->clear_avl();
		this->comp = rhs.comp;
	}
	return (*this);
}

/*
 * search && clear_avl && insert && remove && swap
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::search(typename T::first_type const & key) const
{
	return (this->search(this->root, key));
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::search(node<T>* root, typename T::first_type const & key) const
{
	if (root == NULL)
		return (root);

	else if (this->comp(key, root->data.first) == true) // move to left
		return (this->search(root->left, key));
	else if (this->comp(root->data.first, key) == true) // move to right
		return (this->search(root->right, key));
	return (root);
}

template<class T, class Comp, class NodeAlloc>
void	avl_tree<T, Comp, NodeAlloc>::clear_avl(void)
{
	this->clear_avl(this->root);
	this->root = NULL;
	this->_size = 0;
}

template<class T, class Comp, class NodeAlloc>
void	avl_tree<T, Comp, NodeAlloc>::clear_avl(node<T>* root)
{
	if (root == NULL)
		return ;

	clear_avl(root->left);
	clear_avl(root->right);
	this->alloc.destroy(root); this->alloc.deallocate(root, 1);
}

template<class T, class Comp, class NodeAlloc>
void	avl_tree<T, Comp, NodeAlloc>::insert(T const & data)
{
	this->root = this->insert(this->root, data);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::insert(node<T>* root, T const & data)
{
    if (root == NULL)
	{
		root = this->alloc.allocate(1); this->alloc.construct(root, data);
		this->inserted_state = root;
		this->_size++;
		return (root);
	}
    else if (this->comp(data.first, root->data.first) == true) // move to left
		root->left = this->insert(root->left, data);
    else if (this->comp(root->data.first, data.first) == true) // move to right
		root->right = this->insert(root->right, data);
    else if (this->is_equal(data, root->data) == true)
    {
        this->inserted_state = root;
        return (root);
    }

	// update height && balance_factor
	root->height = this->height_of_node(root);
	int	balance_factor = this->get_balance_factor(root);

	// check if balance or imbalance then balance it if imbalance.
	if (balance_factor == 2 && this->get_balance_factor(root->left) == 1)
		root = this->ll_rotation(root);
	else if (balance_factor == 2 && this->get_balance_factor(root->left) == -1)
		root = this->lr_rotation(root);
	else if (balance_factor == -2 && this->get_balance_factor(root->right) == 1)
		root = this->rl_rotation(root);
	else if (balance_factor == -2 && this->get_balance_factor(root->right) == -1)
		root = this->rr_rotation(root);

	return (root);
}

template<class T, class Comp, class NodeAlloc>
void	avl_tree<T, Comp, NodeAlloc>::remove(typename T::first_type const & key)
{
	this->root = this->remove(this->root, key);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::remove(node<T>* root, typename T::first_type const & key)
{
	if (root == NULL)
		return (NULL);
	else if (this->comp(key, root->data.first) == true) // move to left
		root->left = remove(root->left, key);
	else if (this->comp(root->data.first, key) == true) // move to right
		root->right = remove(root->right, key);
	// case#1: leaf node
	else if (root->left == NULL && root->right == NULL)
	{
		this->alloc.destroy(root); this->alloc.deallocate(root, 1);
		this->_size--;
		return (NULL);
	}
	// case#2: node with 1 Children
	else if (root->left == NULL)
	{
		node<T>*	rptr = root->right;
		this->alloc.destroy(root); this->alloc.deallocate(root, 1);
		this->_size--;
		root = rptr;
	}
	else if (root->right == NULL)
	{
		node<T>*	lptr = root->left;
		this->alloc.destroy(root); this->alloc.deallocate(root, 1);
		this->_size--;
		root = lptr;
	}
	// case#2: node with 2 Children
	else if (root->left != NULL && root->right != NULL)
	{
		node<T>*	succ_node = this->inorder_successor(root);
		node<T>*	temp = root;
	
		root = this->alloc.allocate(1); this->alloc.construct(root, *succ_node);
	
		root->left = temp->left;
		root->right = temp->right;
		root->height = temp->height;
	
		this->alloc.destroy(temp); this->alloc.deallocate(temp, 1);
		root->right = this->remove(root->right, root->data.first);
	}
	
	// update height && balance_factor
	root->height = height_of_node(root);
	int	balance_factor = get_balance_factor(root);
	
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

template<class T, class Comp, class Alloc>
void	avl_tree<T, Comp, Alloc>::swap(avl_tree& x)
{
	std::swap(this->root, x.root);
	std::swap(this->_size, x._size);
	std::swap(this->comp, x.comp);
	std::swap(this->alloc, x.alloc);
}

/*
 * Rotations for insertion and deletion
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::ll_rotation(node<T>* root)
{
	node<T>* lptr = root->left;

	root->left = lptr->right;
	lptr->right = root;

	// update height of (root, lptr)
	root->height = height_of_node(root);
	lptr->height = height_of_node(lptr);

	return (lptr);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::rr_rotation(node<T>* root)
{
	node<T>* rptr = root->right;

	root->right = rptr->left;
	rptr->left = root;

	// update height of (root, rptr)
	root->height = height_of_node(root);
	rptr->height = height_of_node(rptr);

	return (rptr);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::lr_rotation(node<T>* root)
{
	node<T>*	lptr = root->left;
	node<T>*	lrptr = lptr->right;

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

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::rl_rotation(node<T>* root)
{
	node<T>*	rptr = root->right;
	node<T>*	rlptr = rptr->left;

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

template<class T, class Comp, class NodeAlloc>
int	avl_tree<T, Comp, NodeAlloc>::get_height(node<T>* node) const
{
	if (node == NULL)
    	return (-1);
	return (node->height);
}

template<class T, class Comp, class NodeAlloc>
int	avl_tree<T, Comp, NodeAlloc>::height_of_node(node<T>* node) const
{
	int const	left_height = get_height(node->left);
	int const	right_height = get_height(node->right);

	return (std::max(left_height, right_height) + 1);
}

template<class T, class Comp, class NodeAlloc>
int avl_tree<T, Comp, NodeAlloc>::get_balance_factor(node<T>* node) const
{
	int const	left_height = get_height(node->left);
	int const	right_height = get_height(node->right);

	return (left_height - right_height);
}

template<class T, class Comp, class NodeAlloc>
bool	avl_tree<T, Comp, NodeAlloc>::is_equal(T const & a, T const & b) const
{
	return (!this->comp(a.first, b.first) && !this->comp(b.first, a.first));
}

/*
 * size && is_empty
 */

template<class T, class Comp, class NodeAlloc>
size_t	avl_tree<T, Comp, NodeAlloc>::size(void) const
{
	return (this->_size);
}

template<class T, class Comp, class NodeAlloc>
bool	avl_tree<T, Comp, NodeAlloc>::is_empty(void) const
{
	return (this->_size == 0);
}

/*
 * inorder_successor && inorder_predecessor
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::inorder_successor(node<T> const * node) const
{
	ft::node<T>*	ancestor = this->root;
	ft::node<T>*	successor = NULL;

	if (this->root == NULL || node == NULL || node == &this->past_the_last)
		return (NULL);

	// case1: node has right-subtree
	if (node->right != NULL)
		return (this->leftmost_node(node->right));
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
	return ((successor == NULL) ? (ft::node<T>*)(&this->past_the_last) : successor);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::inorder_predecessor(node<T> const * node) const
{
	ft::node<T>*	ancestor = this->root;
	ft::node<T>*	predecessor = NULL;

	if (this->root == NULL || node == NULL)
		return (NULL);
    if (node == &this->past_the_last)
        return (this->rightmost_node(ancestor));

	// case1: node has left-subtree
	if (node->left != NULL)
		return (this->rightmost_node(node->left));
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
 * lower_bound && upper_bound
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::lower_bound(typename T::first_type const & key) const
{
	node<T>*	temp = this->root;
	node<T>*	lower_bound = NULL;

	while (temp != NULL)
	{
		if (!this->comp(temp->data.first, key) && !this->comp(key, temp->data.first))
		{
			lower_bound = temp;
			break ;
		}
		if (this->comp(key, temp->data.first) == true) // move to left
		{
			lower_bound = temp;
			temp = temp->left;
		}
		else // move to right
			temp = temp->right;
	}
	return (lower_bound);
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::upper_bound(typename T::first_type const & key) const
{
	node<T>*	temp = this->root;
	node<T>*	upper_bound = NULL;

	while (temp != NULL)
	{
		if (this->comp(key, temp->data.first) == true) // move to left
		{
			upper_bound = temp;
			temp = temp->left;
		}
		else // move to right
			temp = temp->right;
	}
	return (upper_bound);
}

/*
 * leftmost_node && rightmost_node
 */

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::rightmost_node(void) const
{
	return (this->rightmost_node(this->root));
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::leftmost_node(void) const
{
	return (this->leftmost_node(this->root));
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::rightmost_node(node<T>* root) const
{
   if (root == NULL)
       return (NULL);

   while (root->right != NULL)
       root = root->right;
   return (root);
}

template<class T, class Comp, class NodeAlloc>
node<T>*	avl_tree<T, Comp, NodeAlloc>::leftmost_node(node<T>* root) const
{
    if (root == NULL)
        return (NULL);

    while (root->left != NULL)
        root = root->left;
    return (root);
}

}

#endif
