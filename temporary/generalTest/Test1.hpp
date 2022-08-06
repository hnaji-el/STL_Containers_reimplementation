 
#ifndef TEST1_HPP
# define TEST1_HPP

# include <iostream>


template<class T>
class Test1
{
public:
	Test1(void);
	~Test1(void);

	void	foo(void);
};

template<class T>
class Test;

template<class T>
void	Test1<T>::foo(void)
{
	Test<T>	a;
	std::cout << a._nb << std::endl;
}

template<class T>
Test1<T>::Test1(void)	{ std::cout << "Default constructor [Test1]" << std::endl; }

template<class T>
Test1<T>::~Test1(void)	{ std::cout << "Destructor [Test1]" << std::endl; }

#endif
