#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		this->_v = rhs._v;
		this->_d = rhs._d;
	}
	return *this;
}

std::vector <int> PmergeMe::vec_merger(std::vector <int> &l1, std::vector <int> &l2) {
	std::vector <int> result;
	std::merge(l1.begin(), l1.end(), l2.begin(), l2.end(), std::back_inserter(result));
	return result;
}

std::vector <int> PmergeMe::merge() {
	std::vector <int> result;
	for (size_t i = 0; i < this->_v.size(); ++i) {
		result = vec_merger(result, this->_v[i]);
	}
	return result;
}

void PmergeMe::insertionSort(std::vector<int>& arr) {
	int n = arr.size();
	int i = 0;

	while (i < n) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			std::swap(arr[j - 1], arr[j]);
			--j;
		}
		++i;
	}
}

void PmergeMe::insert() {
	for (size_t i = 0; i < this->_v.size(); ++i) {
		insertionSort(this->_v[i]);
	}
}

void PmergeMe::vector_filler(std::list <int> &result){
	while (!result.empty()) {
		std::vector<int> subVector;
		for (int i = 0; i < 10 && !result.empty(); ++i) {
			subVector.push_back(result.front());
			result.pop_front();
		}
		this->_v.push_back(subVector);
	}
}

void PmergeMe::vec_printer(std::vector<int> &v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::deq_printer(std::deque<int> &v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

std::deque <int> PmergeMe::deq_merger(std::deque <int> &l1, std::deque <int> &l2) {
	std::deque <int> result;
	std::merge(l1.begin(), l1.end(), l2.begin(), l2.end(), std::back_inserter(result));
	return result;
}

std::deque <int> PmergeMe::deq_merge() {
	std::deque <int> result;
	for (size_t i = 0; i < this->_v.size(); ++i) {
		result = deq_merger(result, this->_d[i]);
	}
	return result;
}

void PmergeMe::deq_insertionSort(std::deque<int>& arr) {
	int n = arr.size();
	int i = 0;

	while (i < n) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			std::swap(arr[j - 1], arr[j]);
			--j;
		}
		++i;
	}
}

void PmergeMe::deq_insert() {
	for (size_t i = 0; i < this->_d.size(); ++i) {
		deq_insertionSort(this->_d[i]);
	}
}

void PmergeMe::deque_filler(std::list <int> &result){
	while (!result.empty()) {
		std::deque<int> subDeque;
		for (int i = 0; i < 10 && !result.empty(); ++i) {
			subDeque.push_back(result.front());
			result.pop_front();
		}
		this->_d.push_back(subDeque);
	}
}