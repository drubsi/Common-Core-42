#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <stdexcept>
#include <iterator>

class Span
{
	private:

		unsigned int		N;
		std::vector<int>	container;
	
	public:

		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int value);
		long shortestSpan();
		long longestSpan();

		template <typename T>
		void addNumbers(const T& begin, const T& end)
		{
			T it = begin;
			long size = std::distance(it, end);
			if((size + container.size()) > N)
					throw std::out_of_range("The range exceeds the Span capacity");
			for(; it != end; it++)
				container.push_back(*it);
		}
};
#endif
