#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base()
{
}

Base* generate(void)
{
	unsigned int n;
	Base* newBase;

	n = std::rand() % 3;
	switch(n)
	{
		case 0:
		{
			newBase = new A();
			return (newBase);
		}
		case 1:
		{
			newBase = new B();
			return (newBase);
		}
		case 2:
		{
			newBase = new C();
			return (newBase);
		}
		default :
			return (NULL);
	}
}

void identify(Base* p)
{
	A* a;
	B* b;
	C* c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if(a)
		std::cout << "A" << std::endl;
	else if(b)
		std::cout << "B" << std::endl;
	else if(c)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(...)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(...)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(...)
	{
	}
	
}