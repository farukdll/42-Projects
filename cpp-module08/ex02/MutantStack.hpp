#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <stack>
# include <vector>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){};

        MutantStack(MutantStack const &other) {
            *this = other;
        }

        MutantStack &operator=(MutantStack const &other) {
            (void)other;
            return *this;
        }

        ~MutantStack(){};

        typedef typename std::stack<T>::container_type::iterator iterator;
        
        iterator begin() {
            return std::stack<T>::c.begin();
        }

        iterator end() {
            return std::stack<T>::c.end();
        }
};

#endif
