
#ifndef RAIIPTR_HPP
# define RAIIPTR_HPP

# include <new>

template<class T>
class RAIIptr
{
private:
	T*	_ptr;

public:
	RAIIptr(T*	ptr) : _ptr(ptr)
	{
	}
	~RAIIptr(void)
	{
		delete (this->_ptr);
	}

	T*	getPtr(void) const
	{
		return (this->_ptr);
	}
};

#endif

