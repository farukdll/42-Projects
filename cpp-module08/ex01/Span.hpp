#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int N;
        std::vector<int> v;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end); 
};

#endif
