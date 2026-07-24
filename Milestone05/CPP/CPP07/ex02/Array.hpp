#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <cstddef>


template <typename T>

class Array
{
	private:

		std::size_t			_size;
		T					*array;
	
	public:
		
		class OutOfLimits : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Unable to access the element, out of bounds");
				}
		};
		Array(): _size(0), array(new T[_size]()){}
		Array(unsigned int n): _size(n), array(new T[_size]()){}
		Array(const Array& copy) : _size(copy._size), array(new T[_size])
		{
			for(std::size_t i = 0; i < _size; i++)
				array[i] = copy.array[i];
		}
		~Array()
		{
			delete [] array;
		}
		Array& operator=(const Array& other)
		{
			T	*newArray;
			if (this != &other)
			{
				newArray = new T[other._size];
				for(std::size_t i = 0; i < other._size; i++)
					newArray[i] = other.array[i];
				delete [] this->array;
				this->array = newArray;
				this->_size = other._size;
			}
			return (*this);
		}
		T& operator[](std::size_t index)
		{
			if (index >= _size)
				throw OutOfLimits();
			return(array[index]);
		}
		const T& operator[](std::size_t index) const
		{
			if (index >= _size)
				throw OutOfLimits();
			return(array[index]);
		}
		std::size_t size() const
		{
			return (_size);
		}
};

#endif