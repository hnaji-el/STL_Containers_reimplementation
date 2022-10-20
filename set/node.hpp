
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
	// Constructors && Destructor
	node(void);
	node(node const & src);
	node&	operator=(node const & rhs);
	~node(void);

	node(T const & key);
	node(T const & key, node* lptr, node* rptr);
};

}

# include "node.tpp"

#endif
