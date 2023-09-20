#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

void RPN::calculate(std::string input){
	std::stringstream stream(input);
	std::string token;
	while (getline(stream, token, ' ')){
		if (this->isNumber(token)){
			this->pila.push(token);
		}
		else if (this->isOperator(token) == true){
			int a = std::stoi(this->pila.top());
			this->pila.pop();
			int b = std::stoi(this->pila.top());
			this->pila.pop();
			if (token == "+")
				this->pila.push(std::to_string(b + a));
			else if (token == "-")
				this->pila.push(std::to_string(b - a));
			else if (token == "*")
				this->pila.push(std::to_string(b * a));
			else if (token == "/")
				this->pila.push(std::to_string(b / a));
			else if (token == "%")
				this->pila.push(std::to_string(b % a));
		}
	}
	if (this->pila.size() != 1){
		std::cout << "Error: too many values in stack" << std::endl;
		return;
	}
	std::cout << this->pila.top() << std::endl;
}

bool RPN::isOperator(std::string token){
	const char* tokenchain = token.c_str();
	if (tokenchain[0] == '+' || tokenchain[0] == '-' || tokenchain[0] == '*' || tokenchain[0] == '/' || tokenchain[0] == '%')
		return true;
	return false;
}

bool RPN::isNumber(std::string token){
	const char* cadenaChar = token.c_str();
	int c = 0;
	while (cadenaChar[c]){
		if (!isdigit(cadenaChar[c])){
			return false;
		}
		c++;
	}
	return true;
}