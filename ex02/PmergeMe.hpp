#ifndef PRMERGEME_HPP
#define PRMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include <chrono>

class PmergeMe {
	private:
		std::vector <std::vector <int> > _v;
		std::deque <std::deque <int> > _d;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);

		void checkArgs(int ac, char **av);

		void insertionSort(std::vector<int>& arr);
		void vector_filler(std::list <int> &result);
		std::vector <int> vec_merger(std::vector <int> &l1, std::vector <int> &l2);
		std::vector <int> merge();
		void insert();
		void vec_printer(std::vector <int> &v);

		void deq_insertionSort(std::deque<int>& arr);
		void deque_filler(std::list <int> &result);
		std::deque <int> deq_merger(std::deque <int> &l1, std::deque <int> &l2);
		std::deque <int> deq_merge();
		void deq_insert();
		void deq_printer(std::deque<int> &v);
};


#endif