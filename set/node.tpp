
#ifndef NODE_TPP
# define NODE_TPP

namespace ft
{
  
/*
 * Constructors
 */

template<class T>
node<T>::node(T const & key) : key(key), left(), right(), color(RED)
{
}

}

#endif
