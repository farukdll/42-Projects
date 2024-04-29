#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe merge;

	if (argc < 3)
	{
		std::cout << "Error" << std::endl;
		return (0);
	}
	merge.start(argc,argv);
	merge.process();
	return (0);
}
