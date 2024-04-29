#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

int PmergeMe::start(int argc, char **argv) {
	for (int i = 1; i < argc; ++i)
	{
		std::stringstream ss(argv[i]);
		int num;
		if (!(ss >> num) || !ss.eof()) {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		if (num < 0)
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
		this->_vector.push_back(num);
		this->_deque.push_back(num);
	}
	return (0);
}

void PmergeMe::mergeSort(std::vector<int>&left, std::vector<int>& right, std::vector<int>& bars) {
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) 
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL)
	{
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR)
	{
        bars[i] = right[k];
        k++; i++;
    }
}

void PmergeMe::sort(std::vector<int> & bar) {
    if (bar.size() <= 1) return;

    size_t mid = bar.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    sort(left);
    sort(right);
    mergeSort(left, right, bar);
}

void PmergeMe::mergeSort2(std::deque<int>&left, std::deque<int>& right, std::deque<int>& bars) {
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) 
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL)
	{
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR)
	{
        bars[i] = right[k];
        k++; i++;
    }
}

void PmergeMe::sort2(std::deque<int> & bar) {
    if (bar.size() <= 1) return;

    size_t mid = bar.size() / 2;
    std::deque<int> left;
    std::deque<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    sort2(left);
    sort2(right);
    mergeSort2(left, right, bar);
}

void PmergeMe::print_values() {
	std::vector<int>::iterator it;

	it = this->_vector.begin();
	while (it != this->_vector.end())
	{
		std::cout << *it << " "; 
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::process() {
    clock_t v;
    clock_t d;

    std::cout << "Before: ";
    print_values();

    v = clock();
    sort(this->_vector);
    v = clock() - v;

    std::cout << "After: ";
    print_values();

    d = clock();
    sort2(this->_deque);
    d = clock() - d;

    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << static_cast<float>(v) / CLOCKS_PER_SEC * 1000 << " us" << std::endl;
    std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque : " << static_cast<float>(d) / CLOCKS_PER_SEC * 1000 << " us" << std::endl;
}

PmergeMe::~PmergeMe() {}
