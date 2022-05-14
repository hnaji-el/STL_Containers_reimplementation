
#include <iostream>

template<class T>
class Raii
{
private:
	T*	_res;
public:
	Raii(T* res) : _res(res)
	{
	}
	~Raii(void)
	{
		delete _res;
	}
	
	T*	getRes(void) const
	{
		return (this->_res);
	}
};

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
		Raii<Resource>	obj(new Resource);
		// Resource*	ptr = new Resource; // Acquire the resource
		obj.getRes()->unsafeFunction(); // OK, no problem
//		ptr->unsafeFunction();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

