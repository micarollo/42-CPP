#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack(void) {}
    MutantStack(MutantStack const &cp) {*this = cp}
    ~MutantStack(void) {}

    MutantStack & operator=( MutantStack const & rhs )
    {
        std::stack<T>::operator=(rhs);
        return (*this);
    }

    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
    iterator begin( void ) {return this->c.begin();}
    iterator end( void ) {return this->c.end();}
};

#endif