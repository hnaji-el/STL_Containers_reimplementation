
#include "vector.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <limits>

int	main(void)
{
//	std::vector<int>	vec;
//	std::allocator<int>	alloc;
//
//	std::cout << vec.max_size() << std::endl;
//	std::cout << alloc.max_size() << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<char>::max() << std::endl;
	std::cout << std::numeric_limits<long>::max() << std::endl;
	std::cout << std::numeric_limits<unsigned int>::max() << std::endl;

	return (0);
}

/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */

