#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::ifstream file("data.csv");
	if (file.is_open()){
		std::string line;
		getline(file, line);
		if (line != "date,exchange_rate"){
			std::cout << "Error: invalid CSV" << "\n";
			file.close();
			exit(1);
		}
		while (getline(file, line)){
			std::stringstream ss(line);
			std::string key;
			std::string value;
			getline(ss, key, ',');
			getline(ss, value, ',');
			mapa[key] = std::stof(value);
		}
		file.close();
	}
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs){
	if (this != &rhs){
		this->mapa = rhs.mapa;
	}
	return *this;
}

bool BitcoinExchange::dateChecker(std::string date){
	Fecha aux = ConvertirFecha(date);
	if (std::isdigit(aux.año) || std::isdigit(aux.mes) || std::isdigit(aux.dia))
		return true;
	if (aux.mes < 1 || aux.mes > 12)
		return true;
	if (aux.dia < 1 || aux.dia > 31)
		return true;
	return false;
}

void BitcoinExchange::read_file(std::string filename){
	std::ifstream file(filename);
	if (file.is_open()){
		std::string final_key;
		float final_value;
		std::string line;
		getline(file, line);
		while (getline(file, line)){
			std::stringstream ss(line);
			std::string key;
			std::string value;
			getline(ss, key, '|');
			getline(ss, value, '|');
			if (!key.empty()) {
				key.pop_back();}
			float val;
			if (!value.empty())
				val = std::stof(value.erase(0, 1));
			else{
				std::cout << "Error: bad input => " << key << "\n";
				continue;
			}
			if (val < 0){
				std::cout << "Error: not a positive number." << "\n";
				continue;
			}
			if (val > 1000){
				std::cout << "Error: too large a number." << "\n";
				continue;
			}
			if (dateChecker(key)){
				std::cout << "Error: bad input => " << key << "\n";
				continue;
			}
			Fecha fechaBuscada = ConvertirFecha(key);
			Fecha fechaMasCercana = ConvertirFecha(mapa.begin()->first);
			for (std::map<std::string, float>::iterator it = mapa.begin(); it != mapa.end(); ++it) {
				Fecha fecha = ConvertirFecha(it->first);
				if ((fechaBuscada.año == fecha.año) && (fechaBuscada.mes == fecha.mes)
					&& (fechaBuscada.dia == fecha.dia)) {
					final_key = it->first;
					final_value = it->second;
					break;
				}
				else if (FechaEsMenor(fecha, fechaBuscada) && !FechaEsMenor(fecha, fechaMasCercana)) {
					fechaMasCercana = fecha;
					final_key = it->first;
					final_value = it->second;
				}
			}
			std::map<std::string, float>::iterator aux = mapa.begin();
			Fecha f_aux = ConvertirFecha(aux->first);
			if (FechaEsMenor(fechaBuscada, f_aux)) {
				final_value = aux->second;
			}
			std::cout << key << " => " << val << " = " << final_value * val << "\n";
		}
		file.close();
	}
}

Fecha BitcoinExchange::ConvertirFecha(const std::string& fechaStr) {
	Fecha fecha;
	sscanf(fechaStr.c_str(), "%d-%d-%d", &fecha.año, &fecha.mes, &fecha.dia);
	return fecha;
}

bool BitcoinExchange::FechaEsMenor(const Fecha& fecha1, const Fecha& fecha2) {
	int fecha1Total = fecha1.año * 10000 + fecha1.mes * 100 + fecha1.dia;
	int fecha2Total = fecha2.año * 10000 + fecha2.mes * 100 + fecha2.dia;
	return fecha1Total < fecha2Total;
}