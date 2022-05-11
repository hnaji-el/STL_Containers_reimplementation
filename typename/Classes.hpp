
#ifndef TEMPA_H
# define TEMPA_H

# include <iostream>

template<class T>
class Temp
{
public:
	typedef	T::value_type	value_type;
	typedef T*	pointer;

public:
	Temp(void)	{ std::cout << "Ctor <Temp>" << std::endl; }
	~Temp(void)	{ std::cout << "Dtor <Temp>" << std::endl; }

	value_type	test(pointer x);
};

class Sample
{
public:
	static int	value_type;

public:
	Sample(void)	{ std::cout << "Ctor <Sample>" << std::endl; }
	~Sample(void)	{ std::cout << "Dtor <Sample>" << std::endl; }
};

int	Sample::value_type = 10;

#endif
