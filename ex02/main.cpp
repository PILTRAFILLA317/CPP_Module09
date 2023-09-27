#include "PmergeMe.hpp"

void PmergeMe::checkArgs(int ac, char **av) {
	std::list <int> result;
	if (ac < 2) {
		std::cout << "Error: No arguments" << std::endl;
		throw std::exception();
	}
	for (int i = 1; i < ac; ++i) {
		for (size_t j = 0; j < strlen(av[i]); ++j) {
			if (!std::isdigit(av[i][j])) {
				std::cout << "Error: Invalid argument" << std::endl;
				throw std::exception();
			}
		}
	}
	for (int i = 1; i < ac; ++i) {
		result.push_back(atoi(av[i]));
	}
	for (std::list<int>::iterator it = result.begin(); it != result.end(); ++it) {
		if (*it < 0) {
			std::cout << "Error: Negative numbers" << std::endl;
			throw std::exception();
		}
	}
}

int main(int ac, char **av){
	PmergeMe p;
	try{
		p.checkArgs(ac, av);
	}
	catch (std::exception &e) {
		return 1;
	}
	std::list <int> result;
	for (int i = 1; i < ac; ++i) {
		result.push_back(atoi(av[i]));
	}
	std::cout << "Before: ";
	for (std::list<int>::iterator it = result.begin(); it != result.end(); ++it) {
		std::cout << *it << " ";
	}
	int size = result.size();

	std::cout << std::endl;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	p.vector_filler(result);
	p.insert();
	std::vector<int> final = p.merge();
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "After: ";
	p.vec_printer(final);
	std::cout << "Time to process a range of " << size << " elements with std::vector : " << elapsed_seconds.count() << "s\n";

	for (int i = 1; i < ac; ++i) {
		result.push_back(atoi(av[i]));
	}
	start = std::chrono::system_clock::now();
	p.deque_filler(result);
	p.deq_insert();
	std::deque<int> final2 = p.deq_merge();
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Time to process a range of " << size << " elements with std::deque : " << elapsed_seconds.count() << "s\n";
	return 0;
}