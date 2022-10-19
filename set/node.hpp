
#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{

#define BLACK 0
#define RED 1
  
template<class T>
class node
{
public:
	T		key;
	node*	left;
	node*	right;
	bool	color;

public:
	node(T const & key);
};

}

# include "node.tpp"

#endif
