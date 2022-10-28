
#ifndef AVL_NODE_TPP
# define AVL_NODE_TPP

namespace ft
{
  
/*
 * Constructors && Destructor
 */

template<class T>
avl_node<T>::avl_node(void) : data(), left(), right(), height()
{
}

template<class T>
avl_node<T>::avl_node(T const & val) : data(val), left(), right(), height()
{
}

template<class T>
avl_node<T>::avl_node(avl_node const & src)
	: data(src.data), left(src.left), right(src.right), height(src.height)
{
}

template<class T>
avl_node<T>::~avl_node(void)
{
}

/*
 * Copy assignment operator
 */

template<class T>
avl_node<T>&	avl_node<T>::operator=(avl_node const & rhs)
{
	this->data = rhs.data;
	this->left = rhs.left;
	this->right = rhs.right;
	this->height = rhs.height;

	return (*this);
}

}

#endif
