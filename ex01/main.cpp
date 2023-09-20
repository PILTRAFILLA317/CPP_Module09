#include "RPN.hpp"

int main(int argc, char **av) {
	if (argc != 2) {
		std::cout << "Usage: ./rpn \"1 2 + 3 * 4 5 - /\"" << std::endl;
		return 1;
	}
	RPN rpn;
	std::string input(av[1]);
	rpn.calculate(input);
	return 0;
}