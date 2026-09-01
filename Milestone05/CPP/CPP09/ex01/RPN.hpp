#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>

class RPN
{
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		~RPN();
		void checkInput(char* argv);
		void readInput(char* argv);

	private:
		std::stack<int>		cola;
		int					n1;
		int					n2;
		int					result;
		char				sign;

		bool isSign(char token);
		void makeOperation();
		void popStack();
		void pushStack(const std::string& token);
		void validateInput(const std::string& input);
};
#endif
