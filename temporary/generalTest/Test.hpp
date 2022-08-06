
#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>

# include "Test1.hpp"

template<class T>
class Test
{
private:
	T		_nb;
public:
	Test(void);
	~Test(void);

	template<class U>
	friend void	Test1<U>::foo(void);// Test1<U>::foo() is friend of Test<T>.
};
template<class T>
Test<T>::Test(void)
{
	std::cout << "Default constructor [Test]" << std::endl;
}

template<class T>
Test<T>::~Test(void)
{
	std::cout << "Destructor [Test]" << std::endl;
}

#endif
