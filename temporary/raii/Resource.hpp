
#ifndef RESOURCE_HPP
# define RESOURCE_HPP

# include <iostream>
# include <exception>

struct Resource
{
	Resource(void)
	{
		std::cout << "The resource is acquired" << std::endl;
	}
	~Resource(void)
	{
		std::cout << "The resource is released" << std::endl;
	}

	void	safeFunction(void)
	{
		std::cout << "Doing a safe thing with resource" << std::endl;
	}
	void	unsafeFunction(void)
	{
		throw std::exception();
	}
};

#endif

