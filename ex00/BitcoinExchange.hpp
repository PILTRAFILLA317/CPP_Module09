#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <time.h>

struct Fecha {
	int año;
	int mes;
	int dia;
};

class BitcoinExchange{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		
		void read_file(std::string filename);
		bool dateChecker(std::string date);
		bool FechaEsMenor(const Fecha& fecha1, const Fecha& fecha2);
		Fecha ConvertirFecha(const std::string& fechaStr);

	private:
		std::map<std::string, float> mapa;

};

#endif