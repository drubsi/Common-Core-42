#include "Span.hpp"
#include <algorithm>

Span::Span():N(0), container(0)
{
}

Span::Span(unsigned int N):N(N), container(0)
{
}

Span::Span(const Span& copy):N(copy.N), container(copy.container)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->container = other.container;
	}
	return(*this);
}

Span::~Span()
{
}

void Span::addNumber(int value)
{
	if (container.size() >= N)
		throw std::out_of_range("Span capacity exceeded");
	container.push_back(value);
}

long Span::shortestSpan()
{
	if(container.size() < 2)
		throw std::logic_error("At least two numbers are required to calculate a span");
	std::stable_sort(container.begin(), container.end());
	long	diff = (static_cast<long>(container[1]) - static_cast<long>(container[0]));
	for(std::size_t i = 2; i < container.size(); i++)
	{
		long	n = (static_cast<long>(container[i]) - static_cast<long>(container[i - 1]));
		if (n < diff)
			diff = n;
	}
	return (diff);
}
long Span::longestSpan()
{
	long	result = 0;
	if(container.size() < 2)
		throw std::logic_error("At least two numbers are required to calculate a span");
	std::vector<int>::iterator n = std::max_element(container.begin(), container.end());
	std::vector<int>::iterator j = std::min_element(container.begin(), container.end());
	result = (static_cast<long>(*n) - static_cast<long>(*j));
	return (result);
}
