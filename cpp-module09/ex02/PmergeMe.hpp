#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
	
    public:
		PmergeMe();
		~PmergeMe();
		int start(int argc, char **argv);
		void sort(std::vector<int> & bar);
		void mergeSort(std::vector<int>&left, std::vector<int>& right, std::vector<int>& bars);
		void sort2(std::deque<int> & bar);
		void mergeSort2(std::deque<int>&left, std::deque<int>& right, std::deque<int>& bars);
		void process();
		void print_values();
};

#endif
