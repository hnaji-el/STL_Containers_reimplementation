
#ifndef NODE_TPP
# define NODE_TPP

namespace ft
{
  
/*
 * Constructors && Destructor
 */

template<class T>
node<T>::node(void)
	: key(), left(), right(), color(RED)
{
}

template<class T>
node<T>::node(T const & key)
	: key(key), left(), right(), color(RED)
{
}

template<class T>
node<T>::node(T const & key, node* lptr, node* rptr)
	: key(key), left(lptr), right(rptr), color(RED)
{
}

template<class T>
node<T>::node(node const & src)
	: key(src.key), left(src.left), right(src.right), color(src.color)
{
}


template<class T>
node<T>&	node<T>::operator=(node const & rhs)
{
	if (this != &rhs)
	{
		this->key = rhs.key;
		this->left = rhs.left;
		this->right = rhs.right;
		this->color = rhs.color;
	}

	return (*this);
}

template<class T>
node<T>::~node(void)
{
}

}

#endif
