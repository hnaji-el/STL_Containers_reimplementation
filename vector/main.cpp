
#include "vector.hpp"
#include <vector>
#include <iomanip>
#include <cmath>

struct Foo { char	arr[1]; };

int	main(void)
{
	std::vector<Foo>			vec;
	std::allocator<Foo>			a;

	std::vector<char>			vec1;
	std::allocator<char>		a1;

	std::vector<short int>		vec2;
	std::allocator<short int>	a2;

	std::vector<int>			vec3;
	std::allocator<int>			a3;

	std::vector<long>			vec4;
	std::allocator<long>		a4;

	std::cout << "--------------------" << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << vec1.max_size() << std::endl;
	std::cout << a1.max_size() << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << vec2.max_size() << std::endl;
	std::cout << a2.max_size() << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << vec3.max_size() << std::endl;
	std::cout << a3.max_size() << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << vec4.max_size() << std::endl;
	std::cout << a4.max_size() << std::endl;
	std::cout << "--------------------" << std::endl;

	//	{
	//		ft::vector<Foo>				vec;
	//		ft::vector<char>			vec1;
	//		ft::vector<short int>		vec2;
	//		ft::vector<int>				vec3;
	//		ft::vector<long>			vec4;
	//
	//		std::cout << vec.max_size() << std::endl;
	//		std::cout << "--------------------" << std::endl;
	//		std::cout << vec1.max_size() << std::endl;
	//		std::cout << vec2.max_size() << std::endl;
	//		std::cout << vec3.max_size() << std::endl;
	//		std::cout << vec4.max_size() << std::endl;
	//	}
	//	std::cout << "---------------------------------------------" << std::endl;

	//	std::cout << "---------------------------------------" << std::endl;
	//
	//	std::cout << std::numeric_limits<ptrdiff_t>::max() << std::endl;
	//	std::cout << std::numeric_limits<ptrdiff_t>::max() / 2 << std::endl;
	//	std::cout << std::numeric_limits<ptrdiff_t>::max() / 4 << std::endl;
	//	std::cout << std::numeric_limits<ptrdiff_t>::max() / 8 << std::endl;
	//
	//	std::cout << "---------------------------------------" << std::endl;
	//
	//	std::cout << std::numeric_limits<size_t>::max() << std::endl;
	//	std::cout << std::numeric_limits<size_t>::max() / 2 << std::endl;
	//	std::cout << std::numeric_limits<size_t>::max() / 4 << std::endl;
	//	std::cout << std::numeric_limits<size_t>::max() / 8 << std::endl;
	//
	//	std::cout << "---------------------------------------" << std::endl;
	//
	//	std::cout << sizeof(char) << std::endl;
	//	std::cout << sizeof(short int) << std::endl;
	//	std::cout << sizeof(int) << std::endl;
	//	std::cout << sizeof(long) << std::endl;

	return (0);
}

/*
 * SYNTAX: 
 * _obj(Bar())   === _obj()
 * _obj(Bar(10)) === _obj(10)
 */

