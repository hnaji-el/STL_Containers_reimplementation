
#include <iostream>

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

int	main(void)
{
	try
	{
		Resource*	ptr = new Resource; // Acquire the resource
		// ptr->safeFunction(); // OK, no problem
		ptr->unsafeFunction();
		delete ptr; // Release the resource
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	system("leaks a.out");
	return (0);
}

