
#include "vector.hpp"
#include <iostream>
#include <vector>
#include <memory>

struct Foo { long a; };

int	main(void)
{
	std::vector<char>			vec1;
	std::vector<unsigned char>	vec2;
	std::vector<Foo>			vec3;

	std::vector<short>			vec4;
	std::vector<unsigned short>	vec5;

	std::vector<int>			vec6;
	std::vector<unsigned int>	vec7;

	std::vector<long>			vec8;
	std::vector<unsigned long>	vec9;

	std::cout << vec1.max_size() << std::endl;
	std::cout << vec2.max_size() << std::endl;
	std::cout << vec3.max_size() << std::endl << std::endl;

	std::cout << vec4.max_size() << std::endl;
	std::cout << vec5.max_size() << std::endl << std::endl;

	std::cout << vec6.max_size() << std::endl;
	std::cout << vec7.max_size() << std::endl << std::endl;

	std::cout << vec8.max_size() << std::endl;
	std::cout << vec9.max_size() << std::endl;

	return (0);
}

/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */

