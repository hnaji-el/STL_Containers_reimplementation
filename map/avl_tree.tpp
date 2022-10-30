
#ifndef AVL_TREE_TPP
# define AVL_TREE_TPP

namespace ft
{

/*
 * constructors && destructor
 */

template<class T, class Comp, class Alloc>
avl_tree<T, Comp, Alloc>::avl_tree(Comp const & comp, Alloc const & alloc)
	: _root(), _size(), _comp(comp), _alloc(alloc), _node_alloc(), past_the_last(), inserted_state()
{
}

template<class T, class Comp, class Alloc>
avl_tree<T, Comp, Alloc>::~avl_tree(void)
{
	this->clear_avl();
}

template<class T, class Comp, class Alloc>
avl_tree<T, Comp, Alloc>&	avl_tree<T, Comp, Alloc>::operator=(avl_tree const & rhs)
{
	if (this != &rhs)
	{
		this->clear_avl();
		this->_comp = rhs._comp;
	}
	return (*this);
}

/*
 * search && clear_avl && insert && remove && swap
 */

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::search(typename T::first_type const & key) const
{
	return (this->search(this->_root, key));
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::search(node<T>* root, typename T::first_type const & key) const
{
	if (root == NULL)
		return (root);

	else if (this->_comp(key, root->data.first) == true) // move to left
		return (this->search(root->left, key));
	else if (this->_comp(root->data.first, key) == true) // move to right
		return (this->search(root->right, key));
	return (root);
}

template<class T, class Comp, class Alloc>
void	avl_tree<T, Comp, Alloc>::clear_avl(void)
{
	this->clear_avl(this->_root);
	this->_root = NULL;
	this->_size = 0;
}

template<class T, class Comp, class Alloc>
void	avl_tree<T, Comp, Alloc>::clear_avl(node<T>* root)
{
	if (root == NULL)
		return ;

	clear_avl(root->left);
	clear_avl(root->right);
	this->_node_alloc.destroy(root); this->_node_alloc.deallocate(root, 1);
}

template<class T, class Comp, class Alloc>
void	avl_tree<T, Comp, Alloc>::insert(T const & data)
{
	this->_root = this->insert(this->_root, data);
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::insert(node<T>* root, T const & data)
{
    if (root == NULL)
	{
		root = this->_node_alloc.allocate(1); this->_node_alloc.construct(root, data);
		this->inserted_state = root;
		this->_size++;
		return (root);
	}
    else if (this->_comp(data.first, root->data.first) == true) // move to left
		root->left = this->insert(root->left, data);
    else if (this->_comp(root->data.first, data.first) == true) // move to right
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

template<class T, class Comp, class Alloc>
void	avl_tree<T, Comp, Alloc>::remove(typename T::first_type const & key)
{
	this->_root = this->remove(this->_root, key);
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::remove(node<T>* root, typename T::first_type const & key)
{
	if (root == NULL)
		return (NULL);
	else if (this->_comp(key, root->data.first) == true) // move to left
		root->left = remove(root->left, key);
	else if (this->_comp(root->data.first, key) == true) // move to right
		root->right = remove(root->right, key);
	// case#1: leaf node
	else if (root->left == NULL && root->right == NULL)
	{
		this->_node_alloc.destroy(root); this->_node_alloc.deallocate(root, 1);
		this->_size--;
		return (NULL);
	}
	// case#2: node with 1 Children
	else if (root->left == NULL)
	{
		node<T>*	rptr = root->right;
		this->_node_alloc.destroy(root); this->_node_alloc.deallocate(root, 1);
		this->_size--;
		root = rptr;
	}
	else if (root->right == NULL)
	{
		node<T>*	lptr = root->left;
		this->_node_alloc.destroy(root); this->_node_alloc.deallocate(root, 1);
		this->_size--;
		root = lptr;
	}
	// case#2: node with 2 Children
	else if (root->left != NULL && root->right != NULL)
	{
		this->_alloc.destroy(&root->data);
		this->_alloc.construct(&root->data, this->inorder_successor(root)->data);
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
	std::swap(this->_root, x._root);
	std::swap(this->_size, x._size);
	std::swap(this->_comp, x._comp);
	std::swap(this->_alloc, x._alloc);
}

/*
 * Rotations for insertion and deletion
 */

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::ll_rotation(node<T>* root)
{
	node<T>* lptr = root->left;

	root->left = lptr->right;
	lptr->right = root;

	// update height of (root, lptr)
	root->height = height_of_node(root);
	lptr->height = height_of_node(lptr);

	return (lptr);
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::rr_rotation(node<T>* root)
{
	node<T>* rptr = root->right;

	root->right = rptr->left;
	rptr->left = root;

	// update height of (root, rptr)
	root->height = height_of_node(root);
	rptr->height = height_of_node(rptr);

	return (rptr);
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::lr_rotation(node<T>* root)
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

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::rl_rotation(node<T>* root)
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

template<class T, class Comp, class Alloc>
int	avl_tree<T, Comp, Alloc>::get_height(node<T>* node) const
{
	if (node == NULL)
    	return (-1);
	return (node->height);
}

template<class T, class Comp, class Alloc>
int	avl_tree<T, Comp, Alloc>::height_of_node(node<T>* node) const
{
	int const	left_height = get_height(node->left);
	int const	right_height = get_height(node->right);

	return (std::max(left_height, right_height) + 1);
}

template<class T, class Comp, class Alloc>
int avl_tree<T, Comp, Alloc>::get_balance_factor(node<T>* node) const
{
	int const	left_height = get_height(node->left);
	int const	right_height = get_height(node->right);

	return (left_height - right_height);
}

template<class T, class Comp, class Alloc>
bool	avl_tree<T, Comp, Alloc>::is_equal(T const & a, T const & b) const
{
	return (!this->_comp(a.first, b.first) && !this->_comp(b.first, a.first));
}

/*
 * size && max_size && is_empty
 */

template<class T, class Comp, class Alloc>
size_t	avl_tree<T, Comp, Alloc>::size(void) const
{
	return (this->_size);
}

template<class T, class Comp, class Alloc>
size_t	avl_tree<T, Comp, Alloc>::max_size(void) const
{
    return (this->_alloc.max_size());
}

template<class T, class Comp, class Alloc>
bool	avl_tree<T, Comp, Alloc>::is_empty(void) const
{
	return (this->_size == 0);
}

/*
 * inorder_successor && inorder_predecessor
 */

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::inorder_successor(node<T> const * node) const
{
	ft::node<T>*	ancestor = this->_root;
	ft::node<T>*	successor = NULL;

	if (this->_root == NULL || node == NULL || node == &this->past_the_last)
		return (NULL);

	// case1: node has right-subtree
	if (node->right != NULL)
		return (this->leftmost_node(node->right));
	// case2: no right-subtree
	while (ancestor != node)
	{
		if (this->_comp(node->data.first, ancestor->data.first) == true)
		{
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else
			ancestor = ancestor->right;
	}
	return ((successor == NULL) ? (ft::node<T>*)(&this->past_the_last) : successor);
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::inorder_predecessor(node<T> const * node) const
{
	ft::node<T>*	ancestor = this->_root;
	ft::node<T>*	predecessor = NULL;

	if (this->_root == NULL || node == NULL)
		return (NULL);
    if (node == &this->past_the_last)
        return (this->rightmost_node(ancestor));

	// case1: node has left-subtree
	if (node->left != NULL)
		return (this->rightmost_node(node->left));
	// case2: no left-subtree
	while (ancestor != node)
	{
		if (this->_comp(ancestor->data.first, node->data.first) == true)
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

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::lower_bound(typename T::first_type const & key) const
{
	node<T>*	temp = this->_root;
	node<T>*	lower_bound = NULL;

	while (temp != NULL)
	{
		if (!this->_comp(temp->data.first, key) && !this->_comp(key, temp->data.first))
		{
			lower_bound = temp;
			break ;
		}
		if (this->_comp(key, temp->data.first) == true) // move to left
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
	node<T>*	temp = this->_root;
	node<T>*	upper_bound = NULL;

	while (temp != NULL)
	{
		if (this->_comp(key, temp->data.first) == true) // move to left
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

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::rightmost_node(void) const
{
	return (this->rightmost_node(this->_root));
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::leftmost_node(void) const
{
	return (this->leftmost_node(this->_root));
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::rightmost_node(node<T>* root) const
{
   if (root == NULL)
       return (NULL);

   while (root->right != NULL)
       root = root->right;
   return (root);
}

template<class T, class Comp, class Alloc>
node<T>*	avl_tree<T, Comp, Alloc>::leftmost_node(node<T>* root) const
{
    if (root == NULL)
        return (NULL);

    while (root->left != NULL)
        root = root->left;
    return (root);
} 

/*
 * getters [ get_key_compare && get_allocator ]
 */

template<class T, class Comp, class Alloc>
Comp	avl_tree<T, Comp, Alloc>::get_key_compare(void) const
{
	return (this->_comp);
}

template<class T, class Comp, class Alloc>
Alloc	avl_tree<T, Comp, Alloc>::get_allocator(void) const
{
	return (this->_alloc);
}


}

#endif
