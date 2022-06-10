
#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

/*
 * [	] (copy constructor)
 * [ =  ] (assignment operator)
 * [ ++ ] (pre_increment && post_increment)
 * [ == ]
 * [ != ]
 * [ *	]
 * [ -> ]
 */

namespace ft
{

template<class Container>
class iterator : public std::iterator<std::random_access_iterator_tag, typename Container::value_type>
{
private:

public:
	iterator(void);
	~iterator(void);

};

}

#endif
