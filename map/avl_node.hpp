
#ifndef AVL_NODE_HPP
# define AVL_NODE_HPP

namespace ft
{
  
template<class T>
class avl_node
{
public:
	T			data;
	avl_node*	left;
	avl_node*	right;
	int			height;

public:
	// Constructors && Destructor
	avl_node(void);
	avl_node(T const & val);
	avl_node(avl_node const & src);
	~avl_node(void);

	// Copy assignment operator
	avl_node&	operator=(avl_node const & rhs);
};

}

# include "avl_node.tpp"

#endif
