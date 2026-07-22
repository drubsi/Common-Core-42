#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>

template <typename T, typename F>

void iter(T* array, const std::size_t  size, F function)
{
	for(std::size_t i = 0; i < size; i++)
	{
		function(array[i]);
	}
}
#endif