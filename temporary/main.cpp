
#include <iostream>

struct Foo
{
	int*	ptr;
	Foo(void)	{ }
	~Foo(void)	{ }
};

struct Bar
{
	Bar(void)	{ }
	~Bar(void)	{ }
	int*	allocate(size_t n)
	{
		return (static_cast<int*>(operator
	}
};

void	test(void)
{
	Foo		a;
	a.ptr = new int[2];
	a.ptr = new int[2];
	a.ptr = new int[2];
	a.ptr = new int[2];
	a.ptr = new int[2];
	a.ptr = new int[2];
}

int	main(void)
{
	Foo		a;

	a.ptr = new int[2];
	a.ptr = new int[2];
	a.ptr = new int[2];
	a.ptr = new int[2];
	a.ptr = new int[2];
	a.ptr = new int[2];

	system("leaks a.out");
	return (0);
}

