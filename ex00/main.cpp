#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return 1;
	}
	try{
		BitcoinExchange bitcoin;
		bitcoin.read_file(av[1]);
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	};
	return 0;
}