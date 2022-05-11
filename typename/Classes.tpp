
#include "Classes.hpp"

template<class T>
typename Temp<T>::value_type		Temp<T>::test(Temp<T>::pointer x)
{
	Temp<T>::value_type	y = *x;
	return (y);
}

