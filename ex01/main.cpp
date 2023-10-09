#include "RPN.hpp"

int main(int argc, char **av) {
	if (argc != 2) {
		std::cout << "Usage: ./rpn \"1 2 + 3 * 4 5 - /\"" << std::endl;
		return 1;
	}
	RPN rpn;
	std::string input(av[1]);
	std::stringstream stream(input);
	std::string token;
	int c = 0;
	while (getline(stream, token, ' ')){
		if (rpn.isNumber(token) == false && rpn.isOperator(token) == false){
			std::cout << "Error: bad input" << std::endl;
			return 1;
		}
		if (rpn.isNumber(token) == true)
			c++;
	}
	rpn.calculate(input);
	return 0;
}
