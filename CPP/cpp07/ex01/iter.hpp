#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* arr, std::size_t length, void (*f)(T& a))
{
	for (std::size_t i = 0; i < length; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void func(T& arg)
{
	std::cout << arg << std::endl;
}

#endif