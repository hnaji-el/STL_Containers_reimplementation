
#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
  
template<class T>
class node
{
public:
	T		data;
	node*	left;
	node*	right;
	int		height;

public:
	// Constructors && Destructor
	node(void);
	node(T const & val);
	node(node const & src);
	~node(void);

	// Copy assignment operator
	node&	operator=(node const & rhs);
};

}

# include "node.tpp"

#endif
