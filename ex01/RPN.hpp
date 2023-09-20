#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <cctype>

class RPN{
	public:
		RPN();
		~RPN();
		void calculate(std::string input);
		bool isOperator(std::string token);
		bool isNumber(std::string token);
	private:
		std::stack<std::string> pila;
};

#endif