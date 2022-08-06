 
#include "Test1.hpp"

Test1::Test1(void)
{
	std::cout << "Default constructor [Test1]" << std::endl;
}

Test1::~Test1(void)
{
	std::cout << "Destructor [Test1]" << std::endl;
}

//	void	Test1::test1(Test& tes)
//	{
//		Test::integer	a;
//	
//		a = tes._a;
//		std::cout << a << std::endl;
//		tes.test();
//	}
