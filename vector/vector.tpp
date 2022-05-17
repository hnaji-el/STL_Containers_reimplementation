
#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{

template<class T, class Alloc>
explicit vector<T, Alloc>::vector(const allocator_type& alloc = allocator_type())
	: _array(NULL), _alloc(alloc), _size(0), _capacity(0)
{
}

}

#endif

