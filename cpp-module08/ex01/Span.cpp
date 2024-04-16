#include "Span.hpp"

Span::Span() {
    this->N = 0;
    this ->v = std::vector<int>();
}

Span::Span(unsigned int N) {
    this->N = N;
}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
	this->N = other.N;
	this->v = other.v;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (this->v.size() == this->N)
		throw std::runtime_error("Span is already full.");;
    this->v.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while(begin != end)
        addNumber(*begin++);
}

int Span::shortestSpan() {
    if (this->v.size() <= 1)
        throw std::runtime_error("Cannot find span: not enough numbers stored.-1");
    std::sort(v.begin(), v.end());
        int shortest = v[1] - v[0];
        for (size_t i = 2; i < v.size(); ++i) {
            int span = v[i] - v[i - 1];
            if (span < shortest) {
                shortest = span;
            }
        }
        return shortest;
}

int Span::longestSpan() {
    if (this->v.size() <= 1)
        throw std::runtime_error("Cannot find span: not enough numbers stored.-2");
    std::sort(v.begin(), v.end());
        return v.back() - v.front();
}
