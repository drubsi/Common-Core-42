#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	Base*	base;
	Base*	base2;
	Base*	base3;
	A		a;
	B		b;
	C		c;
	
	base =	generate();
	identify(*base);
	identify(base);
	base2 =	generate();
	identify(*base2);
	identify(base2);
	base3 =	generate();
	identify(*base3);
	identify(base3);
	std::cout << "\t\t---CONTROLLED TESTS WITHOUT RANDOMNESS---" << std::endl;
	identify(a);
	identify(&a);
	identify(b);
	identify(&b);
	identify(c);
	identify(&c);
	delete base3;
	delete base2;
	delete base;
}
