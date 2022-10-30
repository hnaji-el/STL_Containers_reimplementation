
#ifndef NODE_TPP
# define NODE_TPP

namespace ft
{
  
/*
 * Constructors && Destructor
 */

template<class T>
node<T>::node(void)
	: data(), left(), right(), height()
{
}

template<class T>
node<T>::node(T const & val)
	: data(val), left(), right(), height()
{
}

template<class T>
node<T>::node(node const & src)
	: data(src.data), left(src.left), right(src.right), height(src.height)
{
}

template<class T>
node<T>::~node(void)
{
}

/*
 * Copy assignment operator
 */

template<class T>
node<T>&	node<T>::operator=(node const & rhs)
{
	if (this != &rhs)
	{
		this->left = rhs.left;
		this->right = rhs.right;
		this->height = rhs.height;
	}
	return (*this);
}

}

#endif
