#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(RPN const &src){
	*this = src;
}

RPN &RPN::operator=(RPN const &rhs){
	if (this != &rhs){
		this->pila = rhs.pila;
	}
	return *this;
}

void RPN::calculate(std::string input){
	std::stringstream stream(input);
	std::string token;
	while (getline(stream, token, ' ')){
		if (this->isNumber(token)){
			this->pila.push(token);
		}
		else if (this->isOperator(token) == true){
			if (this->pila.size() < 2){
				std::cout << "Error: too few values in stack" << std::endl;
				return;
			}
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
		else{
			std::cout << "Error: bad input" << std::endl;
			return;
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
	if ((tokenchain[0] == '+' || tokenchain[0] == '-' || tokenchain[0] == '*' || tokenchain[0] == '/' || tokenchain[0] == '%')
		&& !tokenchain[1])
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
	if (token.length() == 0)
		return false;
	int i = std::stoi(token);
	if (i >= 10)
		return false;
	return true;
}